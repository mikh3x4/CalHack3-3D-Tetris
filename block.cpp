#include "block.h"

Block::Block(int type){

	switch (type) {
	case 0:
	  coords[0][0] = Z_DIM-1 ; coords[0][1] = 0 ; coords[0][2] = 0 ;
	  coords[1][0] = Z_DIM-1 ; coords[1][1] = 1 ; coords[1][2] = 0 ;
	  coords[2][0] = Z_DIM-1 ; coords[2][1] = 0 ; coords[2][2] = 1 ;
	  coords[3][0] = Z_DIM-1 ; coords[3][1] = 1 ; coords[3][2] = 1 ;
	  break;
	case 1:
	  coords[0][0] = Z_DIM-1 ; coords[0][1] = 0 ; coords[0][2] = 1 ;
	  coords[1][0] = Z_DIM-1 ; coords[1][1] = 0 ; coords[1][2] = 0 ;
	  coords[2][0] = Z_DIM-1 ; coords[2][1] = 0 ; coords[2][2] = 2 ;
	  coords[3][0] = Z_DIM-1 ; coords[3][1] = 0 ; coords[3][2] = 3 ;
	  break;
	case 2:
	  coords[0][0] = Z_DIM-1 ; coords[0][1] = 0 ; coords[0][2] = 1 ;
	  coords[1][0] = Z_DIM-1 ; coords[1][1] = 0 ; coords[1][2] = 0 ;
	  coords[2][0] = Z_DIM-1 ; coords[2][1] = 0 ; coords[2][2] = 2 ;
	  coords[3][0] = Z_DIM-1 ; coords[3][1] = 1 ; coords[3][2] = 1 ;
	  break;
	case 3:
	  coords[0][0] = Z_DIM-1 ; coords[0][1] = 0 ; coords[0][2] = 0 ;
	  coords[1][0] = Z_DIM-1 ; coords[1][1] = 0 ; coords[1][2] = 1 ;
	  coords[2][0] = Z_DIM-1 ; coords[2][1] = 0 ; coords[2][2] = 2 ;
	  coords[3][0] = Z_DIM-1 ; coords[3][1] = 1 ; coords[3][2] = 0 ;
	  break;
	case 4:
	  coords[0][0] = Z_DIM-1 ; coords[0][1] = 0 ; coords[0][2] = 1 ;
	  coords[1][0] = Z_DIM-1 ; coords[1][1] = 0 ; coords[1][2] = 0 ;
	  coords[2][0] = Z_DIM-1 ; coords[2][1] = 1 ; coords[2][2] = 1 ;
	  coords[3][0] = Z_DIM-1 ; coords[3][1] = 1 ; coords[3][2] = 2 ;
	  break;
	case 5:
	  coords[0][0] = Z_DIM-1 ; coords[0][1] = 0 ; coords[0][2] = 0 ;
	  coords[1][0] = Z_DIM-1 ; coords[1][1] = 0 ; coords[1][2] = 1 ;
	  coords[2][0] = Z_DIM-1 ; coords[2][1] = 1 ; coords[2][2] = 0 ;
	  coords[3][0] = Z_DIM-2 ; coords[3][1] = 0 ; coords[3][2] = 0 ;
	  break;
	case 6:
	  coords[0][0] = Z_DIM-1 ; coords[0][1] = 0 ; coords[0][2] = 0 ;
	  coords[1][0] = Z_DIM-1 ; coords[1][1] = 0 ; coords[1][2] = 1 ;
	  coords[2][0] = Z_DIM-2 ; coords[2][1] = 0 ; coords[2][2] = 0 ;
	  coords[3][0] = Z_DIM-2 ; coords[3][1] = 1 ; coords[3][2] = 0 ;
	  break;
	case 7:
	  coords[0][0] = Z_DIM-1 ; coords[0][1] = 0 ; coords[0][2] = 0 ;
	  coords[1][0] = Z_DIM-1 ; coords[1][1] = 1 ; coords[1][2] = 0 ;
	  coords[2][0] = Z_DIM-2 ; coords[2][1] = 0 ; coords[2][2] = 0 ;
	  coords[3][0] = Z_DIM-2 ; coords[3][1] = 0 ; coords[3][2] = 1 ;
	  break;
	}

	bool cont = true;
	while(cont){
		cont = !move_xy(rand() % 5,rand() % 5);
		print_coords();
	}

}


bool Block::move_down(Board& board){
	bool any = false;
	for(int block=0;block<4;block++){
		any |= board.state[coords[block][0]-1][coords[block][1]][coords[block][2]];
	}

	if (!any) {
		for(int block=0;block<4;block++){
			coords[block][0] -= 1;
		}
		return false;
	}

	return true;

}


bool Block::move_xy(int delta_x, int delta_y){

	block_state backup;

	make_backup(backup);


	for(int block=0; block < 4; block++){
		coords[block][1] += delta_y;
		coords[block][2] += delta_x;
	}

	if(check_bounds()){
		return true;
	}
	restore_backup(backup);
	return false;
}




void Block::make_backup(block_state backup){
	for(int block=0; block < 4; block++){
		for(int dim=0; dim < 3; dim++){
			backup[block][dim] = coords[block][dim];
		}
	}

}

void Block::restore_backup(block_state backup){

	for(int block=0; block < 4; block++){
		for(int dim=0; dim < 3; dim++){
			coords[block][dim] = backup[block][dim];
		}
	}
}

bool Block::check_bounds(){
	bool any = true;
	for(int block=0; block < 4; block++){
		any &= (0<=coords[block][0] && coords[block][0]<Z_DIM); 
		any &= (0<=coords[block][1] && coords[block][1]<Y_DIM); 
		any &= (0<=coords[block][2] && coords[block][2]<X_DIM); 
	}

	return any;
}

void Block::print_coords(){

	for(int block=0; block < 4; block++){
		for(int dim=0; dim < 3; dim++){
			std::cout << coords[block][dim] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void Block::add_to_board(Board& board){
	for(int block=0; block < 4; block++){
			board.state[coords[block][0]][coords[block][1]][coords[block][2]] = true;
	}
}
