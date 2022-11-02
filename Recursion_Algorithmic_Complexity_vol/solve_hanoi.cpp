/////////////// solver function ///////////////
#include "Hanoi.h"

// for n discs, the total number of required steps is 2^n - 1; not a member function
void towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod, Hanoi& game){
    if (n == 0)
        return;
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, game);
    game.move(from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, game);
}

void solve_hanoi(Hanoi& game){
    // set aux and fin by set_aux_fin function inside the Hanoi constructor
    towerOfHanoi(game.get_num_of_discs(), game.init, game.fin, game.aux, game);
}

