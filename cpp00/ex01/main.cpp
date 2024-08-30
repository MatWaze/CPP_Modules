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
		std::cout << "Enter a command" << std::endl;
		std::cin >> cmdToEnter;
	
		if (cmdToEnter == "ADD")
		{
			std::string contactInfo[5] = {"", "", "", "", ""};
			
			std::cout << "Enter a first name" << std::endl;
			std::cin >> contactInfo[0];

			std::cout << "Enter a last name" << std::endl;
			std::cin >> contactInfo[1];

			std::cout << "Enter a  nickname" << std::endl;
			std::cin >> contactInfo[2];

			std::cout << "Enter a phone number" << std::endl;
			std::cin >> contactInfo[3];

			std::cout << "Enter a darkest secret" << std::endl;
			std::cin >> contactInfo[4];

			Contact contact;
			if (!(contactInfo[0].length() == 0 || contactInfo[1].length() == 0 || \
				contactInfo[2].length() == 0 || contactInfo[3].length() == 0 || \
				contactInfo[4].length() == 0))
			{
				contact.firstName = contactInfo[0];
				contact.lastName = contactInfo[1];
				contact.nickname = contactInfo[2];
				contact.darkestSecret = contactInfo[3];
				contact.phoneNumber = contactInfo[4];
				phoneBook.AddContact(contact);
			}
			else
				std::cout << "One of the fields is empty. Try again." << std::endl;
		}
		else if (cmdToEnter == "SEARCH")
		{
			std::string strInd;
			int ind;

			std::cout << "Enter the index of a contact" << std::endl;
			std::cin >> strInd;
			ind = stoi(strInd);
			phoneBook.SearchForContact(ind);
		}
		else if (cmdToEnter == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Invalid command. Try again." << std::endl;
		}
		// std::cout << "Index is " << phoneBook.index << std::endl;
		// for (int j = 0; j < phoneBook.index; j++)
		// {
		// 	std::cout << phoneBook.contacts[j].firstName << std::endl;
		// }
	}
	return (0);
}

// int	main(void)
// {
// 	main2();
// 	system("leaks phonebook");
// 	return (0);
// }
