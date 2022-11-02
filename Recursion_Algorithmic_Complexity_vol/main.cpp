#include <iostream>
#include <cstdlib>
#include "Hanoi.h"
#include "Disc.h"
//#include "Disc.cpp"
//#include "Hanoi.cpp"
#include "print_backwards.h"
#include "nth_prime.h"

using namespace std;

// Hanoi solver function

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

int main()
{
    Hanoi han(8);
    int* arr;
    int indx, indx0, indx1, indx2;
    cout << han.get_num_of_discs() << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.discs[i].get_diameter() << endl;

    /*indx = han.get_last_nonzero_index(0);
    cout << indx << endl;
    cout << han.get_last_nonzero_index(1) << endl;
    han.move(0, 1);
    cout << han.get_last_nonzero_index(1) << endl;
    han.move(0, 1);
    cout << han.get_last_nonzero_index(1) << endl;
    han.move(0, 2);
    han.move(0, 2);
    han.move(1, 2);
    han.move(2, 0);*/

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


    //int prime;
    //char str[] = "ape1 ape2. \0";
    //cout << str << endl;
    //print_backwards(str);
    //prime = nth_prime(5);
    //cout << "\n" << prime << endl;
    return 0;
}
