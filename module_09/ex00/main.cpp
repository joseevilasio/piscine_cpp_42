#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return (1);
	}
	try
	{
		BitcoinExchange engine("./data.csv");
		std::string input(argv[1]);
		engine.exchange(input);
		std::cout << "ok!\n"; //debug
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}