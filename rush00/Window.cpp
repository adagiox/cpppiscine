#include "Window.hpp"

Window::Window() {}
Window::~Window() {}

Window::Window(const Window &src)
{
	this->windowWidth = src.windowWidth;
	this->windowHeight = src.windowHeight;
}

Window &Window::operator=(const Window &rhs)
{
	if (this != &rhs)
	{
		this->windowWidth = rhs.windowWidth;
		this->windowHeight = rhs.windowHeight;
	}
	return *this;
}

int Window::getWindowWidth() { return windowWidth; }
int Window::getWindowHeight() { return windowHeight; }
void Window::setWindowWidth(int width) { this->windowWidth = width; }
void Window::setWindowHeight(int height) { this->windowHeight = height; }

void Window::init()
{
	initscr();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	clear();
	refresh();
	int w, h;
	getmaxyx(stdscr, h, w);
	setWindowWidth(w);
	setWindowHeight(h);
	printw("W: %i\tH: %i\n", this->windowWidth, this->windowHeight);
	refresh();
	usleep(5000000);
}

void Window::cleanup()
{
	clear();
	refresh();
	endwin();
}