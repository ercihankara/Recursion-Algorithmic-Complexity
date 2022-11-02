#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;
int dia_inc = 2;
int cntr = 0; // global counter for solver

// TRY TO MAKE DISCS AS PARENT OF HANOI OR VICE VERSA

/* class to model discs with varying diameters,
   an increase of 2 units is used starting from 1
   (arrangeable, private) */

/*
class discs
{
    private:
        int num_of_discs;
        int dia_inc = 2;
        // disc_arr keeps the discs with respect to their diameters
        int disc_arr[];

    public:
        // the constructor for the class
        discs(int num = 1);
        // get the disc with the desired diameter
        int get_discs(int indx) const;
        // get the number of disc
        int get_num_discs() const;
};
*/

/////////////// class declarations ///////////////

class disc
{
    private:
        // diameter of the disc
        int diameter;

    public:
        // the constructor for the class
        disc(int diam = 1);
        // get the diameter of the disc
        int get_diameter() const;
        // get the number of disc
        void set_diameter(int diam);
};

class Hanoi{
    private:
        int rod0[20] = {0};
        int rod1[20] = {0};
        int rod2[20] = {0};
        int num_discs;

    public:
        int aux, fin, init = 0;
        disc Discs[];
        // the constructor for the class to initialize the game
        Hanoi(int num);
        int * get_rods(int rod_index);
        int get_last_nonzero_index(int rod_index);
        int get_num_of_discs() const;
        void set_aux_fin();   // function necessary for solver
        void move(int from, int to);

};

/////////////// independent functions ///////////////
// get index of the last nonzero term of an array
int nonzero_index(int* arr)
{
    int arr_size = 20;
	for(int i = arr_size-1; i >= 0; i--)
	{
		if(arr[i] != 0)
			return i;
        else if (i == 0) // if empty rod
            return -1;
	}
}
// swap values of two integers
void swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

/////////////// functions for disc class ///////////////
// set the discs using diameters, constructor for the class
disc::disc(int diam){
    diameter = diam;
}

// get the diameter of the disc
int disc::get_diameter() const{
    return diameter;
}

// set the diameter of the disc (if required)
void disc::set_diameter(int diam){
    diameter = diam;
}

/////////////// functions for Hanoi class ///////////////
// the constructor for Hanoi class, starter of the game
Hanoi::Hanoi(int num_of_discs){
    num_discs = num_of_discs;
    set_aux_fin(); // set aux and fin
    // create the discs with increase of two, store at an array
    for (int i = 0; i<num_of_discs; i++){
        disc temp(dia_inc*i + 1);
        Discs[i] = temp;
        /* accumulate at them at rod0 using diameters
           from small to large */
        rod0[num_of_discs - i - 1] = Discs[i].get_diameter();
    }
}

// return the rod arrays as pointers
int* Hanoi::get_rods(int rod_index){
    if (rod_index == 0)
        return rod0;
    else if (rod_index == 1)
        return rod1;
    else if (rod_index == 2)
        return rod2;
}

/* get the index of the last disc with nonzero diameter
   for the rod with desired index */
int Hanoi::get_last_nonzero_index(int rod_index){
    return nonzero_index(get_rods(rod_index));
}

int Hanoi::get_num_of_discs() const{
    return num_discs;
}

// set aux and fin for solver function
void Hanoi::set_aux_fin(){
    int num = get_num_of_discs();
    if (num%2 == 0){
        aux = 1;
        fin = 2;
    }
    else{
        aux = 2;
        fin = 1;
    }
}

void Hanoi::move(int from, int to){
    int indx, checkher = 1;
    bool available;

    // first check the indeces, then the legality of the movement
    try{
        if ((from < 3 && to < 3) && (from >= 0 && to >= 0)){
            if (get_last_nonzero_index(to) == -1)
                available = 1;
            else if (get_rods(from)[get_last_nonzero_index(from)] < get_rods(to)[get_last_nonzero_index(to)])
                available = 1;
            else{
                available = 0;
                throw checkher;
            }
        }

        else{
            available = 0;
            throw checkher;
        }
    }
    catch (int checkher) {
        cout << "move is not valid, check again \n";
    }

    if (available == 1){
    //  the move part is realized
        cout << "Disc " << get_rods(from)[get_last_nonzero_index(from)] << " is moved from Rod " << from << " to Rod " << to << endl;
        if (get_last_nonzero_index(to) != 19){  // checking whether full or not
            get_rods(to)[get_last_nonzero_index(to)+1] = get_rods(from)[get_last_nonzero_index(from)];
            get_rods(from)[get_last_nonzero_index(from)] = 0;
            /* get_rods(from)[get_last_nonzero_index(from)] gives the diameter of a disc,
               discs are called by their diameter values in my case */
        }
    }
}

/////////////// solver function ///////////////
// for n discs, the total number of required steps is 2^n - 1; not a member function
void solve_hanoi(Hanoi& game){
    // iteration wise first -> convert to recursive
    // set aux and fin by set_aux_fin function inside constructor

    game.move(game.init, game.aux);
    game.move(game.init, game.fin);
    game.move(game.aux, game.fin);
    if ((cntr > 1 && cntr < 5) || cntr%2 == 0){
        if (game.get_rods(game.init)[game.get_last_nonzero_index(game.init)] != 0){
            game.move(game.init, game.aux);
            cout << "if 1" << endl;
        }
    }
    else if (cntr%2 == 1){
        game.move(game.aux, game.init);
        cout << "if 2" << endl;
    }
    cout << cntr << endl;
    cntr += 1;

    swap(game.fin, game.aux);
    swap(game.aux, game.init);

    if (cntr == 8)  // reset the flow of conditions
        cntr = 0;
    if (game.get_last_nonzero_index(2) == game.get_num_of_discs() - 1){
        cout << "if 3" << endl;
        return;
    }
    solve_hanoi(game);   // now recursion
}
