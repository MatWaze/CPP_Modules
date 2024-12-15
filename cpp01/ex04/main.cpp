#include "File.hpp"

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		File f = File(argv[1], argv[2], argv[3]);
		f.writeToFile();
	}
	else
		std::cout << "Usage: ./sed original_file string_from string_to" << std::endl;
	return (0);
}

