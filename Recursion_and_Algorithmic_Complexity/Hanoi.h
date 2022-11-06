// Ercihan Kara - 2375160
#include <iostream>
#include <cstdlib>
#include "Disc.h"
#pragma once

using namespace std;

class Hanoi{
    private:
        Disc* rod0;
        Disc* rod1;
        Disc* rod2;
        int num_discs;

    public:
        int aux, fin, init = 0;
        // the constructor for the class to initialize the game
        Hanoi(int num);
        Disc* get_rods(int rod_index);
        int get_last_nonzero_index(int rod_index);
        int get_num_of_discs() const;
        void set_aux_fin();   // function necessary for solver
        void move(int from, int to);
        int nonzero_index(Disc* arr);
        //~Hanoi();
};
