#include "background_map_plot.h"

MapPlot& BackgroundMapPlot::operator+=(const MapPlot& rhs){
    // Loop through each line of the 4 lines
    for(int i = 0; i < 4; i++){
        // Create a string to store the new row
        std::string new_row = "";
        // Loop through each character
        for(int j = 0; j < 8; j++){
            // If the rhs plot's current character is not the '?' character
            // set the new character to the rhs plot's current character
            if(rhs.row(i)[j] != '?') new_row += rhs.row(i)[j];
            // If it is a '?' keep the current character
            else new_row += this->row(i)[j];
        }
        // Set the new row
        this->row(i, new_row);
    }
    return *this;
}