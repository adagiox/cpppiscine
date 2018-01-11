#include "Human.hpp"

const Brain &Human::getBrain() { return b; }
std::string Human::identify() { return b.identify(); }