#ifndef BOARD_H_
#define BOARD_H_


#include <iostream>

#include "config.h"
#include "block.h"

class Block;
class Board {

	static const int x_dim = 5;
	static const int y_dim = 5;
	static const int z_dim = 10;


public:
	bool state [z_dim][y_dim][x_dim] ;

	Board();
	void display();
	void display_with_block(Block& b);

};

#endif