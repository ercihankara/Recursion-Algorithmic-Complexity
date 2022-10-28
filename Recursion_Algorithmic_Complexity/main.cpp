#include <iostream>
#include <cstdlib>
#include "Recursion&Algorithmic_Complexity.h"
#include "print_backwards.h"
#include "nth_prime.h"

using namespace std;

int main()
{
    int prime;
    char str[] = "ape1 ape2. \0";
    cout << str << endl;
    print_backwards(str);
    prime = nth_prime(5);
    cout << "\n" << prime << endl;
    return 0;
}
