"""
spoken_dplyr.py — Spoken English data wrangling with pipe operator

Inspired by R's dplyr + magrittr pipe (%>%). Uses Python's >> operator.

Every verb wraps an exact pandas operation — 1:1 mapping, no magic.

Verbs:
    filter_rows(expr)       → df[df.eval(expr)] / boolean mask filtering
    select_cols(*cols)      → df[list(cols)]
    drop_cols(*cols)        → df.drop(columns=list(cols))
    rename_col(old, new)    → df.rename(columns={old: new})
    mutate(**kwargs)        → df.assign(**kwargs)
    arrange(*cols)          → df.sort_values(list(cols))
    arrange_desc(*cols)     → df.sort_values(list(cols), ascending=False)
    group_by(*cols)         → df.groupby(list(cols))
    summarize(**kwargs)     → groupby.agg(**kwargs)  (use after group_by)
    count(*cols)            → df.value_counts(list(cols)).reset_index()
    distinct(*cols)         → df.drop_duplicates(subset=list(cols))
    slice_rows(start, stop) → df.iloc[start:stop]
    head_rows(n)            → df.head(n)
    tail_rows(n)            → df.tail(n)
    pull(col)               → df[col]  (returns Series)
    relocate(*cols)         → move cols to front
    unite(new, *cols, sep)  → combine cols into one string col
    separate(col, into, sep)→ split col into multiple cols
    pivot_longer(...)       → pd.melt(...)
    pivot_wider(...)        → df.pivot(...)
    left_join(other, on)    → df.merge(other, how='left', on=on)
    right_join(other, on)   → df.merge(other, how='right', on=on)
    inner_join(other, on)   → df.merge(other, how='inner', on=on)
    full_join(other, on)    → df.merge(other, how='outer', on=on)
    anti_join(other, on)    → rows in df not in other
    semi_join(other, on)    → rows in df that are in other
    add_row(**kwargs)       → pd.concat with new row
    ungroup()               → reset groupby back to plain DataFrame

Pipe operator:
    df >> filter_rows("x > 2") >> mutate(z=lambda df: df.x + df.y)

Each verb returns either a DataFrame or a GroupedData wrapper.
Verbs that follow group_by are applied per-group automatically.

Usage:
    import pandas as pd
    from spoken_dplyr import (
        filter_rows, select_cols, mutate, arrange, group_by,
        summarize, count, distinct, head_rows, left_join, pipe
    )

    df = pd.DataFrame({"x": [1,2,3,4,5], "y": [2,4,1,5,3], "g": ["a","b","a","b","a"]})

    result = (df
        >> filter_rows("x > 1")
        >> mutate(z=lambda d: d.x + d.y)
        >> arrange("z")
        >> select_cols("x", "y", "z", "g"))

    # Group and summarize
    summary = (df
        >> group_by("g")
        >> summarize(mean_x=("x", "mean"), total_y=("y", "sum")))

    # Pipe directly into spoken_plotnine
    from spoken_plotnine import plot
    chart = (df
        >> filter_rows("x > 1")
        >> mutate(z=lambda d: d.x + d.y)
        >> plot(x="x", y="z", color="g")  # plot() accepts piped df
        ).points().theme_minimal()
"""

import pandas as pd
import numpy as np
from typing import Callable, Any


# ---------------------------------------------------------------------------
# col() — spoken multi-word column names
#
# Problem: STT produces "miles per gallon" but pandas needs "miles_per_gallon"
# Solution: col("miles per gallon") → "miles_per_gallon"
#
# Usage in verbs:
#   filter_rows(lambda d: d[col("miles per gallon")] > 20)
#   select_cols(col("engine size"), col("fuel type"))
#   plot(df, x=col("miles per gallon"), y=col("horse power"))
#
# Also: cols("miles per gallon", "horse power") → ["miles_per_gallon", "horse_power"]
# ---------------------------------------------------------------------------

def col(spoken: str) -> str:
    """
    Convert a spoken multi-word column name to its snake_case equivalent.

    col("miles per gallon")  →  "miles_per_gallon"
    col("horse power")       →  "horse_power"
    col("x")                 →  "x"   (single words pass through)

    Works as a drop-in for any string column name in spoken_dplyr or spoken_plotnine.
    """
    return spoken.strip().lower().replace(" ", "_").replace("-", "_")


def cols(*spoken_names: str) -> list:
    """
    Convert multiple spoken column names to snake_case.

    cols("miles per gallon", "horse power")  →  ["miles_per_gallon", "horse_power"]
    """
    return [col(name) for name in spoken_names]


def rename_cols_spoken(df: pd.DataFrame) -> pd.DataFrame:
    """
    Rename all DataFrame columns to snake_case so spoken names work naturally.

    rename_cols_spoken(df)  — converts "Miles Per Gallon" → "miles_per_gallon"

    Use once after loading data, then col() names will match.
    """
    return df.rename(columns={c: col(c) for c in df.columns})


# ---------------------------------------------------------------------------
# Grouped data wrapper
# ---------------------------------------------------------------------------

class GroupedData:
    """Wraps a pandas GroupBy so verbs can be applied to grouped data."""

    def __init__(self, df: pd.DataFrame, by: list):
        self._df = df
        self._by = by
        self._gb = df.groupby(by)

    # support >> on grouped data
    def __rrshift__(self, left):
        # left >> GroupedData means re-group left
        if isinstance(left, pd.DataFrame):
            return GroupedData(left, self._by)
        raise TypeError(f"Cannot pipe {type(left)} into GroupedData")

    def __rshift__(self, verb):
        return verb(self)

    def agg(self, **kwargs):
        return self._gb.agg(**kwargs).reset_index()

    @property
    def groupby(self):
        return self._gb

    @property
    def df(self):
        return self._df

    @property
    def by(self):
        return self._by


# ---------------------------------------------------------------------------
# Base verb class
# ---------------------------------------------------------------------------

class Verb:
    """A deferred operation on a DataFrame (or GroupedData)."""

    def __call__(self, data):
        raise NotImplementedError

    def __rrshift__(self, left):
        """df >> verb"""
        return self(left)

    def __rshift__(self, right):
        """verb >> verb — compose into a pipeline"""
        return Pipeline(self, right)


class Pipeline(Verb):
    def __init__(self, *verbs):
        self._verbs = list(verbs)

    def __call__(self, data):
        result = data
        for v in self._verbs:
            result = v(result)
        return result

    def __rshift__(self, right):
        return Pipeline(*self._verbs, right)


# ---------------------------------------------------------------------------
# Helper: unwrap GroupedData to DataFrame when needed
# ---------------------------------------------------------------------------

def _df(data):
    if isinstance(data, GroupedData):
        return data.df
    return data


# ---------------------------------------------------------------------------
# Verbs
# ---------------------------------------------------------------------------

class filter_rows(Verb):
    """
    filter_rows("x > 2")               — string expression (df.query)
    filter_rows(lambda df: df.x > 2)   — callable returning bool mask
    filter_rows(df.x > 2)              — boolean Series (pre-computed)

    Equivalent to dplyr::filter()
    """
    def __init__(self, expr):
        self._expr = expr

    def __call__(self, data):
        df = _df(data)
        if callable(self._expr):
            mask = self._expr(df)
        elif isinstance(self._expr, pd.Series):
            mask = self._expr
        else:
            mask = df.eval(self._expr)
        result = df[mask].reset_index(drop=True)
        if isinstance(data, GroupedData):
            return GroupedData(result, data.by)
        return result


class select_cols(Verb):
    """
    select_cols("x", "y", "g")  →  df[["x", "y", "g"]]

    Equivalent to dplyr::select()
    """
    def __init__(self, *cols):
        self._cols = list(cols)

    def __call__(self, data):
        df = _df(data)
        return df[self._cols]


class drop_cols(Verb):
    """
    drop_cols("x", "y")  →  df.drop(columns=["x", "y"])

    Equivalent to dplyr::select(-x, -y)
    """
    def __init__(self, *cols):
        self._cols = list(cols)

    def __call__(self, data):
        df = _df(data)
        return df.drop(columns=self._cols)


class rename_col(Verb):
    """
    rename_col("old_name", "new_name")  →  df.rename(columns={"old_name": "new_name"})

    Equivalent to dplyr::rename()
    """
    def __init__(self, old: str, new: str):
        self._old = old
        self._new = new

    def __call__(self, data):
        df = _df(data)
        result = df.rename(columns={self._old: self._new})
        if isinstance(data, GroupedData):
            new_by = [self._new if c == self._old else c for c in data.by]
            return GroupedData(result, new_by)
        return result


class mutate(Verb):
    """
    mutate(z=lambda df: df.x + df.y)   — callable per-column
    mutate(z=df.x + df.y)              — pre-computed Series
    mutate(label="fixed_value")        — scalar

    Equivalent to dplyr::mutate()
    """
    def __init__(self, **kwargs):
        self._kwargs = kwargs

    def __call__(self, data):
        df = _df(data)
        result = df.assign(**self._kwargs)
        if isinstance(data, GroupedData):
            return GroupedData(result, data.by)
        return result


class arrange(Verb):
    """
    arrange("x")            — sort ascending by x
    arrange("x", "y")       — sort ascending by x then y
    arrange("-x")           — sort descending by x (prefix with -)

    Equivalent to dplyr::arrange()
    """
    def __init__(self, *cols):
        self._cols_raw = list(cols)

    def __call__(self, data):
        df = _df(data)
        cols = [c.lstrip("-") for c in self._cols_raw]
        ascending = [not c.startswith("-") for c in self._cols_raw]
        result = df.sort_values(cols, ascending=ascending).reset_index(drop=True)
        if isinstance(data, GroupedData):
            return GroupedData(result, data.by)
        return result


class arrange_desc(Verb):
    """
    arrange_desc("x")  — sort descending by x

    Equivalent to dplyr::arrange(desc(x))
    """
    def __init__(self, *cols):
        self._cols = list(cols)

    def __call__(self, data):
        df = _df(data)
        result = df.sort_values(self._cols, ascending=False).reset_index(drop=True)
        if isinstance(data, GroupedData):
            return GroupedData(result, data.by)
        return result


class group_by(Verb):
    """
    group_by("g")           — group by one column
    group_by("g", "h")      — group by multiple columns

    Equivalent to dplyr::group_by()
    Returns GroupedData — subsequent verbs operate per-group.
    """
    def __init__(self, *cols):
        self._cols = list(cols)

    def __call__(self, data):
        df = _df(data)
        return GroupedData(df, self._cols)


class ungroup(Verb):
    """
    ungroup()  — drop grouping, return plain DataFrame

    Equivalent to dplyr::ungroup()
    """
    def __call__(self, data):
        return _df(data)


class summarize(Verb):
    """
    summarize(mean_x=("x", "mean"), total_y=("y", "sum"))
    summarize(n=("x", "count"))

    Must follow group_by(). Equivalent to dplyr::summarise()
    Uses pandas named aggregation syntax: col=(source_col, agg_func)
    """
    def __init__(self, **kwargs):
        self._kwargs = kwargs

    def __call__(self, data):
        if isinstance(data, GroupedData):
            return data.groupby.agg(**self._kwargs).reset_index()
        # No grouping — aggregate whole frame
        df = _df(data)
        row = {}
        for name, (col, func) in self._kwargs.items():
            row[name] = getattr(df[col], func)() if isinstance(func, str) else func(df[col])
        return pd.DataFrame([row])


class count(Verb):
    """
    count("g")          — count rows per group
    count("g", "h")     — count rows per group combo
    count()             — total row count

    Equivalent to dplyr::count()
    """
    def __init__(self, *cols, sort=True):
        self._cols = list(cols)
        self._sort = sort

    def __call__(self, data):
        df = _df(data)
        if self._cols:
            result = df.groupby(self._cols).size().reset_index(name="n")
            if self._sort:
                result = result.sort_values("n", ascending=False).reset_index(drop=True)
        else:
            result = pd.DataFrame({"n": [len(df)]})
        return result


class distinct(Verb):
    """
    distinct()              — unique rows across all columns
    distinct("x", "y")      — unique combinations of x and y

    Equivalent to dplyr::distinct()
    """
    def __init__(self, *cols):
        self._cols = list(cols) if cols else None

    def __call__(self, data):
        df = _df(data)
        return df.drop_duplicates(subset=self._cols).reset_index(drop=True)


class slice_rows(Verb):
    """
    slice_rows(0, 5)   → df.iloc[0:5]

    Equivalent to dplyr::slice()
    """
    def __init__(self, start: int, stop: int):
        self._start = start
        self._stop = stop

    def __call__(self, data):
        return _df(data).iloc[self._start:self._stop].reset_index(drop=True)


class head_rows(Verb):
    """
    head_rows(5)  → df.head(5)

    Equivalent to dplyr::slice_head(n=5)
    """
    def __init__(self, n: int = 6):
        self._n = n

    def __call__(self, data):
        return _df(data).head(self._n).reset_index(drop=True)


class tail_rows(Verb):
    """
    tail_rows(5)  → df.tail(5)

    Equivalent to dplyr::slice_tail(n=5)
    """
    def __init__(self, n: int = 6):
        self._n = n

    def __call__(self, data):
        return _df(data).tail(self._n).reset_index(drop=True)


class pull(Verb):
    """
    pull("x")  → df["x"]  (returns a Series)

    Equivalent to dplyr::pull()
    """
    def __init__(self, col: str):
        self._col = col

    def __call__(self, data):
        return _df(data)[self._col]


class relocate(Verb):
    """
    relocate("z", "g")  — move z and g to the front

    Equivalent to dplyr::relocate()
    """
    def __init__(self, *cols):
        self._cols = list(cols)

    def __call__(self, data):
        df = _df(data)
        rest = [c for c in df.columns if c not in self._cols]
        return df[self._cols + rest]


class unite(Verb):
    """
    unite("full_name", "first", "last", sep=" ")
    → df.assign(full_name=df.first + " " + df.last).drop(columns=["first","last"])

    Equivalent to tidyr::unite()
    """
    def __init__(self, new_col: str, *cols, sep: str = "_", remove: bool = True):
        self._new_col = new_col
        self._cols = list(cols)
        self._sep = sep
        self._remove = remove

    def __call__(self, data):
        df = _df(data)
        result = df.assign(**{
            self._new_col: df[self._cols].astype(str).agg(self._sep.join, axis=1)
        })
        if self._remove:
            result = result.drop(columns=self._cols)
        return result


class separate(Verb):
    """
    separate("name", into=["first","last"], sep=" ")
    → splits column into multiple columns

    Equivalent to tidyr::separate()
    """
    def __init__(self, col: str, into: list, sep: str = "_", remove: bool = True):
        self._col = col
        self._into = into
        self._sep = sep
        self._remove = remove

    def __call__(self, data):
        df = _df(data)
        split = df[self._col].str.split(self._sep, expand=True)
        split.columns = self._into[: len(split.columns)]
        result = pd.concat([df, split], axis=1)
        if self._remove:
            result = result.drop(columns=[self._col])
        return result.reset_index(drop=True)


class pivot_longer(Verb):
    """
    pivot_longer(cols=["a","b","c"], names_to="variable", values_to="value")
    → pd.melt(df, id_vars=[...], value_vars=cols, var_name=names_to, value_name=values_to)

    Equivalent to tidyr::pivot_longer()
    """
    def __init__(self, cols: list, names_to: str = "name", values_to: str = "value"):
        self._cols = cols
        self._names_to = names_to
        self._values_to = values_to

    def __call__(self, data):
        df = _df(data)
        id_vars = [c for c in df.columns if c not in self._cols]
        return pd.melt(
            df,
            id_vars=id_vars,
            value_vars=self._cols,
            var_name=self._names_to,
            value_name=self._values_to,
        ).reset_index(drop=True)


class pivot_wider(Verb):
    """
    pivot_wider(index="id", names_from="variable", values_from="value")
    → df.pivot(index=index, columns=names_from, values=values_from)

    Equivalent to tidyr::pivot_wider()
    """
    def __init__(self, index: str, names_from: str, values_from: str):
        self._index = index
        self._names_from = names_from
        self._values_from = values_from

    def __call__(self, data):
        df = _df(data)
        return (
            df.pivot(index=self._index, columns=self._names_from, values=self._values_from)
            .reset_index()
            .rename_axis(None, axis=1)
        )


# ---------------------------------------------------------------------------
# Joins
# ---------------------------------------------------------------------------

class left_join(Verb):
    """
    left_join(other_df, on="key")
    left_join(other_df, on=["k1", "k2"])

    Equivalent to dplyr::left_join()
    """
    def __init__(self, other: pd.DataFrame, on):
        self._other = other
        self._on = on

    def __call__(self, data):
        return _df(data).merge(self._other, how="left", on=self._on)


class right_join(Verb):
    """right_join() — dplyr::right_join()"""
    def __init__(self, other: pd.DataFrame, on):
        self._other = other
        self._on = on

    def __call__(self, data):
        return _df(data).merge(self._other, how="right", on=self._on)


class inner_join(Verb):
    """inner_join() — dplyr::inner_join()"""
    def __init__(self, other: pd.DataFrame, on):
        self._other = other
        self._on = on

    def __call__(self, data):
        return _df(data).merge(self._other, how="inner", on=self._on)


class full_join(Verb):
    """full_join() — dplyr::full_join()"""
    def __init__(self, other: pd.DataFrame, on):
        self._other = other
        self._on = on

    def __call__(self, data):
        return _df(data).merge(self._other, how="outer", on=self._on)


class anti_join(Verb):
    """
    anti_join(other, on="key")
    Rows in df that do NOT appear in other. dplyr::anti_join()
    """
    def __init__(self, other: pd.DataFrame, on):
        self._other = other
        self._on = on

    def __call__(self, data):
        df = _df(data)
        on = [self._on] if isinstance(self._on, str) else self._on
        merged = df.merge(self._other[on].drop_duplicates(), on=on, how="left", indicator=True)
        return merged[merged["_merge"] == "left_only"].drop(columns=["_merge"]).reset_index(drop=True)


class semi_join(Verb):
    """
    semi_join(other, on="key")
    Rows in df that DO appear in other (no extra columns from other). dplyr::semi_join()
    """
    def __init__(self, other: pd.DataFrame, on):
        self._other = other
        self._on = on

    def __call__(self, data):
        df = _df(data)
        on = [self._on] if isinstance(self._on, str) else self._on
        keys = self._other[on].drop_duplicates()
        return df.merge(keys, on=on, how="inner").reset_index(drop=True)


# ---------------------------------------------------------------------------
# Utility: pipe() function for explicit piping without >>
# ---------------------------------------------------------------------------

def pipe(data, *verbs):
    """
    pipe(df, filter_rows("x > 1"), mutate(z=lambda d: d.x+d.y), arrange("z"))

    Alternative to >> when spoken syntax is preferred.
    """
    result = data
    for v in verbs:
        result = v(result)
    return result


# ---------------------------------------------------------------------------
# Patch DataFrame to support >> directly
# ---------------------------------------------------------------------------

def _df_rshift(self, verb):
    """Enable df >> verb syntax on DataFrames."""
    if callable(verb):
        return verb(self)
    raise TypeError(f"Cannot pipe DataFrame into {type(verb)}")


# Monkey-patch pandas DataFrame with >> support
pd.DataFrame.__rshift__ = _df_rshift
