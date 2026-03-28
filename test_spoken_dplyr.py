"""
test_spoken_dplyr.py — 1-to-1 equivalence tests for spoken_dplyr

Each test verifies: spoken_dplyr verb produces identical DataFrame to
the equivalent raw pandas operation.

Run: source .venv/bin/activate && python test_spoken_dplyr.py
"""

import sys
import traceback
import pandas as pd
import numpy as np
from spoken_dplyr import (
    filter_rows, select_cols, drop_cols, rename_col,
    mutate, arrange, arrange_desc, group_by, ungroup,
    summarize, count, distinct, slice_rows, head_rows, tail_rows,
    pull, relocate, unite, separate,
    pivot_longer, pivot_wider,
    left_join, right_join, inner_join, full_join, anti_join, semi_join,
    pipe, GroupedData,
    col, cols, rename_cols_spoken,
)

# ---------------------------------------------------------------------------
# Harness
# ---------------------------------------------------------------------------

passed = 0
failed = 0
errors = []


def check(name, spoken_result, expected_result):
    global passed, failed
    try:
        if isinstance(spoken_result, pd.DataFrame) and isinstance(expected_result, pd.DataFrame):
            # Reset index for comparison
            a = spoken_result.reset_index(drop=True)
            b = expected_result.reset_index(drop=True)
            pd.testing.assert_frame_equal(a, b, check_like=False)
        elif isinstance(spoken_result, pd.Series) and isinstance(expected_result, pd.Series):
            pd.testing.assert_series_equal(
                spoken_result.reset_index(drop=True),
                expected_result.reset_index(drop=True),
            )
        elif isinstance(spoken_result, GroupedData):
            assert spoken_result.by == expected_result.by, (
                f"GroupedData by: {spoken_result.by} != {expected_result.by}"
            )
            pd.testing.assert_frame_equal(
                spoken_result.df.reset_index(drop=True),
                expected_result.df.reset_index(drop=True),
            )
        else:
            assert spoken_result == expected_result, f"{spoken_result!r} != {expected_result!r}"
        passed += 1
        print(f"  PASS  {name}")
    except AssertionError as e:
        failed += 1
        errors.append((name, str(e)))
        print(f"  FAIL  {name}: {e}")
    except Exception as e:
        failed += 1
        errors.append((name, traceback.format_exc()))
        print(f"  ERR   {name}: {e}")


# ---------------------------------------------------------------------------
# Data
# ---------------------------------------------------------------------------

df = pd.DataFrame({
    "x": [1, 2, 3, 4, 5],
    "y": [2, 4, 1, 5, 3],
    "g": ["a", "b", "a", "b", "a"],
    "h": ["p", "p", "q", "q", "p"],
    "val": [10.0, 20.0, 15.0, 25.0, 12.0],
})

df2 = pd.DataFrame({
    "g": ["a", "b", "c"],
    "label": ["alpha", "beta", "gamma"],
})

# ---------------------------------------------------------------------------
# Section 1: filter_rows
# ---------------------------------------------------------------------------

print("\n── filter_rows ──────────────────────────────────────────────────")

check("filter string expr",
    df >> filter_rows("x > 2"),
    df[df.eval("x > 2")].reset_index(drop=True))

check("filter lambda",
    df >> filter_rows(lambda d: d.x > 2),
    df[df.x > 2].reset_index(drop=True))

check("filter boolean Series",
    df >> filter_rows(df.g == "a"),
    df[df.g == "a"].reset_index(drop=True))

check("filter compound",
    df >> filter_rows("x > 1 and g == 'a'"),
    df[df.eval("x > 1 and g == 'a'")].reset_index(drop=True))

# ---------------------------------------------------------------------------
# Section 2: select_cols / drop_cols
# ---------------------------------------------------------------------------

print("\n── select_cols / drop_cols ──────────────────────────────────────")

check("select two cols",
    df >> select_cols("x", "y"),
    df[["x", "y"]])

check("select one col",
    df >> select_cols("g"),
    df[["g"]])

check("drop cols",
    df >> drop_cols("h", "val"),
    df.drop(columns=["h", "val"]))

# ---------------------------------------------------------------------------
# Section 3: rename_col
# ---------------------------------------------------------------------------

print("\n── rename_col ───────────────────────────────────────────────────")

check("rename x to value",
    df >> rename_col("x", "value"),
    df.rename(columns={"x": "value"}))

# ---------------------------------------------------------------------------
# Section 4: mutate
# ---------------------------------------------------------------------------

print("\n── mutate ───────────────────────────────────────────────────────")

check("mutate lambda",
    df >> mutate(z=lambda d: d.x + d.y),
    df.assign(z=df.x + df.y))

check("mutate scalar",
    df >> mutate(const=99),
    df.assign(const=99))

check("mutate multiple",
    df >> mutate(z=lambda d: d.x + d.y, w=lambda d: d.x * 2),
    df.assign(z=df.x + df.y, w=df.x * 2))

# ---------------------------------------------------------------------------
# Section 5: arrange
# ---------------------------------------------------------------------------

print("\n── arrange ──────────────────────────────────────────────────────")

check("arrange asc",
    df >> arrange("y"),
    df.sort_values("y").reset_index(drop=True))

check("arrange desc with -",
    df >> arrange("-x"),
    df.sort_values("x", ascending=False).reset_index(drop=True))

check("arrange_desc",
    df >> arrange_desc("val"),
    df.sort_values("val", ascending=False).reset_index(drop=True))

check("arrange multi-col",
    df >> arrange("g", "x"),
    df.sort_values(["g", "x"]).reset_index(drop=True))

# ---------------------------------------------------------------------------
# Section 6: group_by / ungroup
# ---------------------------------------------------------------------------

print("\n── group_by / ungroup ───────────────────────────────────────────")

check("group_by returns GroupedData",
    df >> group_by("g"),
    GroupedData(df, ["g"]))

check("group_by multi-col",
    df >> group_by("g", "h"),
    GroupedData(df, ["g", "h"]))

check("ungroup returns DataFrame",
    df >> group_by("g") >> ungroup(),
    df)

# ---------------------------------------------------------------------------
# Section 7: summarize
# ---------------------------------------------------------------------------

print("\n── summarize ────────────────────────────────────────────────────")

check("group_by + summarize mean",
    df >> group_by("g") >> summarize(mean_x=("x", "mean")),
    df.groupby("g").agg(mean_x=("x", "mean")).reset_index())

check("group_by + summarize multi",
    df >> group_by("g") >> summarize(mean_x=("x", "mean"), total_y=("y", "sum")),
    df.groupby("g").agg(mean_x=("x", "mean"), total_y=("y", "sum")).reset_index())

check("group_by multi + summarize",
    df >> group_by("g", "h") >> summarize(n=("x", "count")),
    df.groupby(["g", "h"]).agg(n=("x", "count")).reset_index())

# ---------------------------------------------------------------------------
# Section 8: count
# ---------------------------------------------------------------------------

print("\n── count ────────────────────────────────────────────────────────")

check("count by group",
    df >> count("g"),
    df.groupby("g").size().reset_index(name="n").sort_values("n", ascending=False).reset_index(drop=True))

check("count multi-group",
    df >> count("g", "h"),
    df.groupby(["g", "h"]).size().reset_index(name="n").sort_values("n", ascending=False).reset_index(drop=True))

# ---------------------------------------------------------------------------
# Section 9: distinct
# ---------------------------------------------------------------------------

print("\n── distinct ─────────────────────────────────────────────────────")

check("distinct all cols",
    df >> distinct(),
    df.drop_duplicates().reset_index(drop=True))

check("distinct by col",
    df >> distinct("g"),
    df.drop_duplicates(subset=["g"]).reset_index(drop=True))

# ---------------------------------------------------------------------------
# Section 10: slice / head / tail
# ---------------------------------------------------------------------------

print("\n── slice / head / tail ──────────────────────────────────────────")

check("slice_rows 0:3",
    df >> slice_rows(0, 3),
    df.iloc[0:3].reset_index(drop=True))

check("head_rows 3",
    df >> head_rows(3),
    df.head(3).reset_index(drop=True))

check("tail_rows 2",
    df >> tail_rows(2),
    df.tail(2).reset_index(drop=True))

# ---------------------------------------------------------------------------
# Section 11: pull
# ---------------------------------------------------------------------------

print("\n── pull ─────────────────────────────────────────────────────────")

check("pull column as Series",
    df >> pull("x"),
    df["x"])

# ---------------------------------------------------------------------------
# Section 12: relocate
# ---------------------------------------------------------------------------

print("\n── relocate ─────────────────────────────────────────────────────")

check("relocate g to front",
    df >> relocate("g"),
    df[["g", "x", "y", "h", "val"]])

check("relocate two cols to front",
    df >> relocate("val", "g"),
    df[["val", "g", "x", "y", "h"]])

# ---------------------------------------------------------------------------
# Section 13: unite / separate
# ---------------------------------------------------------------------------

print("\n── unite / separate ─────────────────────────────────────────────")

check("unite two cols",
    df >> unite("gh", "g", "h", sep="-"),
    df.assign(gh=df.g.astype(str) + "-" + df.h.astype(str)).drop(columns=["g", "h"]))

check("separate col",
    (df >> unite("gh", "g", "h", sep="-") >> separate("gh", into=["g2", "h2"], sep="-")),
    (df.assign(gh=df.g.astype(str) + "-" + df.h.astype(str))
       .drop(columns=["g", "h"])
       .assign(g2=df.g.values, h2=df.h.values)
       .drop(columns=["gh"])
       .reset_index(drop=True)))

# ---------------------------------------------------------------------------
# Section 14: pivot_longer / pivot_wider
# ---------------------------------------------------------------------------

print("\n── pivot_longer / pivot_wider ───────────────────────────────────")

wide_df = pd.DataFrame({"id": [1, 2], "a": [10, 20], "b": [30, 40]})

check("pivot_longer",
    wide_df >> pivot_longer(cols=["a", "b"], names_to="variable", values_to="value"),
    pd.melt(wide_df, id_vars=["id"], value_vars=["a", "b"],
            var_name="variable", value_name="value").reset_index(drop=True))

long_df = pd.melt(wide_df, id_vars=["id"], value_vars=["a", "b"],
                  var_name="variable", value_name="value")

check("pivot_wider",
    long_df >> pivot_wider(index="id", names_from="variable", values_from="value"),
    long_df.pivot(index="id", columns="variable", values="value")
           .reset_index().rename_axis(None, axis=1))

# ---------------------------------------------------------------------------
# Section 15: joins
# ---------------------------------------------------------------------------

print("\n── joins ────────────────────────────────────────────────────────")

check("left_join",
    df >> left_join(df2, on="g"),
    df.merge(df2, how="left", on="g"))

check("right_join",
    df >> right_join(df2, on="g"),
    df.merge(df2, how="right", on="g"))

check("inner_join",
    df >> inner_join(df2, on="g"),
    df.merge(df2, how="inner", on="g"))

check("full_join",
    df >> full_join(df2, on="g"),
    df.merge(df2, how="outer", on="g"))

check("anti_join",
    df >> anti_join(df2[df2.g.isin(["b", "c"])], on="g"),
    df[~df.g.isin(["b", "c"])].reset_index(drop=True))

check("semi_join",
    df >> semi_join(df2[df2.g == "a"], on="g"),
    df[df.g == "a"].reset_index(drop=True))

# ---------------------------------------------------------------------------
# Section 16: pipe() function (explicit)
# ---------------------------------------------------------------------------

print("\n── pipe() function ──────────────────────────────────────────────")

check("pipe() explicit",
    pipe(df, filter_rows("x > 2"), select_cols("x", "y", "g"), arrange("x")),
    df[df.eval("x > 2")][["x", "y", "g"]].sort_values("x").reset_index(drop=True))

# ---------------------------------------------------------------------------
# Section 17: chained pipelines
# ---------------------------------------------------------------------------

print("\n── chained pipelines ────────────────────────────────────────────")

check("filter + mutate + arrange",
    df >> filter_rows("x > 1") >> mutate(z=lambda d: d.x + d.y) >> arrange("z"),
    (df[df.x > 1]
       .assign(z=lambda d: d.x + d.y)
       .sort_values("z")
       .reset_index(drop=True)))

check("group_by + filter + summarize",
    df >> group_by("g") >> filter_rows("x > 1") >> summarize(mean_val=("val", "mean")),
    (df[df.x > 1]
       .groupby("g")
       .agg(mean_val=("val", "mean"))
       .reset_index()))

check("select + rename + arrange",
    df >> select_cols("x", "g") >> rename_col("x", "value") >> arrange_desc("value"),
    (df[["x", "g"]]
       .rename(columns={"x": "value"})
       .sort_values("value", ascending=False)
       .reset_index(drop=True)))

check("count after filter",
    df >> filter_rows("val > 12") >> count("g"),
    (df[df.val > 12]
       .groupby("g").size()
       .reset_index(name="n")
       .sort_values("n", ascending=False)
       .reset_index(drop=True)))

# ---------------------------------------------------------------------------
# Section 18: col() — spoken multi-word column names
# ---------------------------------------------------------------------------

print("\n── col() / cols() / rename_cols_spoken() ────────────────────────")

def check_val(name, a, b):
    global passed, failed
    try:
        assert a == b, f"{a!r} != {b!r}"
        passed += 1
        print(f"  PASS  {name}")
    except AssertionError as e:
        failed += 1
        errors.append((name, str(e)))
        print(f"  FAIL  {name}: {e}")

check_val("col single word",      col("x"),                    "x")
check_val("col two words",        col("horse power"),          "horse_power")
check_val("col three words",      col("miles per gallon"),     "miles_per_gallon")
check_val("col already snake",    col("already_snake"),        "already_snake")
check_val("col uppercase",        col("Miles Per Gallon"),     "miles_per_gallon")
check_val("col hyphen",           col("two-word"),             "two_word")
check_val("cols multi",           cols("horse power", "mpg"),  ["horse_power", "mpg"])

# rename_cols_spoken — DataFrame column renaming
messy = pd.DataFrame({"Miles Per Gallon": [20, 25], "Horse Power": [100, 200]})
cleaned = rename_cols_spoken(messy)
check("rename_cols_spoken",
    cleaned,
    pd.DataFrame({"miles_per_gallon": [20, 25], "horse_power": [100, 200]}))

# col() used inside verbs
df_spoken = pd.DataFrame({"horse power": [100, 200, 150], "mpg": [20, 15, 25], "type": ["a","b","a"]})
df_snake = rename_cols_spoken(df_spoken)

check("col in filter_rows",
    df_snake >> filter_rows(lambda d: d[col("horse power")] > 120),
    df_snake[df_snake["horse_power"] > 120].reset_index(drop=True))

check("col in select_cols",
    df_snake >> select_cols(*cols("horse power", "mpg")),
    df_snake[["horse_power", "mpg"]])

# ---------------------------------------------------------------------------
# Summary
# ---------------------------------------------------------------------------

total = passed + failed
print(f"\n{'═'*60}")
print(f"  {passed} passed, {failed} failed  (total {total})")
if errors:
    print("\nFailures:")
    for name, msg in errors:
        print(f"  ✗ {name}")
        for line in msg.strip().split("\n"):
            print(f"      {line}")
print()
sys.exit(0 if failed == 0 else 1)
