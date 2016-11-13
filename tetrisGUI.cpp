
#include <iostream>
#include "tetrisGUI.h"
#include "gwindow.h"
#include "vector.h"

#include "gobjects.h"

using namespace std;

namespace BoggleGUI {

    static const int WINDOW_WIDTH = 500;
    static const int WINDOW_HEIGHT = 500;
    static const int numSideBlocksX = 5;
    static const int numSideBlocksY = 5;
    static const int BOARD_COLOR = 0xADD8E6;

    static const int colors[] = {0x000000,0x333333,0x4D4D4D,0x666666,0x7F7F7F,0x999999,0xB3B3B3,0xCCCCCC,0xE5E5E5,0xFFFFFF};
    Vector<*GRect> vec;


    static GWindow* window = NULL;

    void initialize(){

        window = new GWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
        window->setVisible(true);
        window->setWindowTitle("3D Tetris");
        window->setExitOnClose(true);
        window->setColor(BOARD_COLOR);
        int blockWidth = WINDOW_WIDTH / numSideBlocksX;
        int blockHeight = WINDOW_HEIGHT / numSideBlocksY;
        for(int i = 0; i < numSideBlocksX; i++){
        	for(int j = 0; j < numSideBlocksY; j++){
        		GRect *rec = new GRect rec(i * blockWidth, j * blockHeight, blockWidth, blockHeight);
        		rec->setFilled(true);
        		rec->setFillColor(BOARD_COLOR);
        		window->add(*rec);
        		vec.add(rec);
        	}
        }
        for(int i = 1; i < numSideBlocksX; i++){
        	GLine line(i * blockWidth, 0, i * blockWidth, window->getHeight());
            add(line);
        }
        for(int i = 1; i < numSideBlocksY; i++){
        	GLine line(0, i * blockHeight, window->getWidth(), i * blockHeight);
            add(line);
        }
    }

    void displayBlock(int x, int y){
        GRect *rec = vec.get(x * numSideBlocksY + y);
        rec->setFillColor(colors[9]);
    }

    void updateColor(int x, int y, int z){
    	GRect *rec = vec.get(x * numSideBlocksY + y);
        rec->setFillColor(colors[z]);

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
