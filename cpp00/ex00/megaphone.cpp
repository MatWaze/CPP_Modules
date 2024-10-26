#include <iostream>

void printUpper(std::string sentence)
{
	for (size_t i = 0; i < sentence.length(); i++)
	{
		std::cout << static_cast<char>(std::toupper(sentence[i])) << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::string str = "";

		for (int i = 1; i < argc; i++)
			str += argv[i];
		printUpper(str);
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
