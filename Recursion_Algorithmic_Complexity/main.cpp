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

class Hanoi: public discs{
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

// get the disc with desired index
int discs::get_discs(int indx) const{
    return disc_arr[indx];
}

// get the number of discs
int discs::get_num_discs() const{
    return num_of_discs;
}

/////////////// functions for Hanoi class ///////////////
Hanoi::Hanoi(){
    discs Disc(num);
}

int * Hanoi::get_rods(int rod_index){
    if (rod_index == 0){


    }
}

// be stacked by increasing diameter
int main()
{
    return 0;
}
