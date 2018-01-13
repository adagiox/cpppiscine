#include "Window.hpp"
//#include ""

int main()
{
	Window *w = new Window();
	w->init();
	w->cleanup();
	return 0;
}