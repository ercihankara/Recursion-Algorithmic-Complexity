// Ercihan Kara - 2375160
#include <iostream>
#include <cstdlib>
#include "Hanoi.h"
#include "Disc.h"
#include "print_backwards.h"
#include "nth_prime.h"
#include "solve_hanoi.h"

using namespace std;

// Hanoi solver function:
// for n discs, the total number of required steps is 2^n - 1
// recursive function to be called inside the "solve_hanoi" function

int main()
{
    // for 1. part!

    Hanoi han(4);
    cout << "Before" << endl;

    cout << "rod0" << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.get_rods(0)[i].get_diameter() << endl;
    cout << "rod1" << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.get_rods(1)[i].get_diameter() << endl;
     cout << "rod2" << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.get_rods(2)[i].get_diameter() << endl;

    solve_hanoi(han);

    cout << "After" << endl;
    cout << "rod0" << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.get_rods(0)[i].get_diameter() << endl;
    cout << "rod1" << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.get_rods(1)[i].get_diameter() << endl;
     cout << "rod2" << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.get_rods(2)[i].get_diameter() << endl;

    cout << "total steps: " << step << endl;

    // for 2. and 3. parts!

    /*
    char str[] = "apes strong together. \0";
    cout << str << endl;
    cout << endl;
    print_backwards(str);*/
    /*int prime;
    prime = nth_prime(5);
    cout << "5th prime number: " << endl;
    cout << "\n" << prime << endl;*/

    return 0;
}
