
// #include <vector.h>
#include <iostream>
#include <ctime>

#include "config.h"

#include "board.h"
#include "block.h"





using namespace std;


int main(){
	srand(time(NULL));


	Board b;

	b.display();

	cout << endl;

	Block a(rand() % 8);
	b.display_with_block(a);


	a.print_coords();
}


