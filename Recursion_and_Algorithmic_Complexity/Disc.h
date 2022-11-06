// Ercihan Kara - 2375160
#pragma once

using namespace std;

class Disc
{
    private:
        // diameter of the disc
        int diameter;

    public:
        // the constructor for the class
        Disc(int diam = 0);
        // get the diameter of the disc
        int get_diameter();
        // get the number of disc
        void set_diameter(int diam);
};

