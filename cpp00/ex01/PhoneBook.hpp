#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		// PhoneBook(void);
		// ~PhoneBook(void);
		int index;
		Contact contacts[8];
		void AddContact(Contact c);
		void SearchForContact(int index);
};

#endif
