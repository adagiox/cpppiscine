#include "Window.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <signal.h>

void sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		clear();
		refresh();
		endwin();
		std::cout << "Aborting..." << std::endl;
		exit(1);
	}
}

int main()
{
	signal(SIGINT, sig_handler);
	Game g;
	return 0;
}