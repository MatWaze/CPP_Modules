#include "File.hpp"
#include <fstream>
#include <new>

File::File(std::string fileName, std::string s1, std::string s2)
{
	this->_fileName = fileName;
	this->_s1 = s1;
	this->_s2 = s2;
}

void File::writeToFile()
{
	bool	conditionToReplace = true;

	if ((this->_s1 == this->_s2) || this->_s1 == "")
		conditionToReplace = false;

	std::ofstream writeFile(this->_fileName + ".replace");
	if (writeFile.is_open())
	{
		std::ifstream readFile(this->_fileName);
		if (readFile.is_open())
		{
			std::string line;
			int failed = 0;
			
			while (std::getline(readFile, line))
			{
				if (failed == 0 && conditionToReplace)
				{
					replaceAll(line, this->_s1, this->_s2, failed);
					writeFile << line << std::endl;
				}
				else if (failed == 1)
					break;
			}
			readFile.close();
		}
	}
	else
	{
		std::cerr << "Unable to create "
		<< this->_fileName + ".replace" << std::endl;
	}
	writeFile.close();
}

void File::replaceAll(std::string& source, const std::string& from, const std::string& to, int& failed)
{
	std::string	newString;
	newString.reserve(source.length());
	std::string::size_type lastPos = 0;
	std::string::size_type findPos;

	while(std::string::npos != (findPos = source.find(from, lastPos)))
	{
		newString.append(source, lastPos, findPos - lastPos);
		newString += to;
		lastPos = findPos + from.length();
	}
	newString += source.substr(lastPos);
	source.swap(newString);
}
