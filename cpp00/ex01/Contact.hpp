#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		std::string getName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhone();
		std::string getSecret();
		void setName(std::string name);
		void setLastName(std::string lastName);
		void setNickname(std::string nickname);
		void setPhone(std::string phoneNumber);
		void setSecret(std::string secret);
};

#endif
