#include <iostream>
#include <iomanip>

class Contact
{
	public:
		std::string first, last, nick, login, address, email, phone, birthday, meal, color, secret;
		Contact();
		void set_first();
		void set_last();
		void set_nick();
		void set_login();
		void set_address();
		void set_email();
		void set_phone();
		void set_birthday();
		void set_meal();
		void set_color();
		void set_secret();
		void show_contact(int i);
		void show_full_contact();
		~Contact();
};