#include "Contact.hpp"

Contact::Contact(){};

void Contact::set_first()
{
	std::string first;
	std::cout << "Enter first name:" << std::endl;
	std::getline(std::cin, first);
	this->first = first;
}

void Contact::set_last()
{
	std::string last;
	std::cout << "Enter last name:" << std::endl;
	std::getline(std::cin, last);
	this->last = last;
}

void Contact::set_nick()
{
	std::string nick;
	std::cout << "Enter nick:" << std::endl;
	std::getline(std::cin, nick);
	this->nick = nick;
}

void Contact::set_login()
{
	std::string login;
	std::cout << "Enter login" << std::endl;
	std::getline(std::cin, login);
	this->login = login;
}

void Contact::set_address()
{
	std::string address;
	std::cout << "Enter address" << std::endl;
	std::getline(std::cin, address);
	this->address = address;
}

void Contact::set_email()
{
	std::string email;
	std::cout << "Enter email:" << std::endl;
	std::getline(std::cin, email);
	this->email = email;
}

void Contact::set_phone()
{
	std::string phone;
	std::cout << "Enter phone:" << std::endl;
	std::getline(std::cin, phone);
	this->phone = phone;
}

void Contact::set_birthday()
{
	std::string birthday;
	std::cout << "Enter birthday:" << std::endl;
	std::getline(std::cin, birthday);
	this->birthday = birthday;
}

void Contact::set_meal()
{
	std::string meal;
	std::cout << "Enter favorite meal:" << std::endl;
	std::getline(std::cin, meal);
	this->meal = meal;
}

void Contact::set_color()
{
	std::string color;
	std::cout << "Enter underwear color:" << std::endl;
	std::getline(std::cin, color);
	this->color = color;
}

void Contact::set_secret()
{
	std::string secret;
	std::cout << "Enter secret:" << std::endl;
	std::getline(std::cin, secret);
	this->secret = secret;
}

void Contact::show_full_contact()
{
	std::cout << std::setw(18) << "First Name: " << first << std::endl;
	std::cout << std::setw(18) << "Last Name: " << last << std::endl;
	std::cout << std::setw(18) << "Nickname: " << nick << std::endl;
	std::cout << std::setw(18) << "Login: " << login << std::endl;
	std::cout << std::setw(18) << "Address: " << address << std::endl;
	std::cout << std::setw(18) << "Email: " << email << std::endl;
	std::cout << std::setw(18) << "Phone: " << phone << std::endl;
	std::cout << std::setw(18) << "Birthday: " << birthday << std::endl;
	std::cout << std::setw(18) << "Favorite Meal: " << meal << std::endl;
	std::cout << std::setw(18) << "Underwear Color: " << color << std::endl;
	std::cout << std::setw(18) << "Secret: " << secret << std::endl;
}

void Contact::show_contact(int i)
{
	std::cout << std::setw(10) << i << "|";
	if (first.length() > 10)
		std::cout << first.substr(0,9) << ".|";
	else
		std::cout << std::setw(10) << first << "|";
	if (last.length() > 10)
		std::cout << last.substr(0,9) << ".|";
	else
		std::cout << std::setw(10) << last << "|";
	if (nick.length() > 10)
		std::cout << nick.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << nick << "|";
	std::cout << std::endl;
}

Contact::~Contact(){};