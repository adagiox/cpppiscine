#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <ncurses.h>
#include <unistd.h>

class Window
{
	private:
		int windowWidth, windowHeight;
		WINDOW *scr;
		WINDOW *debug;
		WINDOW *gameWin;

	public:
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
};

#endif