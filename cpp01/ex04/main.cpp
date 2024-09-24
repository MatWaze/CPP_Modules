#include "File.hpp"

int	main2(int argc, char **argv)
{
	if (argc == 4)
	{
		File f = File(argv[1], argv[2], argv[3]);
		f.writeToFile();
	}
	else
		std::cout << "Wrong number of arguments" << std::endl;
	return (0);
}

int	main(int argc, char **argv)
{
	main2(argc, argv);
	system("leaks sed");
}
