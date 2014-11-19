#ifndef FOREGROUND_MAP_PLOT_H
#define	FOREGROUND_MAP_PLOT_H

#include "map_plot.h"

/**
 * Represents a foreground item that can be placed on a WorldMap
 */
class ForegroundMapPlot : public MapPlot {
private:
    // The item's type
    std::string type_;
public:
    /**
     * Constructs the item from a file.
     * See ForegroundMapPlot::pull_from_file
     * @param file_stream
     */
    ForegroundMapPlot(std::ifstream& file_stream);
    /**
     * @return the item's type
     */
    std::string type();
    /**
     * Fills the existing map plot data with the data from the next 5 lines of
     * a file where the first line is the item type and the rest are the plot
     * data.
     * @param file_stream
     */
    void pull_from_file(std::ifstream& file_stream);
};

#endif	/* FOREGROUND_MAP_PLOT_H */