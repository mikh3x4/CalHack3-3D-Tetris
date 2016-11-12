
// #include <vector.h>
#include <iostream>

using namespace std;

class Board{

	static const int x_dim = 5;
	static const int y_dim = 5;
	static const int z_dim = 10;


public:
	bool state [z_dim][y_dim][x_dim] ;

	Board ();
	display();

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


Board::display(){

	int out[x_dim][y_dim];

	for(int y=0;y<y_dim;y++){
		for(int x=0;x<x_dim;x++){

			int z=z_dim-1;

			while (!state[z][y][x] && z>0){
				z-=1;
			}
			out[x][y]=z;

		}
	}

	//print out nicely

}


class Block{



	vector<int> coords[4];

	//returns true if successfully moved down
	bool move_down(Board& board){


	}

};


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