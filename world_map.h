#ifndef WORLD_MAP_H
#define	WORLD_MAP_H

#include <boost/functional/hash.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_smallint.hpp>
#include <boost/random/variate_generator.hpp>
#include <vector>

#include "map_plot.h"
#include "background_map_plot.h"
#include "foreground_map_plot.h"
#include "character_map_plot.h"

/**
 * Represents a map of a world along with its characters, foreground items,
 * associated messages/information, etc.
 */
class WorldMap {
private:
    // The name of the world
    std::string name_;
    // The name of the world hashed into a std::size_t (u int, usually)
    std::size_t name_hash_;
    // The number of rows of plots that should be generated
    std::size_t num_rows_;
    // The number plots in each row that should be generated
    std::size_t num_cols_;
    // The vector of vector of background plots representing the 2D map
    std::vector<std::vector<BackgroundMapPlot> > data_;
    // Contains the plots pulled from the background_map_plots file
    std::vector<BackgroundMapPlot> background_map_plots_;
    // Contains the plots pulled from the foreground_map_plots file
    std::vector<ForegroundMapPlot> foreground_map_plots_;
    // Contains the plots pulled from the character_map_plots file
    std::vector<CharacterMapPlot> character_map_plots_;
    // The possible first names as pulled from the first_names file
    std::vector<std::string> first_names_;
    // The possible last names as pulled from the last_names file
    std::vector<std::string> last_names_;
    // The messages that describe the map
    std::vector<std::string> messages_;
    // A callable generated with boost that's used to hash the name
    boost::hash<std::string> string_hash;
public:
    // The type of the number generator engine
    typedef boost::mt19937 base_gen_type;
    // The type of the distribution to pull numbers from in the generator
    typedef boost::uniform_smallint<> dist_type;
    // The generator type as defined by the previous two types
    typedef boost::variate_generator<base_gen_type, dist_type> gen_type;
    /**
     * @param name
     * @param rows
     * @param cols
     */
    WorldMap(std::string name, std::size_t rows, std::size_t cols);
    /**
     * Will actually fill in the map with deterministic data pulled from the
     * supplied generator callable
     * @param gen 
     */
    void build(gen_type& gen);
    /**
     * Takes the map of plots and converts it to a single string
     * @return 
     */
    std::string serialize() const;
};

#endif	/* WORLD_MAP_H */