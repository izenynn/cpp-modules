#ifndef EX00_BITCOINEXCHANGE_HPP_
#define EX00_BITCOINEXCHANGE_HPP_

#include <string>
#include <map>

class BitcoinExchange {
public:
	BitcoinExchange(const std::string &filename);
	void ProcessInput(const std::string &filename);
private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &rhs);

	std::map<std::string, double> data_;
	double GetExchangeRate(const std::string &date);
	bool ValidateDate(const std::string &date);
	bool ValidateValue(const double &value);
};

#endif // EX00_BITCOINEXCHANGE_HPP_
