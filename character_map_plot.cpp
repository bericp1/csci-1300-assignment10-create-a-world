#include "character_map_plot.h"

// Forward to the overridde pull_from_file
CharacterMapPlot::CharacterMapPlot(std::ifstream& file_stream) {this->pull_from_file(file_stream);}

std::string CharacterMapPlot::name() const {return this->name_;}

void CharacterMapPlot::set_name(const std::string& name) {this->name_ = name;}

std::string CharacterMapPlot::activity() const {return this->activity_;}

void CharacterMapPlot::pull_from_file(std::ifstream& file_stream) {
    // Get the next line in the stream and put it as the activity
    std::getline(file_stream, this->activity_);
    // Pass the rest of the stream off to MapPlot::generate_from_file
    this->data(MapPlot::generate_from_file(file_stream));
}
