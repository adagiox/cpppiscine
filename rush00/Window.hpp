#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <ncurses.h>
#include <unistd.h>

class Window
{
	public:
		int windowWidth, windowHeight;
		WINDOW *scr;
		WINDOW *debug;
		WINDOW *gameWin;
		Window();
		~Window();
		Window(const Window &src);
		Window &operator=(const Window &rhs);
		void init();
		void cleanup();
		int getWindowWidth();
		int getWindowHeight();
		void setWindowWidth(int width);
		void setWindowHeight(int height);
		void printBar(WINDOW *win);
};

#endif