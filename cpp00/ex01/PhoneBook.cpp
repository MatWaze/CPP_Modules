#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstddef>
#include <iomanip>
#include <ios>
#include <iostream>
	
void PhoneBook::AddContact(Contact c)
{
	if (index < 8)
		contacts[index++] = c;
	else if (index == 8)
		contacts[7] = c;
}

void PhoneBook::SearchForContact(int ind)
{
	if (ind < index)
	{
		Contact c = contacts[ind];
		std::cout << std::setw(10) << std::right << ind << "|";
		if (c.firstName.length() < 10)
			std::cout << std::setw(10) << std::right << c.firstName << "|";
		else
			std::cout << std::setw(10) << std::right << c.firstName.substr(0, 9) + "." << "|";
		
		if (c.lastName.length() < 10)
			std::cout << std::setw(10) << std::right << c.lastName << "|";
		else
			std::cout << std::setw(10) << std::right << c.lastName.substr(0, 9) + "." << "|";
			
		if (c.nickname.length() < 10)
			std::cout << std::setw(10) << std::right << c.nickname << "|";
		else
			std::cout << std::setw(10) << std::right << c.nickname.substr(0, 9) + "." << "|";
			
		if (c.phoneNumber.length() < 10)
			std::cout << std::setw(10) << std::right << c.phoneNumber << "|";
		else
			std::cout << std::setw(10) << std::right << c.phoneNumber.substr(0, 9) + "." << "|";
			
		if (c.darkestSecret.length() < 10)
			std::cout << std::setw(10) << std::right << c.darkestSecret << "|" << std::endl;
		else
			std::cout << std::setw(10) << std::right << c.darkestSecret.substr(0, 9) + "." << "|" << std::endl;
	}
	else
	{
		std::cout << "Index out of range. Try again." << std::endl;
	}
}
