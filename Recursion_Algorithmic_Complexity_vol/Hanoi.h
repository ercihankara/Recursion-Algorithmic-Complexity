#include <iostream>
#include <cstdlib>
#include "Disc.h"
#pragma once

using namespace std;

class Hanoi{
    private:
        int rod0[20] = {0};
        int rod1[20] = {0};
        int rod2[20] = {0};
        int num_discs;

    public:
        int aux, fin, init = 0;
        Disc discs[];
        // the constructor for the class to initialize the game
        Hanoi(int num);
        int * get_rods(int rod_index);
        int get_last_nonzero_index(int rod_index);
        int get_num_of_discs() const;
        void set_aux_fin();   // function necessary for solver
        void move(int from, int to);

};
