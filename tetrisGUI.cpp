
#include <iostream>
#include "tetrisGUI.h"
#include "gwindow.h"
#include "vector.h"
using namespace std;

namespace BoggleGUI {

    static const int WINDOW_WIDTH = 500;
    static const int WINDOW_HEIGHT = 500;
    static const int numSideBlocksX = 5;
    static const int numSideBlocksY = 5;
    static const int BOARD_COLOR = 0xADD8E6;

    static GWindow* window = NULL;

    void initialize(){
    	window = new GWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    	window->setWindowTitle("3D Tetris");
    	window->setExitOnClose(true);
    	window->setColor(BOARD_COLOR);
    	int blockWidth = WINDOW_WIDTH / numSideBlocksX;
    	int blockHeight = WINDOW_HEIGHT / numSideBlocksY;
    	for(int i = 1; i < numSideBlocksX; i++){
    		window->drawLine(i * blockWidth, 0, i * blockWidth, window->getHeight());
    	}
    	for(int i = 1; i < numSideBlocksY; i++){
    		window->drawLine(0, i * blockHeight, window->getWidth(), i * blockHeight);
    	}
    }

    void displayBlock(int x, int y){

    }

    void updateColor(int x, int y){
    	
    }

}
