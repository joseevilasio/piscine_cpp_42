#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_database;
		enum					SourceType { SOURCE_DATABASE, SOURCE_INPUT};

		bool	_validateDate(const std::string& date);
		int		_convertDate(const std::string& value);
		float	_convertValue(const std::string& value, SourceType type);
		float	_findValue(const std::string& date);
		bool	_init_db(const std::string& db_path);

	public:
		BitcoinExchange(const std::string& db_path);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		BitcoinExchange(const BitcoinExchange& rhs);
		~BitcoinExchange(void);

		void	exchange(const std::string& input_path);
};

#endif //BITCOIN_EXCHANGE_HPP
