"""
spoken_plotnine.py — Spoken English interface to plotnine

Every method on Plot compiles 1:1 to a plotnine object via the + operator.
No magic, no approximation — each spoken call wraps the exact plotnine call.

Spoken English design principles:
- ggplot()          → plot(data)  or  plot(data).map(x="col", y="col")
- aes()             → map(x=, y=, color=, fill=, size=, shape=, alpha=, group=)
- geom_point()      → points()
- geom_line()       → line()
- geom_bar()        → bars()
- geom_col()        → columns()
- geom_histogram()  → histogram()
- geom_boxplot()    → boxplot()
- geom_violin()     → violin()
- geom_smooth()     → smooth()
- geom_density()    → density()
- geom_area()       → area()
- geom_ribbon()     → ribbon()
- geom_text()       → text(label=)
- geom_label()      → label(label=)
- geom_hline()      → horizontal_line(yintercept=)
- geom_vline()      → vertical_line(xintercept=)
- geom_abline()     → diagonal_line(slope=, intercept=)
- geom_segment()    → segment(x=, y=, xend=, yend=)
- geom_errorbar()   → error_bars(ymin=, ymax=)
- geom_rug()        → rug()
- geom_jitter()     → jitter()
- geom_count()      → count_points()
- geom_tile()       → tile()
- geom_raster()     → raster()
- geom_rect()       → rect(xmin=, xmax=, ymin=, ymax=)
- geom_polygon()    → polygon()
- geom_path()       → path()
- geom_step()       → step()
- geom_freqpoly()   → frequency_polygon()
- geom_dotplot()    → dot_plot()
- geom_qq()         → qq()
- geom_quantile()   → quantile()
- geom_sina()       → sina()
- geom_crossbar()   → crossbar()
- geom_linerange()  → line_range()
- geom_pointrange() → point_range()
- geom_bin2d()      → bin_2d()
- geom_density_2d() → density_2d()
- geom_pointdensity() → point_density()

- facet_wrap()      → facet(~col)          / wrap_by(col)
- facet_grid()      → grid_by(row, col)
- coord_flip()      → flip()
- coord_fixed()     → fixed_ratio(ratio=)
- coord_cartesian() → zoom(xlim=, ylim=)
- coord_trans()     → transform_axes(x=, y=)

- labs()            → title(t).xlabel(x).ylabel(y)
- ggtitle()         → title(t)
- xlab()            → xlabel(x)
- ylab()            → ylabel(y)
- xlim()            → x_range(lo, hi)
- ylim()            → y_range(lo, hi)

- theme_bw()        → theme_black_white()
- theme_minimal()   → theme_minimal()
- theme_classic()   → theme_classic()
- theme_dark()      → theme_dark()
- theme_gray()      → theme_gray()
- theme_void()      → theme_void()
- theme_538()       → theme_538()
- theme_tufte()     → theme_tufte()
- theme_xkcd()      → theme_xkcd()
- theme_seaborn()   → theme_seaborn()
- theme_matplotlib()→ theme_matplotlib()
- theme_linedraw()  → theme_linedraw()
- theme_light()     → theme_light()
- theme()           → theme_set(...)   / adjust_theme(**kwargs)

- scale_color_brewer()   → color_brewer(palette=)
- scale_color_gradient() → color_gradient(low=, high=)
- scale_color_gradient2()→ color_gradient2(low=, mid=, high=)
- scale_color_manual()   → color_manual(values=[])
- scale_color_cmap()     → color_map(cmap=)
- scale_fill_brewer()    → fill_brewer(palette=)
- scale_fill_gradient()  → fill_gradient(low=, high=)
- scale_fill_manual()    → fill_manual(values=[])
- scale_x_log10()        → log_x()
- scale_y_log10()        → log_y()
- scale_x_reverse()      → reverse_x()
- scale_y_reverse()      → reverse_y()
- scale_x_continuous()   → scale_x(breaks=, labels=, limits=)
- scale_y_continuous()   → scale_y(breaks=, labels=, limits=)
- scale_x_discrete()     → scale_x_discrete(limits=)
- scale_y_discrete()     → scale_y_discrete(limits=)
- scale_size()           → scale_size(range=)
- scale_alpha()          → scale_alpha(range=)
- scale_shape()          → scale_shape()

- position_dodge()       → dodge()
- position_stack()       → stack()
- position_fill()        → fill_position()
- position_jitter()      → jitter_position()

- annotate()             → annotate(geom, x, y, ...)
- expand_limits()        → expand_limits(x=, y=)
- guides()               → legend(color=, fill=, size=)
- ggsave()               → save(filename)

Usage:
    from spoken_plotnine import plot, map
    import pandas as pd

    df = pd.DataFrame({"x": [1,2,3], "y": [4,5,6], "g": ["a","b","a"]})

    p = (plot(df)
         .map(x="x", y="y", color="g")
         .points()
         .smooth()
         .title("My Chart")
         .xlabel("X Axis")
         .ylabel("Y Axis")
         .theme_minimal())

    p.show()
    p.save("out.png")

    # Access the underlying plotnine object at any time:
    p.build()
"""

import plotnine as p9
from plotnine import aes


# ---------------------------------------------------------------------------
# Aesthetic mapping helper (also exported so you can call map(...) standalone)
# ---------------------------------------------------------------------------

def map(**kwargs):
    """Spoken aes() — map(x="col", y="col", color="group")"""
    return aes(**kwargs)


# ---------------------------------------------------------------------------
# Plot — the main fluent builder
# ---------------------------------------------------------------------------

class Plot:
    """
    Fluent spoken-English wrapper around a plotnine ggplot object.

    Each method returns self so calls can be chained.
    .build() returns the raw ggplot object for inspection / equality tests.
    .show() renders it.
    .save(path) saves it.
    """

    def __init__(self, data=None, mapping=None):
        self._layers = []
        self._data = data
        self._mapping = mapping
        if data is not None and mapping is not None:
            self._gg = p9.ggplot(data, mapping)
        elif data is not None:
            self._gg = p9.ggplot(data)
        else:
            self._gg = p9.ggplot()

    def _add(self, layer):
        self._gg = self._gg + layer
        return self

    # ------------------------------------------------------------------
    # Aesthetic mapping (can be set after construction too)
    # ------------------------------------------------------------------

    def map(self, **kwargs):
        """map(x="col", y="col", color="grp") — set aesthetic mapping"""
        self._gg = self._gg + aes(**kwargs)
        return self

    # ------------------------------------------------------------------
    # Geoms
    # ------------------------------------------------------------------

    def points(self, **kwargs):
        """geom_point()"""
        return self._add(p9.geom_point(**kwargs))

    def line(self, **kwargs):
        """geom_line()"""
        return self._add(p9.geom_line(**kwargs))

    def bars(self, **kwargs):
        """geom_bar() — count-based bars"""
        return self._add(p9.geom_bar(**kwargs))

    def columns(self, **kwargs):
        """geom_col() — value-based bars"""
        return self._add(p9.geom_col(**kwargs))

    def histogram(self, **kwargs):
        """geom_histogram()"""
        return self._add(p9.geom_histogram(**kwargs))

    def boxplot(self, **kwargs):
        """geom_boxplot()"""
        return self._add(p9.geom_boxplot(**kwargs))

    def violin(self, **kwargs):
        """geom_violin()"""
        return self._add(p9.geom_violin(**kwargs))

    def smooth(self, **kwargs):
        """geom_smooth() — trend line with confidence interval"""
        return self._add(p9.geom_smooth(**kwargs))

    def density(self, **kwargs):
        """geom_density()"""
        return self._add(p9.geom_density(**kwargs))

    def area(self, **kwargs):
        """geom_area()"""
        return self._add(p9.geom_area(**kwargs))

    def ribbon(self, **kwargs):
        """geom_ribbon(ymin=, ymax=)"""
        return self._add(p9.geom_ribbon(**kwargs))

    def text(self, **kwargs):
        """geom_text(label=)"""
        return self._add(p9.geom_text(**kwargs))

    def label(self, **kwargs):
        """geom_label(label=) — text with background box"""
        return self._add(p9.geom_label(**kwargs))

    def horizontal_line(self, **kwargs):
        """geom_hline(yintercept=)"""
        return self._add(p9.geom_hline(**kwargs))

    def vertical_line(self, **kwargs):
        """geom_vline(xintercept=)"""
        return self._add(p9.geom_vline(**kwargs))

    def diagonal_line(self, **kwargs):
        """geom_abline(slope=, intercept=)"""
        return self._add(p9.geom_abline(**kwargs))

    def segment(self, **kwargs):
        """geom_segment(x=, y=, xend=, yend=)"""
        return self._add(p9.geom_segment(**kwargs))

    def error_bars(self, **kwargs):
        """geom_errorbar(ymin=, ymax=)"""
        return self._add(p9.geom_errorbar(**kwargs))

    def rug(self, **kwargs):
        """geom_rug()"""
        return self._add(p9.geom_rug(**kwargs))

    def jitter(self, **kwargs):
        """geom_jitter()"""
        return self._add(p9.geom_jitter(**kwargs))

    def count_points(self, **kwargs):
        """geom_count() — size encodes count of overlapping points"""
        return self._add(p9.geom_count(**kwargs))

    def tile(self, **kwargs):
        """geom_tile()"""
        return self._add(p9.geom_tile(**kwargs))

    def raster(self, **kwargs):
        """geom_raster()"""
        return self._add(p9.geom_raster(**kwargs))

    def rect(self, **kwargs):
        """geom_rect(xmin=, xmax=, ymin=, ymax=)"""
        return self._add(p9.geom_rect(**kwargs))

    def polygon(self, **kwargs):
        """geom_polygon()"""
        return self._add(p9.geom_polygon(**kwargs))

    def path(self, **kwargs):
        """geom_path()"""
        return self._add(p9.geom_path(**kwargs))

    def step(self, **kwargs):
        """geom_step()"""
        return self._add(p9.geom_step(**kwargs))

    def frequency_polygon(self, **kwargs):
        """geom_freqpoly()"""
        return self._add(p9.geom_freqpoly(**kwargs))

    def dot_plot(self, **kwargs):
        """geom_dotplot()"""
        return self._add(p9.geom_dotplot(**kwargs))

    def qq(self, **kwargs):
        """geom_qq()"""
        return self._add(p9.geom_qq(**kwargs))

    def quantile(self, **kwargs):
        """geom_quantile()"""
        return self._add(p9.geom_quantile(**kwargs))

    def sina(self, **kwargs):
        """geom_sina()"""
        return self._add(p9.geom_sina(**kwargs))

    def crossbar(self, **kwargs):
        """geom_crossbar()"""
        return self._add(p9.geom_crossbar(**kwargs))

    def line_range(self, **kwargs):
        """geom_linerange()"""
        return self._add(p9.geom_linerange(**kwargs))

    def point_range(self, **kwargs):
        """geom_pointrange()"""
        return self._add(p9.geom_pointrange(**kwargs))

    def bin_2d(self, **kwargs):
        """geom_bin2d()"""
        return self._add(p9.geom_bin2d(**kwargs))

    def density_2d(self, **kwargs):
        """geom_density_2d()"""
        return self._add(p9.geom_density_2d(**kwargs))

    def point_density(self, **kwargs):
        """geom_pointdensity()"""
        return self._add(p9.geom_pointdensity(**kwargs))

    # ------------------------------------------------------------------
    # Stats  (stat_* objects used as layers — add_stat pattern)
    # ------------------------------------------------------------------

    def stat_smooth(self, **kwargs):
        """stat_smooth() — trend line stat (alternative to geom_smooth)"""
        return self._add(p9.stat_smooth(**kwargs))

    def stat_summary(self, **kwargs):
        """stat_summary(fun_y=, fun_ymin=, fun_ymax=) — summarize y per x"""
        return self._add(p9.stat_summary(**kwargs))

    def stat_summary_bin(self, **kwargs):
        """stat_summary_bin() — summarize within x bins"""
        return self._add(p9.stat_summary_bin(**kwargs))

    def stat_ecdf(self, **kwargs):
        """stat_ecdf() — empirical cumulative distribution function"""
        return self._add(p9.stat_ecdf(**kwargs))

    def stat_ellipse(self, **kwargs):
        """stat_ellipse() — confidence ellipse around point cloud"""
        return self._add(p9.stat_ellipse(**kwargs))

    def stat_hull(self, **kwargs):
        """stat_hull() — convex hull around point cloud"""
        return self._add(p9.stat_hull(**kwargs))

    def stat_density(self, **kwargs):
        """stat_density()"""
        return self._add(p9.stat_density(**kwargs))

    def stat_bin(self, **kwargs):
        """stat_bin()"""
        return self._add(p9.stat_bin(**kwargs))

    def stat_count(self, **kwargs):
        """stat_count()"""
        return self._add(p9.stat_count(**kwargs))

    def stat_identity(self, **kwargs):
        """stat_identity()"""
        return self._add(p9.stat_identity(**kwargs))

    def stat_function(self, **kwargs):
        """stat_function(fun=) — plot an arbitrary function"""
        return self._add(p9.stat_function(**kwargs))

    def stat_qq(self, **kwargs):
        """stat_qq()"""
        return self._add(p9.stat_qq(**kwargs))

    def stat_qq_line(self, **kwargs):
        """stat_qq_line()"""
        return self._add(p9.stat_qq_line(**kwargs))

    def stat_unique(self, **kwargs):
        """stat_unique() — remove duplicate rows"""
        return self._add(p9.stat_unique(**kwargs))

    def stat_sum(self, **kwargs):
        """stat_sum() — sum duplicate points"""
        return self._add(p9.stat_sum(**kwargs))

    def stat_density_2d(self, **kwargs):
        """stat_density_2d()"""
        return self._add(p9.stat_density_2d(**kwargs))

    def stat_bin_2d(self, **kwargs):
        """stat_bin2d()"""
        return self._add(p9.stat_bin2d(**kwargs))

    def stat_quantile(self, **kwargs):
        """stat_quantile()"""
        return self._add(p9.stat_quantile(**kwargs))

    def stat_ydensity(self, **kwargs):
        """stat_ydensity()"""
        return self._add(p9.stat_ydensity(**kwargs))

    def stat_bindot(self, **kwargs):
        """stat_bindot()"""
        return self._add(p9.stat_bindot(**kwargs))

    def stat_boxplot(self, **kwargs):
        """stat_boxplot()"""
        return self._add(p9.stat_boxplot(**kwargs))

    def stat_sina(self, **kwargs):
        """stat_sina()"""
        return self._add(p9.stat_sina(**kwargs))

    def stat_pointdensity(self, **kwargs):
        """stat_pointdensity()"""
        return self._add(p9.stat_pointdensity(**kwargs))

    # ------------------------------------------------------------------
    # Facets
    # ------------------------------------------------------------------

    def wrap_by(self, *facets, **kwargs):
        """facet_wrap(~col) — small multiples in a ribbon"""
        return self._add(p9.facet_wrap(facets, **kwargs))

    def grid_by(self, rows=None, cols=None, **kwargs):
        """facet_grid(rows~cols) — rows and columns of panels"""
        if rows and cols:
            facets = f"{rows}~{cols}"
        elif rows:
            facets = f"{rows}~."
        elif cols:
            facets = f".~{cols}"
        else:
            facets = "."
        return self._add(p9.facet_grid(facets, **kwargs))

    # ------------------------------------------------------------------
    # Coordinates
    # ------------------------------------------------------------------

    def flip(self):
        """coord_flip() — swap x and y axes"""
        return self._add(p9.coord_flip())

    def fixed_ratio(self, ratio=1, **kwargs):
        """coord_fixed(ratio=) — equal-aspect coordinates"""
        return self._add(p9.coord_fixed(ratio=ratio, **kwargs))

    def zoom(self, xlim=None, ylim=None, **kwargs):
        """coord_cartesian(xlim=, ylim=) — zoom without clipping data"""
        return self._add(p9.coord_cartesian(xlim=xlim, ylim=ylim, **kwargs))

    def transform_axes(self, x=None, y=None, **kwargs):
        """coord_trans(x=, y=) — axis transformation (e.g. 'log10')"""
        kw = {}
        if x is not None:
            kw["x"] = x
        if y is not None:
            kw["y"] = y
        kw.update(kwargs)
        return self._add(p9.coord_trans(**kw))

    # ------------------------------------------------------------------
    # Labels
    # ------------------------------------------------------------------

    def title(self, t):
        """ggtitle(t)"""
        return self._add(p9.ggtitle(t))

    def xlabel(self, x):
        """xlab(x)"""
        return self._add(p9.xlab(x))

    def ylabel(self, y):
        """ylab(y)"""
        return self._add(p9.ylab(y))

    def labels(self, title=None, x=None, y=None, **kwargs):
        """labs(title=, x=, y=, ...) — set multiple labels at once"""
        kw = {}
        if title is not None:
            kw["title"] = title
        if x is not None:
            kw["x"] = x
        if y is not None:
            kw["y"] = y
        kw.update(kwargs)
        return self._add(p9.labs(**kw))

    def x_range(self, lo, hi):
        """xlim(lo, hi)"""
        return self._add(p9.xlim(lo, hi))

    def y_range(self, lo, hi):
        """ylim(lo, hi)"""
        return self._add(p9.ylim(lo, hi))

    def expand_limits(self, **kwargs):
        """expand_limits(x=, y=)"""
        return self._add(p9.expand_limits(**kwargs))

    # ------------------------------------------------------------------
    # Themes
    # ------------------------------------------------------------------

    def theme_black_white(self):
        """theme_bw()"""
        return self._add(p9.theme_bw())

    def theme_minimal(self):
        """theme_minimal()"""
        return self._add(p9.theme_minimal())

    def theme_classic(self):
        """theme_classic()"""
        return self._add(p9.theme_classic())

    def theme_dark(self):
        """theme_dark()"""
        return self._add(p9.theme_dark())

    def theme_gray(self):
        """theme_gray()"""
        return self._add(p9.theme_gray())

    def theme_void(self):
        """theme_void()"""
        return self._add(p9.theme_void())

    def theme_538(self):
        """theme_538()"""
        return self._add(p9.theme_538())

    def theme_tufte(self):
        """theme_tufte()"""
        return self._add(p9.theme_tufte())

    def theme_xkcd(self):
        """theme_xkcd()"""
        return self._add(p9.theme_xkcd())

    def theme_seaborn(self):
        """theme_seaborn()"""
        return self._add(p9.theme_seaborn())

    def theme_matplotlib(self):
        """theme_matplotlib()"""
        return self._add(p9.theme_matplotlib())

    def theme_linedraw(self):
        """theme_linedraw()"""
        return self._add(p9.theme_linedraw())

    def theme_light(self):
        """theme_light()"""
        return self._add(p9.theme_light())

    def adjust_theme(self, **kwargs):
        """theme(**kwargs) — fine-grained theme tweaks"""
        return self._add(p9.theme(**kwargs))

    # ------------------------------------------------------------------
    # Scales — color / fill
    # ------------------------------------------------------------------

    def color_brewer(self, **kwargs):
        """scale_color_brewer(palette=, type=)"""
        return self._add(p9.scale_color_brewer(**kwargs))

    def color_gradient(self, low=None, high=None, **kwargs):
        """scale_color_gradient(low=, high=)"""
        kw = {}
        if low is not None:
            kw["low"] = low
        if high is not None:
            kw["high"] = high
        kw.update(kwargs)
        return self._add(p9.scale_color_gradient(**kw))

    def color_gradient2(self, low=None, mid=None, high=None, **kwargs):
        """scale_color_gradient2(low=, mid=, high=)"""
        kw = {}
        if low is not None:
            kw["low"] = low
        if mid is not None:
            kw["mid"] = mid
        if high is not None:
            kw["high"] = high
        kw.update(kwargs)
        return self._add(p9.scale_color_gradient2(**kw))

    def color_manual(self, values, **kwargs):
        """scale_color_manual(values=[...])"""
        return self._add(p9.scale_color_manual(values=values, **kwargs))

    def color_map(self, cmap, **kwargs):
        """scale_color_cmap(cmap=)"""
        return self._add(p9.scale_color_cmap(cmap, **kwargs))

    def fill_brewer(self, **kwargs):
        """scale_fill_brewer(palette=, type=)"""
        return self._add(p9.scale_fill_brewer(**kwargs))

    def fill_gradient(self, low=None, high=None, **kwargs):
        """scale_fill_gradient(low=, high=)"""
        kw = {}
        if low is not None:
            kw["low"] = low
        if high is not None:
            kw["high"] = high
        kw.update(kwargs)
        return self._add(p9.scale_fill_gradient(**kw))

    def fill_manual(self, values, **kwargs):
        """scale_fill_manual(values=[...])"""
        return self._add(p9.scale_fill_manual(values=values, **kwargs))

    def fill_map(self, cmap, **kwargs):
        """scale_fill_cmap(cmap=)"""
        return self._add(p9.scale_fill_cmap(cmap, **kwargs))

    # ------------------------------------------------------------------
    # Scales — axes
    # ------------------------------------------------------------------

    def log_x(self, **kwargs):
        """scale_x_log10()"""
        return self._add(p9.scale_x_log10(**kwargs))

    def log_y(self, **kwargs):
        """scale_y_log10()"""
        return self._add(p9.scale_y_log10(**kwargs))

    def reverse_x(self, **kwargs):
        """scale_x_reverse()"""
        return self._add(p9.scale_x_reverse(**kwargs))

    def reverse_y(self, **kwargs):
        """scale_y_reverse()"""
        return self._add(p9.scale_y_reverse(**kwargs))

    def scale_x(self, **kwargs):
        """scale_x_continuous(breaks=, labels=, limits=)"""
        return self._add(p9.scale_x_continuous(**kwargs))

    def scale_y(self, **kwargs):
        """scale_y_continuous(breaks=, labels=, limits=)"""
        return self._add(p9.scale_y_continuous(**kwargs))

    def scale_x_discrete(self, **kwargs):
        """scale_x_discrete(limits=)"""
        return self._add(p9.scale_x_discrete(**kwargs))

    def scale_y_discrete(self, **kwargs):
        """scale_y_discrete(limits=)"""
        return self._add(p9.scale_y_discrete(**kwargs))

    def scale_size(self, **kwargs):
        """scale_size(range=)"""
        return self._add(p9.scale_size(**kwargs))

    def scale_alpha(self, **kwargs):
        """scale_alpha(range=)"""
        return self._add(p9.scale_alpha(**kwargs))

    def scale_shape(self, **kwargs):
        """scale_shape()"""
        return self._add(p9.scale_shape(**kwargs))

    # ------------------------------------------------------------------
    # Positions
    # ------------------------------------------------------------------

    def dodge(self, width=None):
        """position_dodge(width=) — returns a position object for use in geoms"""
        kw = {"width": width} if width is not None else {}
        return p9.position_dodge(**kw)

    def stack(self):
        """position_stack()"""
        return p9.position_stack()

    def fill_position(self):
        """position_fill()"""
        return p9.position_fill()

    def jitter_position(self, width=None, height=None):
        """position_jitter(width=, height=)"""
        kw = {}
        if width is not None:
            kw["width"] = width
        if height is not None:
            kw["height"] = height
        return p9.position_jitter(**kw)

    # ------------------------------------------------------------------
    # Annotations / guides
    # ------------------------------------------------------------------

    def annotate(self, geom, **kwargs):
        """annotate(geom, x=, y=, label=, ...)"""
        return self._add(p9.annotate(geom, **kwargs))

    def legend(self, **kwargs):
        """guides(color=, fill=, size=, ...)"""
        return self._add(p9.guides(**kwargs))

    # ------------------------------------------------------------------
    # Build / render / save
    # ------------------------------------------------------------------

    def build(self):
        """Return the underlying plotnine ggplot object."""
        return self._gg

    def show(self):
        """Render the plot (calls ggplot.draw())."""
        return self._gg.draw()

    def save(self, filename, **kwargs):
        """ggsave(filename, ...) — save to file"""
        return p9.ggsave(self._gg, filename, **kwargs)

    def __repr__(self):
        return f"Plot({self._gg!r})"


# ---------------------------------------------------------------------------
# Top-level factory — the main entry point
# ---------------------------------------------------------------------------

def plot(data=None, **mapping_kwargs):
    """
    Start a spoken plot.

    plot(df)                          — data only, map later
    plot(df, x="col", y="col")        — data + immediate mapping
    plot(df, x="col", y="col", color="grp")
    """
    if mapping_kwargs:
        return Plot(data, aes(**mapping_kwargs))
    return Plot(data)
