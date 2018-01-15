#include "Window.hpp"

Window::Window() 
{
	this->init();
}
Window::~Window() 
{
	//std::cout <<  "Window destroyed." << std::endl;
}

Window::Window(const Window &src)
{
	this->scr = src.scr;
	this->debug = src.debug;
	this->gameWin = src.gameWin;
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

void Window::printHorizBar(WINDOW *win, int row)
{
	for (int col = 0; col < this->windowWidth; col++)
		mvwprintw(win, row, col, "-");
}

void Window::init()
{
	setlocale(LC_ALL, "");
	initscr();
	noecho();
	cbreak();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	clear();
	refresh();
	int w, h;
	getmaxyx(stdscr, h, w);
	setWindowWidth(w);
	setWindowHeight(h);
	this->scr = stdscr;
	this->debug = newwin(2, this->windowWidth, 0, 0);
	this->gameWin = newwin(this->windowHeight - 2, this->windowWidth, 3, 0);
	printHorizBar(debug, 1);
	mvwprintw(debug, 0, this->getWindowWidth()/2 + this->getWindowWidth()/3, 
			"W: %i  H: %i", this->windowWidth, this->windowHeight);
	wrefresh(debug);
	refresh();
	usleep(500000);
}

void Window::cleanup()
{
	clear();
	refresh();
	endwin();
}