#include "utils.h"

bool	ensureValidArguments(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Invalid argument." << std::endl;
		return (false);
	}
	for (int i = 1; i < argc; i++)
	{
		if (argv[i] == NULL || argv[i][0] == '\0')
		{
			std::cout << "Error: Invalid argument." << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	ensureValidFilestream(std::ifstream& file)
{
	if(!file.is_open())
	{
		std::cout << "Error: " << std::strerror(errno) << std::endl;
		return (false);
	}
	return (true);
}

std::string	defaultOutputName(std::string& filename)
{
	std::string newFilename = filename.append(".replace");
	return (newFilename);
}

std::string	handleReplace(std::string line, std::string& str1, std::string& str2)
{
	while (true)
	{
		std::size_t pos = line.find(str1.c_str(), 0, str1.length());
		if (pos != std::string::npos)
		{
			line.erase(pos, str1.length());
			line.insert(pos, str2);
		}
		else
			break ;
	}
	return (line);
}
