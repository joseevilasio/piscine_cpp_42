#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>
#include <cfloat>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iomanip>

BitcoinExchange::BitcoinExchange(const std::string& db_path)
{
	if (!BitcoinExchange::_init_db(db_path))
		throw std::runtime_error("Error: Failure to start the database");
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

bool	BitcoinExchange::_init_db(const std::string& db_path)
{
	std::ifstream db(db_path.c_str());

	if (!db.is_open())
		return (false);

	std::string line;
	while (std::getline(db, line))
	{
		try
		{
			std::size_t sep = line.find(",");
			std::string date = line.substr(0, sep);
			std::string value = line.substr(sep + 1);
			if (date == "date")
				continue ;
			_validateDate(date);
			float f = _convertValue(value, "database");
			_database.insert(std::pair<std::string, float>(date, f));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	db.close();
	return (true);
}

bool	BitcoinExchange::exchange(const std::string& input_path)
{
	std::ifstream input(input_path.c_str());

	if (!input.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	while (std::getline(input, line))
	{
		try
		{
			line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
			std::size_t sep = line.find("|"); //diff
			std::string date = line.substr(0, sep);
			std::string value = line.substr(sep + 1);
			if (date == "date")
				continue ;
			_validateDate(date);
			float f = _convertValue(value, "input");
			std::cout << date << " => " << f << " = " << f * _findValue(date) << std::endl; //debug
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	input.close();
	return (true);
}

// bool	BitcoinExchange::validate_path(const std::string& path)
// {
// 	std::ifstream file(path.c_str());
// 	if (file.is_open())
// 	{
// 		file.close();
// 		return (true);
// 	}
// 	return (false);
// }

bool	BitcoinExchange::_validateDateValue(const std::string& value, const std::string& type)
{
	std::istringstream iss(value);
	int i;
	
	if (!(iss >> i))
		return (false);
	if (!iss.eof())
		return (false);
	if (type == "year" && (i < 1000 || i > 3000))
		return (false);
	if (type == "month" && (i < 1 || i > 12))
		return (false);
	if (type == "day" && (i < 1 || i > 31))
		return (false);
	return (true);
}

bool	BitcoinExchange::_validateDate(const std::string& date)
{
	// 2012-01-01
	// 0123456789
	std::string error = "Error: bad input => " + date;

	if (date.length() != 10)
		throw std::logic_error(error);
	if (date.substr(4, 1) != "-" || date.substr(7, 1) != "-")
		throw std::logic_error(error);
	if (!BitcoinExchange::_validateDateValue(date.substr(0, 4), "year")) //enum?
		throw std::logic_error(error);
	if (!BitcoinExchange::_validateDateValue(date.substr(5, 2), "month"))
		throw std::logic_error(error);
	if (!BitcoinExchange::_validateDateValue(date.substr(8, 2), "day"))
		throw std::logic_error(error);

	//TODO added validate leap year
	return (true);
}

float	BitcoinExchange::_convertValue(const std::string& value, const std::string& type)
{
	errno = 0;
	char* end;

	float f = std::strtod(value.c_str(), &end);

	if (value.c_str() == end)
		throw std::range_error("Error: not a valid numeric value.");
	if (errno == ERANGE) //INPUT != DATABASE
		throw std::range_error("Error: too large a number.");
	if (type == "input" && f > 1000)
		throw std::range_error("Error: too large a number.");
	if (f < 0)
		throw std::range_error("Error: not a positive number.");
	while (*end == ' ' || *end == '\t' || *end == '\n')
		++end;
	if (*end != '\0')
		throw std::range_error("Error: not a valid numeric value.");
	return (f);
}

float	BitcoinExchange::_findValue(const std::string& date)
{
	(void)date;
	std::map<std::string, float>::const_iterator match = _database.lower_bound(date);
	if (match != _database.end())
	{
		return (match->second);
	}
	float f = 100;
	return (f);
}	
