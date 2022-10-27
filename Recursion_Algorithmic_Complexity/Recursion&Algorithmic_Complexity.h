#include <iostream>
#include <cstdlib>

using namespace std;

/* class to model discs with varying diameters,
   an increase of 2 units is used starting from 1
   (arrangeable, private) */
class discs
{
    private:
        int num_of_discs;
        int dia_inc = 2;
        // disc_arr keeps the discs with respect to their diameters
        int disc_arr[];

    public:
        // the constructor for the class
        discs(int num);
        // get the disc with the desired diameter
        int get_discs(int indx) const;
        // get the number of disc
        int get_num_discs() const;
};

class Hanoi{
    private:
        int rod0[20] = {0};
        int rod1[20] = {0};
        int rod2[20] = {0};
        // discs Disc(); // ??

    public:
        // the constructor for the class to initialize the game
        Hanoi(int num);
        // reach the rods with the index
        int * get_rods(int rod_index);
        int get_last_nonzero_index(int rod_index);
        void move(int from, int to);

};

/////////////// functions for discs class ///////////////
// set the discs using diameters
discs::discs(int num){
    num_of_discs = num;
    for(int i = 0; i<num; i++){
        disc_arr[i] = i*dia_inc + 1;
    }
}

// get the disc with desired index (diameter = index*dia_inc + 1) -> UNUSED
int discs::get_discs(int indx) const{
    return disc_arr[indx];
}

// get the number of discs -> UNUSED
int discs::get_num_discs() const{
    return num_of_discs;
}

// get index of the last nonzero term of an array
int nonzero_index(int* arr)
{
    int arr_size = 20;
	for(int i = arr_size-1; i>=0 ; i--)
	{
		if(arr[i] != 0)
			return i;
	}
}

/////////////// functions for Hanoi class ///////////////
// the constructor for Hanoi class ????
Hanoi::Hanoi(){
    discs Disc(num);
}

// return the rod arrays as pointers
int * Hanoi::get_rods(int rod_index){
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

void Hanoi::move(int from, int to){
    int checkher = 1;
    bool available;

    // first check the indeces, then the legality of the movement
    try{
        if ((from < 3 && to < 3) && (from > 0 && to > 0)){
            if (get_rods(from)[get_last_nonzero_index(from)] > get_rods(to)[get_last_nonzero_index(to)])
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
    // the move part is realized
        if (get_last_nonzero_index(to)+1 != 20){
            get_rods(to)[get_last_nonzero_index(to)+1] = get_rods(from)[get_last_nonzero_index(from)];
            get_rods(from)[get_last_nonzero_index(from)] = 0;
            /* get_rods(from)[get_last_nonzero_index(from)] gives the diameter of a disc,
               discs are called by their diameter values in my case */
            cout << "Disc " << get_rods(from)[get_last_nonzero_index(from)] << "is moved from Rod " << from << "to Rod " << to << endl;
        }
    }
}

// be stacked by increasing diameter
