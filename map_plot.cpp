#include "map_plot.h"

MapPlot::MapPlot() {
    // Fill with blank spaces on construction with no file to pull from
    for(int i = 0; i < 4; i++) this->data_.push_back("        ");
}

// Call MapPlot::pull_from_file if just a file was passed in
MapPlot::MapPlot(std::ifstream& file_stream) { this->pull_from_file(file_stream); }

std::string MapPlot::row(const std::size_t& row) const {return this->data_[row];}
void MapPlot::row(const std::size_t& row, const std::string& new_row) {this->data_[row] = new_row;}
void MapPlot::data(std::vector<std::string> new_data){this->data_ = new_data;}

std::vector<std::string> MapPlot::generate_from_file(std::ifstream& file_stream){
    // Temp variables
    std::string line (""); std::size_t count = 0; std::vector<std::string> result;
    // Loop 4 times...
    while(count < 4){
        // Read in a line to the line string variable
        std::getline(file_stream, line);
        // Add it to the result vector
        result.push_back(line);
        count++;
    }
    return result;
}

void MapPlot::pull_from_file(std::ifstream& file_stream){
    // Just pass off to MapPlot::generate_from_file since normal map plots
    // have no extra information or special formats in their files
    this->data(MapPlot::generate_from_file(file_stream));
}