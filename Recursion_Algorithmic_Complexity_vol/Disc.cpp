/////////////// functions for disc class ///////////////
#include "Disc.h"

// set the discs using diameters, constructor for the class
Disc::Disc(int diam){
    diameter = diam;
}

// get the diameter of the disc
int Disc::get_diameter() const{
    return diameter;
}

// set the diameter of the disc (if required)
void Disc::set_diameter(int diam){
    diameter = diam;
}
