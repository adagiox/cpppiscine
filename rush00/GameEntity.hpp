#ifndef GAMEENTITY_HPP
#define GAMEENTITY_HPP

class GameEntity
{
	protected:
		char entityChar;
		int yPos, xPos;
		bool alive;
		GameEntity(char entityChar);
		GameEntity(const GameEntity &src);
		char getEntityChar();
		void moveEntity(int y, int x);
		void setPos(int y, int x);
		void getPos(int *y, int *x);
};

#endif