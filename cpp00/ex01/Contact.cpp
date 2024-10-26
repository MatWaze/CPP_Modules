#include "Contact.hpp"

std::string Contact::getLastName()
{
	return this->lastName;
}

std::string Contact::getName()
{
	return this->firstName;
}

std::string Contact::getNickname()
{
	return this->nickname;
}

std::string Contact::getPhone()
{
	return this->phoneNumber;
}

std::string Contact::getSecret()
{
	return this->darkestSecret;
}

void Contact::setName(std::string name)
{
	this->firstName = name;
}

void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void Contact::setSecret(std::string secret)
{
	this->darkestSecret = secret;
}

void Contact::setPhone(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}
