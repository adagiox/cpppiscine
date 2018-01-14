#include "GameEntity.hpp"

GameEntity::GameEntity(char entityChar) : entityChar(entityChar), alive(true) {}
GameEntity::GameEntity(const GameEntity &src) { this->entityChar = src.entityChar; }
char GameEntity::getEntityChar() { return entityChar; }

void GameEntity::moveEntity(int y, int x)
{
	y = this->yPos;
	x = this->xPos;
}

void GameEntity::setPos(int y, int x)
{
	this->yPos = y;
	this->xPos = x;
}

void GameEntity::getPos(int *y, int *x)
{
	*y = this->yPos;
	*x = this->xPos;
}