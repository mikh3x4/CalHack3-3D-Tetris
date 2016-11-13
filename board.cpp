
#include "board.h"


Board::Board(){

	for(int z=0; z < Z_DIM;z++){
		for(int y=0; y < Y_DIM;y++){
			for(int x=0; x < X_DIM;x++){
				state[z][y][x] = false;
			}
		}
	}
}


void Board::display(){

	for(int y=0; y < Y_DIM; y++){
		for(int x=0; x < X_DIM; x++){

			int z=Z_DIM-1;

			while (!state[z][y][x] && z>0){
				z-=1;
			}
			std::cout << z;
			std::cout << " ";
		}
		std::cout << std::endl;
	}

}


void Board::display_with_block(Block& b){

	for(int y=0; y < Y_DIM; y++){
		for(int x=0; x < X_DIM; x++){

			int z=Z_DIM-1;

			while (!state[z][y][x] && z>0){
				z-=1;
			}
			std::cout << z;

			bool any = false;

			for(int block=0; block < 4; block++){
				any |= (b.coords[block][1] == y && b.coords[block][2] == x);
			}

			if(any){
				std::cout << "|";
			}else{

				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}

}