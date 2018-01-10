#include <iostream>

class Pony
{
	private:
		std::string name;
		std::string where;
		Pony(std::string name, std::string where);
		~Pony();
	
	public:
		static void ponyOnTheHeap();
		static void ponyOnTheStack();

};
