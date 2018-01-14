#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player : public GameEntity
{
	private:
		

	public:
		Player();
		~Player();
		Player(const Player &src);
		Player &operator=(const Player &rhs);
};

#endif