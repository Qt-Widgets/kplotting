# KPlotting

## Introduction
KPlotting provides classes to do plotting.

KPlotWidget is a QWidget-derived class that provides a virtual base class
for easy data-plotting. The idea behind KPlotWidget is that you only have
to specify information in "data units"; i.e., the natural units of the
data being plotted.  KPlotWidget automatically converts everything
to screen pixel units.

KPlotWidget draws X and Y axes with tickmarks and tick labels.  It
automatically determines how many tickmarks to use and where they should
be, based on the data limits specified for the plot.  You change the limits
by calling setLimits( double x1, double x2, double y1, double y2 ).

Data to be plotted are stored using the KPlotObject class.  KPlotObject
consists of a QList of QPointF's, each specifying the X,Y coordinates
of a data point.  KPlotObject also specifies the "type" of data to be
plotted (POINTS or CURVE or POLYGON or LABEL).

## Links

- Mailing list: <https://mail.kde.org/mailman/listinfo/kde-frameworks-devel>
- IRC channel: #kde-devel on Freenode
- Git repository: <https://projects.kde.org/projects/frameworks/kplotting/repository>