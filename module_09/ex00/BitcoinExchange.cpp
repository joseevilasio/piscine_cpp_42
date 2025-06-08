#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange(const std::string& db_path)
{
	if (!BitcoinExchange::init_db(db_path))
		throw std::runtime_error("Failure to start the database");
}

// BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
// {
// 	// if (this != &rhs)
// 	// {
// 	// 	//_database = rhs._database;
// 	// }
// 	return (*this);
// }

// BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {*this=rhs;}

BitcoinExchange::~BitcoinExchange(void) {}

bool	BitcoinExchange::init_db(const std::string& db_path)
{
	std::ifstream db(db_path.c_str());

	if (!db.is_open())
		return (false);

	std::string line;
	while (std::getline(db, line))
	{
		std::size_t sep = line.find(",");
		std::string cpy;
		std::size_t len = line.copy(cpy, 0, sep);
		cpy[len] = '\0';

		std::cout << cpy << std::endl; //debug
	}

	std::cout << "init db: " << db_path << std::endl;

	db.close();
	return (true);
}

bool	BitcoinExchange::exchange(const std::string& input_path) const
{
	// if (!BitcoinExchange::validate_path(input_path))
	// 	throw std::runtime_error("could not open file.");

	std::ifstream input(input_path.c_str());

	if (!input.is_open())
		throw std::runtime_error("could not open file.");

	return (true);
}

bool	BitcoinExchange::validate_path(const std::string& path)
{
	std::ifstream file(path.c_str());
	if (file.is_open())
	{
		file.close();
		return (true);
	}
	return (false);
}

bool	BitcoinExchange::validate_date(const std::string& date)
{
	(void)date;
	return (true);
} 

bool	BitcoinExchange::validate_value(const std::string& value)
{
	(void)value;
	return (true);
}
