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

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
	{
		_database = rhs._database;
	}
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {*this=rhs;}

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
			if (line.empty())
				continue ;
			std::size_t sep = line.find("|");
			std::string date = line.substr(0, sep);
			std::string value = line.substr(sep + 1);
			if (date == "date")
				continue ;
			_validateDate(date);
			float f = _convertValue(value, "input");
			std::cout << date << " => " << f << " = "
				<< f * _findValue(date) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	input.close();
	return (true);
}

int		BitcoinExchange::_convertDate(const std::string& value)
{
	std::istringstream iss(value);
	int i;
	
	if (!(iss >> i))
		return (-1);
	if (!iss.eof())
		return (-1);
	return (i);
}

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
	std::string	error = "Error: bad input => " + date;	
	int			daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if (date.length() != 10 || (date.substr(4, 1) != "-" || date.substr(7, 1) != "-"))
		throw std::logic_error(error);

	int year		= _convertDate(date.substr(0, 4));
	int month		= _convertDate(date.substr(5, 2));
	int day			= _convertDate(date.substr(8, 2));
	bool isLeapYear = ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0));

	if (year < 1000 || year > 3000 || month < 1 || month > 12 || day < 1)
		throw std::logic_error(error);
	if (isLeapYear && month == 2 && day > 29)
		throw std::logic_error(error);
	if (!isLeapYear && month == 2 && day > 28)
		throw std::logic_error(error);
	if (month != 2 && day > daysInMonth[month - 1])
		throw std::logic_error(error);
	return (true);
}

float	BitcoinExchange::_convertValue(const std::string& value, const std::string& type)
{
	errno = 0;
	char* end;

	float f = std::strtod(value.c_str(), &end);

	if (value.c_str() == end)
		throw std::range_error("Error: not a valid numeric value.");
	if (errno == ERANGE)
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
	if (_database.empty())
		return (0);
	if (date < _database.begin()->first)
		return (0);

	std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
	if (it != _database.end() && it->first == date)
		return (it->second);
	if (it == _database.begin())
		return (0);
	--it;
	return (it->second);
}
