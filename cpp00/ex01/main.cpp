#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

bool	isStrNumeric(std::string str)
{
	bool	ans = true;
	size_t	i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	for (; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			ans = false;
			break ;
		}
	}
	return ans;
}

Contact	getContact(std::string (&contactInfo)[5])
{
	Contact	contact;
	
	contact.setName(contactInfo[0]);
	contact.setLastName(contactInfo[1]);
	contact.setNickname(contactInfo[2]);
	contact.setSecret(contactInfo[3]);
	contact.setPhone(contactInfo[4]);
	return contact;
}

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc == 1)
	{
		std::string cmdToEnter = "";
		std::string contactToEnter;

		PhoneBook phoneBook;
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
					
				Contact cntct = getContact(contactInfo);
				phoneBook.AddContact(cntct);
			}
			else if (cmdToEnter == "SEARCH")
			{
				std::string strInd;
				long ind;
				std::cout << "Enter the index of a contact: ";
				std::cin >> strInd;
				if (std::cin.eof() == true)
					break ;

				if (strInd.length() <= 12 && (ind = atol(strInd.c_str())) <= INT_MAX && ind >= INT_MIN && isStrNumeric(strInd))
				{
					std::cout << "ind: " << ind << std::endl;
					phoneBook.SearchForContact(ind);
				}
				else
					std::cout << "Not int. Try again." << std::endl;
			}
			else
				std::cout << "Invalid command. Try again." << std::endl;
		}
	}
	else
		std::cerr << "Program doesn't accept any parameters" << std::endl;
	return (0);
}
