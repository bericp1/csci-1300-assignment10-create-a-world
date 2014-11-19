#include <boost/lexical_cast.hpp>

#include "world_map.h"

// Start by initializing name, name_hash, num_rows, and num_cols
WorldMap::WorldMap(std::string name, std::size_t rows, std::size_t cols) : name_(name), name_hash_(string_hash(name)), num_rows_(rows), num_cols_(cols){
    // Some temp variables for reading in files
    std::string active_file; std::ifstream active_file_stream; std::string active_line ("");
    // An array of filenames to read from
    std::string files[5] = {"background_map_plots", "foreground_map_plots", "character_map_plots", "first_names", "last_names"};
    // Begin looping through each file
    for(int i = 0; i < 5; i++){
        // Get the name of the active file and open a stream to it
        active_file = files[i]; active_file_stream.open(active_file.c_str());
        // Start looping through the file and stop when we reach the end (EOF)
        while(active_file_stream.peek() != std::char_traits<char>::eof()){
            // For all the *_map_plots files, generate their appropriate
            // MapPlots by passing around the file_stream and store them in the
            // appropriate vectors
            if(active_file=="background_map_plots") this->background_map_plots_.push_back(BackgroundMapPlot (active_file_stream));
            else if(active_file == "foreground_map_plots") this->foreground_map_plots_.push_back(ForegroundMapPlot (active_file_stream));
            else if(active_file == "character_map_plots") this->character_map_plots_.push_back(CharacterMapPlot (active_file_stream));
            // For the *_names files, just read in each line as a separate
            // item in the approriate vector
            else if(active_file == "first_names") {std::getline(active_file_stream, active_line); this->first_names_.push_back(active_line);}
            else if(active_file == "last_names") {std::getline(active_file_stream, active_line); this->last_names_.push_back(active_line);}
        }
        // Close the file_stream so that it can be opened for the next file.
        active_file_stream.close();
    }
    
    // Create the number generator using the name_hash as the seed. It shall
    // generate an integer between 0 and 100. The modulo operator is used
    // later on to cut this number down to needed domains
    WorldMap::base_gen_type base_gen (this->name_hash_);
    WorldMap::gen_type gen(base_gen, WorldMap::dist_type(0,100));
    // Begin looping through each row of map plots that is to be created
    for(std::size_t row = 0; row < this->num_rows_; row++){
        // Create the new row
        std::vector<BackgroundMapPlot> new_row;
        // Begin looping through each plot in the row that is to be created
        for(std::size_t col = 0; col < this->num_cols_; col++)
            // Add a background plot randomly selected from the vector of back-
            // ground plots to the new row
            new_row.push_back(this->background_map_plots_[gen() % this->background_map_plots_.size()]);
        // Add the row to the map
        this->data_.push_back(new_row);
    }
    
    //TODO Create a coord ban list so that dupes aren't placed ontop of eachother
    
    // Begin looping through each available foreground tile to be placed
    for(std::size_t fg_idx = 0; fg_idx < this->foreground_map_plots_.size(); fg_idx++)
        // (gen() % n) will generate an integer on the interval [0,n). We then
        // check to see if this number is 0 to see if we want to place this
        // particular foreground tile. This essentially gives each tile a 1 in
        // n chance of being placed.
        if((gen() % 3) == 0){
            // Generate a random row/column number
            std::size_t row = (gen() % this->num_rows_); std::size_t col = (gen() % this->num_cols_);
            // Get a pointer to the foreground plot of interest
            ForegroundMapPlot* fg_map_plot = &this->foreground_map_plots_[fg_idx];
            // Overlay the plot of interest onto the randomly selected plot
            this->data_[row][col] += (MapPlot) *fg_map_plot;
            // Add a descriptive message to the message queue
            this->messages_.push_back("There is a " + fg_map_plot->type() + " at " + boost::lexical_cast<std::string>(row+1) + ", " + boost::lexical_cast<std::string>(col+1));
        }
    // Repeat the above loop for character plots
    for(std::size_t ch_idx = 0; ch_idx < this->character_map_plots_.size(); ch_idx++)
        if((gen() % 3) == 0){
            std::size_t row = (gen() % this->num_rows_); std::size_t col = (gen() % this->num_cols_);
            CharacterMapPlot* ch_map_plot = &this->character_map_plots_[ch_idx];
            // Additionally, though, we want to also generate a name by
            // selecting a random first name and last name and concatenating
            // them.
            ch_map_plot->set_name(this->first_names_[(gen() % this->first_names_.size())] + " " + this->last_names_[(gen() % this->last_names_.size())]);
            this->data_[row][col] += (MapPlot) *ch_map_plot;
            this->messages_.push_back(ch_map_plot->name() + " is at " + boost::lexical_cast<std::string>(row+1) + ", " + boost::lexical_cast<std::string>(col+1) + " and is " + ch_map_plot->activity());
        }
}

std::string WorldMap::serialize() const {
    // Create a variable to store the result of the serialization as we go
    std::string result = "";
    // Begin looping through each row of plots
    for(int map_row = 0; map_row < this->num_rows_; map_row++)
        // Then loop through each row of the plots in the given row
        for(int plot_row = 0; plot_row < 4; plot_row++){
            // Then loop through each string associated with each plot in the row
            for(int map_col = 0; map_col < this->num_cols_; map_col++)
                // And append the row to the resultant string
                result += this->data_[map_row][map_col].row(plot_row);
            // When we get to the end of a row of strings, we add a newline
            result += "\n";
        }
    // We also add a newline at the end of the serialization before the messages
    result += "\n";
    // Loop through each message and append to the messages vector with a newline
    for(int m_idx = 0; m_idx < this->messages_.size(); m_idx++)
        result += this->messages_[m_idx] + "\n";
    
    return result;
}