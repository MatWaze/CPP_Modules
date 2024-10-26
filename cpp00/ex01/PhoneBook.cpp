#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <ios>
#include <iostream>
			
void PhoneBook::AddContact(Contact c)
{
	if (index < 2)
		contacts[index++] = c;
	else if (index == 2)
		contacts[1] = c;
}

void PhoneBook::SearchForContact(int ind)
{
	if (ind >= 0 && ind < index)
	{
		Contact c = contacts[ind];
		std::cout << std::setw(10) << std::right << ind << "|";
		if (c.getName().length() < 10)
			std::cout << std::setw(10) << std::right << c.getName() << "|";
		else
			std::cout << std::setw(10) << std::right << c.getName().substr(0, 9) + "." << "|";
		
		if (c.getLastName().length() < 10)
			std::cout << std::setw(10) << std::right << c.getLastName() << "|";
		else
			std::cout << std::setw(10) << std::right << c.getLastName().substr(0, 9) + "." << "|";
			
		if (c.getNickname().length() < 10)
			std::cout << std::setw(10) << std::right << c.getNickname() << "|";
		else
			std::cout << std::setw(10) << std::right << c.getNickname().substr(0, 9) + "." << "|";
			
		if (c.getPhone().length() < 10)
			std::cout << std::setw(10) << std::right << c.getPhone() << "|";
		else
			std::cout << std::setw(10) << std::right << c.getPhone().substr(0, 9) + "." << "|";
			
		if (c.getSecret().length() < 10)
			std::cout << std::setw(10) << std::right << c.getSecret() << "|" << std::endl;
		else
			std::cout << std::setw(10) << std::right << c.getSecret().substr(0, 9) + "." << "|" << std::endl;
	}
	else
	{
		std::cout << "Index out of range. Try again." << std::endl;
	}
}
