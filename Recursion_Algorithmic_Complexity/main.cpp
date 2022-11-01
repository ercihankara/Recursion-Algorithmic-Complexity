#include <iostream>
#include <cstdlib>
#include "Recursion&Algorithmic_Complexity.h"
#include "print_backwards.h"
#include "nth_prime.h"

using namespace std;

int main()
{
    Hanoi han(7);
    int* arr;
    int indx, indx0, indx1, indx2;
    cout << han.get_num_of_discs() << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.Discs[i].get_diameter() << endl;

    indx = han.get_last_nonzero_index(0);
    cout << indx << endl;

    han.move(0, 1);
    han.move(0, 1);

    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.get_rods(0)[i] << endl;
    cout << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.get_rods(1)[i] << endl;



    //int prime;
    //char str[] = "ape1 ape2. \0";
    //cout << str << endl;
    //print_backwards(str);
    //prime = nth_prime(5);
    //cout << "\n" << prime << endl;
    return 0;
}
