#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

class Disc
{
    private:
        // diameter of the disc
        int diameter;

    public:
        // the constructor for the class
        Disc(int diam = 1);
        // get the diameter of the disc
        int get_diameter() const;
        // get the number of disc
        void set_diameter(int diam);
};
