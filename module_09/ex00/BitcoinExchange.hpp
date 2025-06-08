#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_database;

		bool	_validateDate(const std::string& date);
		bool	_validateDateValue(const std::string& value, const std::string& type);
		float	_convertValue(const std::string& value, const std::string& type);

	public:
		BitcoinExchange(const std::string& db_path);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		BitcoinExchange(const BitcoinExchange& rhs);
		~BitcoinExchange(void);

		bool	exchange(const std::string& input_path) const;
		bool	init_db(const std::string& db_path);
};

#endif //BITCOIN_EXCHANGE_HPP
