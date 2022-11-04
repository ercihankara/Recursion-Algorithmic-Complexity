#include <iostream>
#include <cstdlib>
#include "Hanoi.h"
#include "Disc.h"
#include "print_backwards.h"
#include "nth_prime.h"

int step = 0;   // hold the number of actions taken
using namespace std;

// Hanoi solver function:
// for n discs, the total number of required steps is 2^n - 1
// recursive function to be called inside the "solve_hanoi" function
void Hanoi_helper(int nth_disc, int init, int fin, int aux, Hanoi& game){
    if (nth_disc == 0)
        return;
    step += 1;
    Hanoi_helper(nth_disc - 1, init, aux, fin, game);
    game.move(init, fin);
    Hanoi_helper(nth_disc - 1, aux, fin, init, game);
}

void solve_hanoi(Hanoi& game){
    // set init, aux, and fin by set_aux_fin function inside the Hanoi constructor
    Hanoi_helper(game.get_num_of_discs(), game.init, game.fin, game.aux, game);
}

int main()
{
    // for 1. part!

    Hanoi han(8);
    cout << han.get_num_of_discs() << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.discs[i].get_diameter() << endl;

    cout << "rod0" << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.get_rods(0)[i] << endl;
    cout << "rod1" << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.get_rods(1)[i] << endl;
     cout << "rod2" << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.get_rods(2)[i] << endl;

    solve_hanoi(han);

    cout << "rod0" << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.get_rods(0)[i] << endl;
    cout << "rod1" << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.get_rods(1)[i] << endl;
     cout << "rod2" << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.get_rods(2)[i] << endl;

    cout << "total steps: " << step << endl;

    // for 2. and 3. parts!

    //int prime;
    //char str[] = "apes strong together. \0";
    //cout << str << endl;
    //print_backwards(str);
    //prime = nth_prime(5);
    //cout << "\n" << prime << endl;

    return 0;
}
