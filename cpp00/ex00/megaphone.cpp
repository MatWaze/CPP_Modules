#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>

class Megaphone
{
	public:
		void printUpper(std::string sentence)
		{
			if (sentence.length() != 0)
			{
				for (unsigned long i = 0; i < sentence.length(); i++)
					std::cout << (char) std::toupper(sentence[i]);
				std::cout << std::endl;
			}
			else
				std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		}
};

int	main(int argc, char **argv)
{
	Megaphone var;
	std::string str = "";

	for (int i = 1; i < argc; i++)
		str += argv[i];
	var.printUpper(str);
	return (0);
}
