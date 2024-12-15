#ifndef FILE_HPP
# define FILE_HPP

#include <iostream>

class File
{
	private:
		std::string _fileName;
		std::string _s1;
		std::string _s2;
	
	public:
		File(std::string fileName, std::string s1, std::string s2);
		void writeToFile();
		void replaceAll(std::string& source, const std::string& from, const std::string& to, int& failed);
};

#endif
