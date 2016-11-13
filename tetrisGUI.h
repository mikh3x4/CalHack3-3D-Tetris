#ifndef _tetrisgui_h
#define _tetrisgui_h

#include <iostream>
#include "gwindow.h"

namespace tetrisGUI{

	void initialize();
	void shutdown();
	void displayBlock(int x, int y);
	void updateColor(int x, int y);

}

#endif