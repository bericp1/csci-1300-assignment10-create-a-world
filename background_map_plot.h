#ifndef BACKGROUND_MAP_PLOT_H
#define	BACKGROUND_MAP_PLOT_H

#include "map_plot.h"

/**
 * Represents a map plot that occurs in the background and upon which other
 * plots may be laid in a WorldMap.
 */
class BackgroundMapPlot : public MapPlot {
public:
    BackgroundMapPlot(std::ifstream& file_stream) : MapPlot(file_stream) {};
    /**
     * Will overlay other MapPlots ontop of this instance, char-by-char. Note
     * that the character '?' is considered transparent and if it occurs in the
     * rhs MapPlot, it will cause that character to be skipped over, thus
     * leaving the current character in the plot as is.
     * @param rhs: the plot to overlay on top of the current plot instance
     * @return the current plot instance
     */
    MapPlot& operator+=(const MapPlot& rhs);
};

#endif	/* BACKGROUND_MAP_PLOT_H */