#include "Game.hpp"

Game::Game() : maxEnemies(20), maxBullets(5) 
{
	std::srand(std::time(0));
	this->window = new Window();
	this->player = new Player();
	this->player->setPos(this->window->windowHeight/2, 
		this->window->windowWidth/6);
	mvwaddch(this->window->gameWin, this->player->yPos,
		this->player->xPos, this->player->entityChar);
	this->enemies = new Enemy[this->maxEnemies];
	for (int i = 0; i < this->maxEnemies; i++)
		this->enemies[i].setNumber(i+1);
	this->bullets = new Bullet[this->maxBullets];
}
Game::~Game() { this->window->cleanup(); }

Game::Game(const Game &src)
{
	this->window = src.window;
	//this->entityManager = src.entityManager;
	this->player = src.player;
	// this->enemies = src.enemies;
}

Game &Game::operator=(const Game &rhs)
{
	if (this != &rhs)
	{
		this->window = rhs.window;
		//this->entityManager = rhs.entityManager;
		this->player = rhs.player;
		// this->enemies = rhs.enemies;
	}
	return *this;
}

void Game::spawnEnemy()
{
	Enemy *next;
	if ((next = this->getNextEnemy()) != NULL)
	{
		if (rand() % 10 == 0)
		{
			next->isVisible = true;
			int enemyYPos = rand() % (this->window->windowHeight - 5);
			mvwaddch(this->window->gameWin, enemyYPos,
				this->window->windowWidth - 1, next->entityChar);
			next->setPos(enemyYPos, this->window->windowWidth - 1);
		}
	}
}

Enemy *Game::getNextEnemy()
{
	Enemy *next = NULL;
	for (int i = 0; i < maxEnemies; i++)
	{
		if (this->enemies[i].isVisible == false)
		{
			next = &this->enemies[i];
			return next;
		}
	}
	return next;
}

Bullet *Game::getNextBullet()
{
	Bullet *next = NULL;
	for (int i = 0; i < maxBullets; i++)
	{
		if (this->bullets[i].isVisible == false)
		{
			next = &this->bullets[i];
			return next;
		}
	}
	return next;
}

void Game::getInput()
{
	int c;
	if ((c = wgetch(this->window->gameWin)) == ERR)
		return;
	std::string clear = "       ";
	std::string ustr = "Up";
	std::string dstr = "Down";
	std::string sstr = "Space";
	switch(c)
	{
		case KEY_UP:
			this->window->printDebug(clear.c_str());
			this->window->printDebug(ustr.c_str());
			this->moveUp();
			break;
		case KEY_DOWN:
			this->window->printDebug(clear.c_str());
			this->window->printDebug(dstr.c_str());
			this->moveDown();
			break;
		case ' ':
			this->window->printDebug(clear.c_str());
			this->window->printDebug(sstr.c_str());
			this->shoot();
			break;
		default:
			break;
	}
}

void Game::processEvents() 
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (this->bullets[i].isVisible == true)
		{
			// get the pos in front of the bullet and check if enemy
			char ch = (char)mvwinch(this->window->gameWin, this->bullets[i].yPos, 
				this->bullets[i].xPos + 1);
			if (ch == 'C' || ch == 'D' || ch == 'E')
			{
				// kill enemy
				mvwaddch(this->window->gameWin, this->bullets[i].yPos,
					this->bullets[i].xPos + 1, ' ');
				this->bullets[i].isVisible = false;
				this->bullets[i].alive = false;
				mvwaddch(this->window->gameWin, this->bullets[i].yPos, 
					this->bullets[i].xPos, ' ');
			}
			else if (this->bullets[i].xPos >= this->window->windowWidth)
			{
				this->bullets[i].isVisible = false;
				this->bullets[i].alive = false;
				mvwaddch(this->window->gameWin, this->bullets[i].yPos, 
					this->bullets[i].xPos, ' ');
			}
			else
			{
				mvwaddch(this->window->gameWin, this->bullets[i].yPos, 
					this->bullets[i].xPos, ' ');
				mvwaddch(this->window->gameWin, this->bullets[i].yPos, 
					this->bullets[i].xPos + 1, this->bullets[i].entityChar);
				this->bullets[i].setPos(this->bullets[i].yPos, 
					this->bullets[i].xPos + 1);
			}
		}
	}
	for (int i = 0; i < maxEnemies; i++)
	{
		if (this->enemies[i].isVisible == true)
		{
			// check if current loc is a space or an enemy char
			char ch = (char)mvwinch(this->window->gameWin, this->enemies[i].yPos, 
				this->enemies[i].xPos);
			char fch = (char)mvwinch(this->window->gameWin, this->enemies[i].yPos, 
				this->enemies[i].xPos - 1);
			if (ch == 'C' || ch == 'D' || ch == 'E')
			{
				if (fch == '>') 
				{
					// player collision
					std::string s = "G A M E      O V E R";
					int len = s.length();
					mvwprintw(this->window->scr, this->window->windowHeight/2,
						this->window->windowWidth/2 - len, s.c_str());
					usleep(1000000);
					this->window->cleanup();
					exit(0);
				}
				// move enemy
				mvwaddch(this->window->gameWin, this->enemies[i].yPos, 
					this->enemies[i].xPos, ' ');
				mvwaddch(this->window->gameWin, this->enemies[i].yPos, 
					this->enemies[i].xPos - 1, this->enemies[i].entityChar);
				this->enemies[i].setPos(this->enemies[i].yPos,
					this->enemies[i].xPos - 1);
			}
			else
			{
				// enemy was shot
				this->enemies[i].isVisible = false;
				this->enemies[i].alive = false;
			}
		}
	}
	this->spawnEnemy();
}

void Game::refreshScreen() { this->window->refreshWin(); }

void Game::moveUp()
{
	if (this->player->yPos - 1 > 0)
	{
		mvwaddch(this->window->gameWin, this->player->yPos, 
			this->player->xPos, ' ');
		mvwaddch(this->window->gameWin, this->player->yPos - 1, 
			this->player->xPos, this->player->entityChar);
		this->player->setPos(this->player->yPos - 1, 
			this->player->xPos);
	}
}

void Game::moveDown()
{	
	if (this->player->yPos + 1 < this->window->windowHeight - 5)
	{
		mvwaddch(this->window->gameWin, this->player->yPos, 
			this->player->xPos, ' ');
		mvwaddch(this->window->gameWin, this->player->yPos + 1, 
			this->player->xPos, this->player->entityChar);
		this->player->setPos(this->player->yPos + 1, 
			this->player->xPos);
	}
}

void Game::shoot()
{
	Bullet *shot;
	if ((shot = this->getNextBullet()) != NULL)
	{
		shot->isVisible = true;
		shot->alive = true;
		mvwaddch(this->window->gameWin, this->player->yPos, 
			this->player->xPos + 1, shot->entityChar);
		shot->setPos(this->player->yPos, 
			this->player->xPos + 1);
	}
}
