#ifndef MAP_PLOT_H
#define	MAP_PLOT_H

#include <fstream>
#include <vector>

/**
 * Represents a map plot that can be placed in a WorldMap.
 */
class MapPlot {
protected:
    // A vector of 4 strings where each string consists of 8 characters
    // holding the plots visual representation
    std::vector<std::string> data_;
public:
    MapPlot();
    /**
     * Creates the map plot by filling in the plot data from a file. See
     * MapPlot::pull_from_file
     * @param file_stream
     */
    MapPlot(std::ifstream& file_stream);
    /**
     * @param row: the index of the row to get on the interval [0,3]
     * @return a string of 8 characters representing the row
     */
    std::string row(const std::size_t& row) const;
    /**
     * @param row: the index of the row to change on the interval [0,3]
     * @param new_row: the string of 8 characters to replace the row with
     */
    void row(const std::size_t& row, const std::string& new_row);
    /**
     * @param new_data: A vector of 4 strings of 8 characters each to replace
     *      the current map plot data with.
     */
    void data(std::vector<std::string> new_data);
    /**
     * Build map plot data from the next 4 lines of a file
     * @param file_stream
     * @return Returns a vector of 4 strings, one from each of the 4 file lines
     */
    static std::vector<std::string> generate_from_file (std::ifstream& file_stream);
    /**
     * Sets the plots data to data pulled from a file.
     * MapPlot::generate_from_file is to be used here
     * @param file_stream
     */
    virtual void pull_from_file(std::ifstream& file_stream);
};

#endif	/* MAP_PLOT_H */