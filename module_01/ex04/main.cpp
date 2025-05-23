#include "utils.h"

int	main(int argc, char **argv)
{
	if (!ensureValidArguments(argc, argv))
		return (1);

	std::string filename(argv[1]);
	std::string str1(argv[2]);
	std::string str2(argv[3]);

	std::ifstream input(filename.c_str());

	if (!ensureValidFilestream(input))
		return (1);

	std::ofstream output(defaultOutputName(filename).c_str());

	if (output.is_open())
	{
		std::string buffer;
		std::string line;
		while (std::getline(input, line))
		{
			handleReplace(line, str1, str2);
			buffer.append(line);
			if (!input.eof())
				buffer.append("\n");
		}
		output << buffer;
		output.close();
	}
	else
	{
		std::cout << "Error: Output file failure." << std::endl;
		return (1);
	}
	return (0);
}
