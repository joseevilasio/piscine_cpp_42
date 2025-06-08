#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_database;

		static bool	validate_path(const std::string& path);
		static bool	validate_date(const std::string& date);
		static bool	validate_value(const std::string& value);
		static bool	init_db(const std::string& db_path);

	public:
		BitcoinExchange(const std::string& db_path);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		BitcoinExchange(const BitcoinExchange& rhs);
		~BitcoinExchange(void);

		bool	exchange(const std::string& input_path) const;
};

#endif //BITCOIN_EXCHANGE_HPP
