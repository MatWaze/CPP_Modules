#include <iostream>
#include "PhoneBook.hpp"
		
int	main(int argc, char **argv)
{
	(void) argv;
	if (argc == 1)
	{
		std::string cmdToEnter = "";
		std::string contactToEnter;

		PhoneBook phoneBook;
		phoneBook.index = 0;
		while (cmdToEnter != "EXIT")
		{
			std::cout << "Enter a command: ";
			std::cin >> cmdToEnter;
		
			if (std::cin.eof() == true || cmdToEnter == "EXIT")
				break ;
			else if (cmdToEnter == "ADD")
			{
				std::string contactInfo[5] = {"", "", "", "", ""};

				std::cout << "Enter a first name: ";
				std::cin >> contactInfo[0];
				if (std::cin.eof() == true)
					break ;
					
				std::cout << "Enter a last name: ";
				std::cin >> contactInfo[1];
				if (std::cin.eof() == true)
					break ;
					
				std::cout << "Enter a nickname: ";
				std::cin >> contactInfo[2];
				if (std::cin.eof() == true)
					break ;
				
				std::cout << "Enter a phone number: ";
				std::cin >> contactInfo[3];

				std::cout << "Enter a darkest secret: ";
				std::cin >> contactInfo[4];
				if (std::cin.eof() == true)
					break ;
					
				Contact contact;

				contact.firstName = contactInfo[0];
				contact.lastName = contactInfo[1];
				contact.nickname = contactInfo[2];
				contact.darkestSecret = contactInfo[3];
				contact.phoneNumber = contactInfo[4];
				phoneBook.AddContact(contact);
			}
			else if (cmdToEnter == "SEARCH")
			{
				std::string strInd;
				int ind;

				std::cout << "Enter the index of a contact: ";
				std::cin >> strInd;
				if (std::cin.eof() == true)
					break ;
				try
				{
					ind = stoi(strInd);
					phoneBook.SearchForContact(ind);
				}
				catch (std::out_of_range& e)
				{
					std::cerr << "Exception caught: " << e.what()
					<< std::endl;
					break ;
				}
				catch (std::invalid_argument& e)
				{
					std::cerr << "Exception caught: " << e.what()
					<< std::endl;
					break ;
				}
			}
			else
				std::cout << "Invalid command. Try again." << std::endl;
		}
	}
	else
		std::cerr << "Program doesn't accept any parameters" << std::endl;
	return (0);
}
