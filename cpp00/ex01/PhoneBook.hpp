#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		void AddContact(Contact c);
		void SearchForContact(int index);
	private:
		int index;
		Contact contacts[8];
};

#endif
