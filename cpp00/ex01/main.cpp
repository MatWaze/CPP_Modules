#include <iostream>
#include <string>
#include "PhoneBook.hpp"
	
int	main(void)
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
			// if (!(contactInfo[0].length() == 0 || contactInfo[1].length() == 0 || \
			// 	contactInfo[2].length() == 0 || contactInfo[3].length() == 0 || \
			// 	contactInfo[4].length() == 0))
			// {
			contact.firstName = contactInfo[0];
			contact.lastName = contactInfo[1];
			contact.nickname = contactInfo[2];
			contact.darkestSecret = contactInfo[3];
			contact.phoneNumber = contactInfo[4];
			phoneBook.AddContact(contact);
			// }
			// else
				// std::cout << "One of the fields is empty. Try again." << std::endl;
		}
		else if (cmdToEnter == "SEARCH")
		{
			std::string strInd;
			int ind;

			std::cout << "Enter the index of a contact: ";
			std::cin >> strInd;
			if (std::cin.eof() == true)
				break ;
				
			ind = stoi(strInd);
			phoneBook.SearchForContact(ind);
		}
		else
		{
			std::cout << "Invalid command. Try again." << std::endl;
		}
	}
	return (0);
}

// int	main(void)
// {
// 	main2();
// 	system("leaks phonebook");
// 	return (0);
// }
