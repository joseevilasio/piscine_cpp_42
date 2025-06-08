#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, std::string>	_database;

		static bool	validate_path(const std::string& path); //remove
		static bool	validate_date(const std::string& date);
		static bool	validate_value(const std::string& value);

	public:
		BitcoinExchange(const std::string& db_path);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		BitcoinExchange(const BitcoinExchange& rhs);
		~BitcoinExchange(void);

		bool	exchange(const std::string& input_path) const;
		bool	init_db(const std::string& db_path);
};

#endif //BITCOIN_EXCHANGE_HPP
