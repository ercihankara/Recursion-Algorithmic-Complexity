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
    cout << han.get_num_of_discs() << endl;
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << han.Discs[i].get_diameter() << endl;

    arr = han.get_rods(0);
    for(int i=0; i<han.get_num_of_discs(); i++)
        cout << arr[i] << endl;
    // cout << han.get_last_nonzero_index(0) << endl;



    //int prime;
    //char str[] = "ape1 ape2. \0";
    //cout << str << endl;
    //print_backwards(str);
    //prime = nth_prime(5);
    //cout << "\n" << prime << endl;
    return 0;
}
