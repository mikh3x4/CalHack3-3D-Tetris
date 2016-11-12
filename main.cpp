
// #include <vector.h>
#include <iostream>

using namespace std;

class Board{

	static const x_dim = 5;
	static const y_dim = 5;
	static const z_dim = 10;


public:
	bool state [z_dim][y_dim][x_dim] ;

	Board ();

};

Board::Board(){

	for(int z=0;z<z_dim;z++){
		for(int y=0;y<y_dim;y++){
			for(int x=0;x<x_dim;x++){
				state[z][y][x] = false;
			}
		}
	}

	

}


// class Block{



// 	Vector<int> coords[4];

// 	//returns true if successfully moved down
// 	bool move_down(Board& board){


// 	}

// };


int main(){

	Board b;

	if (b.state[5][0][0]){
		cout << "true";
	}else{
		cout << "false";
	}
	// cout << b.state[5][0][0] << endl;

	return 0;
}