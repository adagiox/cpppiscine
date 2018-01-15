#ifndef GAMEENTITY_HPP
#define GAMEENTITY_HPP

#include <iostream>
#include <ncurses.h>

class GameEntity
{
	public:
		int yPos, xPos;
		void setPos(int y, int x);
		char entityChar;
		bool alive;
		GameEntity(char entityChar);
		GameEntity(const GameEntity &src);
		char getEntityChar();
		void setEntityChar(char c);
		void moveEntity(int y, int x);
		void getPos(int *y, int *x);
};

#endif