#ifndef BLOCK_H_
#define BLOCK_H_

#include <ctime>
#include <stdlib.h>
#include <iostream>
#include "config.h"
#include "board.h"



typedef int block_state[4][3];

class Board;
class Block {

public:
	int coords[4][3];

	Block(int);
	//returns true if successfully moved down
	bool move_down(struct Board& board);
	bool move_xy(int delta_x, int delta_y);


	void make_backup(block_state block);
	void restore_backup(block_state block);
	bool check_bounds();
	void add_to_board(struct Board& board);
	void print_coords();


};

#endif