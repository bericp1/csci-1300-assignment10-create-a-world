#include "foreground_map_plot.h"

// Forward to ForegroundMapPlo::pull_from_file
ForegroundMapPlot::ForegroundMapPlot(std::ifstream& file_stream) {this->pull_from_file(file_stream);}

void ForegroundMapPlot::pull_from_file(std::ifstream& file_stream){
    // Read the next line from the stream and store it as the type
    std::getline(file_stream, this->type_);
    // Pass the rest off to MapPlot::generate_from_file
    this->data(MapPlot::generate_from_file(file_stream));
}

std::string ForegroundMapPlot::type(){ return this->type_; }