#ifndef CHARACTER_MAP_PLOT_H
#define	CHARACTER_MAP_PLOT_H

#include "map_plot.h"

/**
 * Represents a character that can be placed in a WorldMap
 */
class CharacterMapPlot : public MapPlot {
private:
    // The character's name
    std::string name_;
    // The character's current activity
    std::string activity_;
public:
    /**
     * Constructs this character from a file.
     * See CharacterMapPlot::pull_from_file
     * @param file_stream
     */
    CharacterMapPlot(std::ifstream& file_stream);
    /**
     * @return the name of this character
     */
    std::string name() const;
    /**
     * Sets the name of the character to `name`
     * @param name
     */
    void set_name(const std::string& name);
    /**
     * @return the character's current activity
     */
    std::string activity() const;
    /**
     * Fills the existing map plot data with the data from the next 5 lines of
     * a file.
     * @param file_stream
     */
    void pull_from_file(std::ifstream& file_stream);
};

#endif	/* CHARACTER_MAP_PLOT_H */

