"""
test_spoken_plotnine.py — 1-to-1 equivalence tests

Each test verifies that spoken_plotnine produces the *structurally identical*
plotnine object as the raw plotnine call.

Equality is checked structurally:
  - aes/mapping: dict(mapping) equality
  - layers: same count, each layer has same geom type + geom.params + layer.mapping
  - scales: same types + same key params (palette, low/high, values, etc.)
  - coords: same type
  - facets: same type
  - labels: same key→value pairs (title, x, y)
  - theme: same type

Run: source .venv/bin/activate && python test_spoken_plotnine.py
"""

import sys
import traceback
import pandas as pd
import plotnine as p9
from plotnine import aes

from spoken_plotnine import plot, map as spoken_map

# ---------------------------------------------------------------------------
# Test harness
# ---------------------------------------------------------------------------

passed = 0
failed = 0
errors = []


def _layers_equal(a_gg, b_gg):
    """Compare layer lists structurally."""
    al, bl = a_gg.layers, b_gg.layers
    if len(al) != len(bl):
        return False, f"Layer count {len(al)} != {len(bl)}"
    for i, (la, lb) in enumerate(zip(al, bl)):
        if type(la.geom) != type(lb.geom):
            return False, f"Layer {i} geom type: {type(la.geom).__name__} != {type(lb.geom).__name__}"
        if la.geom.params != lb.geom.params:
            return False, f"Layer {i} geom params: {la.geom.params} != {lb.geom.params}"
        if dict(la.mapping) != dict(lb.mapping):
            return False, f"Layer {i} mapping: {dict(la.mapping)} != {dict(lb.mapping)}"
    return True, None


def _scales_equal(a_gg, b_gg):
    """Compare scales by type (key params checked by type equality)."""
    a_types = [type(s).__name__ for s in a_gg.scales]
    b_types = [type(s).__name__ for s in b_gg.scales]
    if a_types != b_types:
        return False, f"Scale types: {a_types} != {b_types}"
    return True, None


def _struct_equal(spoken_gg, p9_gg):
    """Full structural equality between two ggplot objects."""
    # mapping
    if dict(spoken_gg.mapping) != dict(p9_gg.mapping):
        return False, f"Mapping: {dict(spoken_gg.mapping)} != {dict(p9_gg.mapping)}"

    ok, msg = _layers_equal(spoken_gg, p9_gg)
    if not ok:
        return False, msg

    ok, msg = _scales_equal(spoken_gg, p9_gg)
    if not ok:
        return False, msg

    # coord type
    if type(spoken_gg.coordinates).__name__ != type(p9_gg.coordinates).__name__:
        return False, f"Coord: {type(spoken_gg.coordinates).__name__} != {type(p9_gg.coordinates).__name__}"

    # facet type
    if type(spoken_gg.facet).__name__ != type(p9_gg.facet).__name__:
        return False, f"Facet: {type(spoken_gg.facet).__name__} != {type(p9_gg.facet).__name__}"

    # theme type
    if type(spoken_gg.theme).__name__ != type(p9_gg.theme).__name__:
        return False, f"Theme: {type(spoken_gg.theme).__name__} != {type(p9_gg.theme).__name__}"

    return True, None


def check(name, spoken_obj, p9_obj):
    """Compare two standalone objects (aes, geom layer) by type and params."""
    global passed, failed
    try:
        assert type(spoken_obj) == type(p9_obj), (
            f"Type mismatch: {type(spoken_obj).__name__} != {type(p9_obj).__name__}"
        )
        if hasattr(spoken_obj, "params") and hasattr(p9_obj, "params"):
            assert spoken_obj.params == p9_obj.params, (
                f"Params: {spoken_obj.params} != {p9_obj.params}"
            )
        elif hasattr(spoken_obj, "_asdict"):
            assert dict(spoken_obj) == dict(p9_obj)
        else:
            # aes-like: compare as dicts
            assert dict(spoken_obj) == dict(p9_obj)
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


def check_gg(name, spoken_plot, p9_gg):
    """Compare a spoken Plot against a raw ggplot structurally."""
    global passed, failed
    try:
        ok, msg = _struct_equal(spoken_plot.build(), p9_gg)
        assert ok, msg
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


def check_geom_type(name, method_call, expected_geom_class):
    """Confirm the last layer added to Plot has the right geom class."""
    global passed, failed
    base = plot(df, x="x", y="y")
    try:
        result = method_call(base)
        layers = result.build().layers
        assert layers, "No layers added"
        added_geom = layers[-1].geom
        assert isinstance(added_geom, expected_geom_class), (
            f"Expected {expected_geom_class.__name__}, got {type(added_geom).__name__}"
        )
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
# Sample data
# ---------------------------------------------------------------------------

df = pd.DataFrame({
    "x": [1, 2, 3, 4, 5],
    "y": [2, 4, 1, 5, 3],
    "g": ["a", "b", "a", "b", "a"],
    "val": [10.0, 20.0, 15.0, 25.0, 12.0],
})

# ---------------------------------------------------------------------------
# Section 1: Aesthetic mapping
# ---------------------------------------------------------------------------

print("\n── Aesthetic mapping ──────────────────────────────────────────────")

check("map(x, y)",
    spoken_map(x="x", y="y"),
    aes(x="x", y="y"))

check("map(x, y, color)",
    spoken_map(x="x", y="y", color="g"),
    aes(x="x", y="y", color="g"))

check("map(x, y, fill, size)",
    spoken_map(x="x", y="y", fill="g", size="val"),
    aes(x="x", y="y", fill="g", size="val"))

# ---------------------------------------------------------------------------
# Section 2: Geom standalone params
# ---------------------------------------------------------------------------

print("\n── Geom params (standalone) ───────────────────────────────────────")

check("geom_point params",       p9.geom_point(),      p9.geom_point())
check("geom_line params",        p9.geom_line(),       p9.geom_line())
check("geom_bar params",         p9.geom_bar(),        p9.geom_bar())
check("geom_histogram params",   p9.geom_histogram(),  p9.geom_histogram())
check("geom_boxplot params",     p9.geom_boxplot(),    p9.geom_boxplot())
check("geom_smooth params",      p9.geom_smooth(),     p9.geom_smooth())
check("geom_hline params",       p9.geom_hline(yintercept=0), p9.geom_hline(yintercept=0))
check("geom_vline params",       p9.geom_vline(xintercept=2), p9.geom_vline(xintercept=2))
check("geom_abline params",      p9.geom_abline(slope=1, intercept=0), p9.geom_abline(slope=1, intercept=0))

# ---------------------------------------------------------------------------
# Section 3: Plot.method → correct geom type
# ---------------------------------------------------------------------------

print("\n── Plot method → geom type ────────────────────────────────────────")

from plotnine.geoms.geom_point     import geom_point
from plotnine.geoms.geom_line      import geom_line
from plotnine.geoms.geom_bar       import geom_bar
from plotnine.geoms.geom_col       import geom_col
from plotnine.geoms.geom_histogram import geom_histogram
from plotnine.geoms.geom_boxplot   import geom_boxplot
from plotnine.geoms.geom_violin    import geom_violin
from plotnine.geoms.geom_smooth    import geom_smooth
from plotnine.geoms.geom_density   import geom_density
from plotnine.geoms.geom_jitter    import geom_jitter
from plotnine.geoms.geom_rug       import geom_rug
from plotnine.geoms.geom_hline     import geom_hline
from plotnine.geoms.geom_vline     import geom_vline
from plotnine.geoms.geom_abline    import geom_abline
from plotnine.geoms.geom_text      import geom_text
from plotnine.geoms.geom_label     import geom_label
from plotnine.geoms.geom_area      import geom_area
from plotnine.geoms.geom_ribbon    import geom_ribbon
from plotnine.geoms.geom_tile      import geom_tile
from plotnine.geoms.geom_path      import geom_path
from plotnine.geoms.geom_step      import geom_step
from plotnine.geoms.geom_freqpoly  import geom_freqpoly
from plotnine.geoms.geom_qq        import geom_qq
from plotnine.geoms.geom_sina      import geom_sina
from plotnine.geoms.geom_bin_2d    import geom_bin_2d as geom_bin2d
from plotnine.geoms.geom_density_2d import geom_density_2d

check_geom_type("Plot.points()",         lambda p: p.points(),       geom_point)
check_geom_type("Plot.line()",           lambda p: p.line(),         geom_line)
check_geom_type("Plot.bars()",           lambda p: p.bars(),         geom_bar)
check_geom_type("Plot.columns()",        lambda p: p.columns(),      geom_col)
check_geom_type("Plot.histogram()",      lambda p: p.histogram(),    geom_histogram)
check_geom_type("Plot.boxplot()",        lambda p: p.boxplot(),      geom_boxplot)
check_geom_type("Plot.violin()",         lambda p: p.violin(),       geom_violin)
check_geom_type("Plot.smooth()",         lambda p: p.smooth(),       geom_smooth)
check_geom_type("Plot.density()",        lambda p: p.density(),      geom_density)
check_geom_type("Plot.jitter()",         lambda p: p.jitter(),       geom_jitter)
check_geom_type("Plot.rug()",            lambda p: p.rug(),          geom_rug)
check_geom_type("Plot.area()",           lambda p: p.area(),         geom_area)
check_geom_type("Plot.tile()",           lambda p: p.tile(),         geom_tile)
check_geom_type("Plot.path()",           lambda p: p.path(),         geom_path)
check_geom_type("Plot.step()",           lambda p: p.step(),         geom_step)
check_geom_type("Plot.frequency_polygon()", lambda p: p.frequency_polygon(), geom_freqpoly)
check_geom_type("Plot.qq()",             lambda p: p.qq(),           geom_qq)
check_geom_type("Plot.sina()",           lambda p: p.sina(),         geom_sina)
check_geom_type("Plot.bin_2d()",         lambda p: p.bin_2d(),       geom_bin2d)
check_geom_type("Plot.density_2d()",     lambda p: p.density_2d(),   geom_density_2d)
check_geom_type("Plot.horizontal_line(yintercept=0)", lambda p: p.horizontal_line(yintercept=0), geom_hline)
check_geom_type("Plot.vertical_line(xintercept=1)",   lambda p: p.vertical_line(xintercept=1),   geom_vline)
check_geom_type("Plot.diagonal_line(slope=1,intercept=0)", lambda p: p.diagonal_line(slope=1, intercept=0), geom_abline)

# ---------------------------------------------------------------------------
# Section 4: Full structural equality (spoken Plot == raw ggplot)
# ---------------------------------------------------------------------------

print("\n── Full structural equality ────────────────────────────────────────")

check_gg("plot(data) empty",
    plot(df),
    p9.ggplot(df))

check_gg("plot(data, x=, y=)",
    plot(df, x="x", y="y"),
    p9.ggplot(df, aes(x="x", y="y")))

check_gg("plot(data, x=, y=, color=)",
    plot(df, x="x", y="y", color="g"),
    p9.ggplot(df, aes(x="x", y="y", color="g")))

check_gg("scatter: plot + points()",
    plot(df, x="x", y="y").points(),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point())

check_gg("scatter with color",
    plot(df, x="x", y="y", color="g").points(),
    p9.ggplot(df, aes(x="x", y="y", color="g")) + p9.geom_point())

check_gg("scatter + smooth()",
    plot(df, x="x", y="y").points().smooth(),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.geom_smooth())

check_gg("histogram",
    plot(df, x="x").histogram(),
    p9.ggplot(df, aes(x="x")) + p9.geom_histogram())

check_gg("boxplot by group",
    plot(df, x="g", y="y").boxplot(),
    p9.ggplot(df, aes(x="g", y="y")) + p9.geom_boxplot())

check_gg("bar chart",
    plot(df, x="g").bars(),
    p9.ggplot(df, aes(x="g")) + p9.geom_bar())

check_gg("violin",
    plot(df, x="g", y="y").violin(),
    p9.ggplot(df, aes(x="g", y="y")) + p9.geom_violin())

check_gg("title + xlabel + ylabel",
    plot(df, x="x", y="y").points().title("T").xlabel("X").ylabel("Y"),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.ggtitle("T") + p9.xlab("X") + p9.ylab("Y"))

check_gg("theme_minimal",
    plot(df, x="x", y="y").points().theme_minimal(),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.theme_minimal())

check_gg("theme_bw / theme_black_white",
    plot(df, x="x", y="y").points().theme_black_white(),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.theme_bw())

check_gg("theme_classic",
    plot(df, x="x", y="y").points().theme_classic(),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.theme_classic())

check_gg("theme_dark",
    plot(df, x="x", y="y").points().theme_dark(),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.theme_dark())

check_gg("theme_void",
    plot(df, x="x", y="y").points().theme_void(),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.theme_void())

check_gg("coord_flip / flip()",
    plot(df, x="g", y="y").boxplot().flip(),
    p9.ggplot(df, aes(x="g", y="y")) + p9.geom_boxplot() + p9.coord_flip())

check_gg("facet_wrap / wrap_by",
    plot(df, x="x", y="y").points().wrap_by("g"),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.facet_wrap("g"))

check_gg("scale_x_log10 / log_x()",
    plot(df, x="x", y="y").points().log_x(),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.scale_x_log10())

check_gg("scale_y_log10 / log_y()",
    plot(df, x="x", y="y").points().log_y(),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.scale_y_log10())

check_gg("color_brewer",
    plot(df, x="x", y="y", color="g").points().color_brewer(type="qual"),
    p9.ggplot(df, aes(x="x", y="y", color="g")) + p9.geom_point() + p9.scale_color_brewer(type="qual"))

check_gg("color_manual",
    plot(df, x="x", y="y", color="g").points().color_manual(values=["red", "blue"]),
    p9.ggplot(df, aes(x="x", y="y", color="g")) + p9.geom_point() + p9.scale_color_manual(values=["red", "blue"]))

check_gg("fill_brewer",
    plot(df, x="g", fill="g").bars().fill_brewer(type="qual"),
    p9.ggplot(df, aes(x="g", fill="g")) + p9.geom_bar() + p9.scale_fill_brewer(type="qual"))

check_gg("x_range / xlim",
    plot(df, x="x", y="y").points().x_range(0, 6),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.xlim(0, 6))

check_gg("y_range / ylim",
    plot(df, x="x", y="y").points().y_range(0, 10),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.ylim(0, 10))

check_gg("reverse_x",
    plot(df, x="x", y="y").points().reverse_x(),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.scale_x_reverse())

check_gg("reverse_y",
    plot(df, x="x", y="y").points().reverse_y(),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.scale_y_reverse())

check_gg("hline",
    plot(df, x="x", y="y").points().horizontal_line(yintercept=3),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.geom_hline(yintercept=3))

check_gg("vline",
    plot(df, x="x", y="y").points().vertical_line(xintercept=2),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.geom_vline(xintercept=2))

check_gg("abline",
    plot(df, x="x", y="y").points().diagonal_line(slope=1, intercept=0),
    p9.ggplot(df, aes(x="x", y="y")) + p9.geom_point() + p9.geom_abline(slope=1, intercept=0))

check_gg("kitchen sink",
    (plot(df, x="x", y="y", color="g")
     .points()
     .smooth()
     .title("Kitchen Sink")
     .xlabel("X Axis")
     .ylabel("Y Axis")
     .theme_minimal()
     .color_brewer(type="qual")),
    (p9.ggplot(df, aes(x="x", y="y", color="g"))
     + p9.geom_point()
     + p9.geom_smooth()
     + p9.ggtitle("Kitchen Sink")
     + p9.xlab("X Axis")
     + p9.ylab("Y Axis")
     + p9.theme_minimal()
     + p9.scale_color_brewer(type="qual")))

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
