/////////////// functions for Hanoi class ///////////////
#include "Hanoi.h"

int dia_inc = 2; // global parameter for the diameter arrangements


// helper function

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

// the constructor for Hanoi class, starter of the game
Hanoi::Hanoi(int num_of_discs){
    num_discs = num_of_discs;
    set_aux_fin(); // set aux and fin
    // create the discs with increase of two, store at an array
    for (int i = 0; i<num_of_discs; i++){
        Disc temp(dia_inc*i + 1);
        discs[i] = temp;
        /* accumulate at them at rod0 using diameters
           from small to large */
        rod0[num_of_discs - i - 1] = discs[i].get_diameter();
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
    aux = 1;
    fin = 2;
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
