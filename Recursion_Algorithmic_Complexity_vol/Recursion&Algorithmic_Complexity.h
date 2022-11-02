#include <iostream>
#include <cstdlib>

using namespace std;
int dia_inc = 2;

// TRY TO MAKE DISCS AS PARENT OF HANOI OR VICE VERSA

/* class to model discs with varying diameters,
   an increase of 2 units is used starting from 1
   (arrangeable, private) */

/////////////// class declarations ///////////////
class Disc
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
        int temp_num;
        disc Discs[]; // d->D
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
    temp_num = num_of_discs;
    set_aux_fin(); // set aux and fin
    // create the discs with increase of two, store at an array
    for (int i = 0; i<num_of_discs; i++){
        disc temp(dia_inc*i + 1);
        Discs[i] = temp;
        /* accumulate at them at rod0 using diameters
           from small to large */
        rod0[num_of_discs - i - 1] = Discs[i].get_diameter();
    }
    cout << temp_num;
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
        aux = 1;
        fin = 2;
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
