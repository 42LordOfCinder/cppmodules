#ifndef BITCOIN_EXCHANGE
# define BITCOIN_EXCHANGE

# include <fstream>
# include <string>
# include <map>

class	BitcoinExchange {
	private:
		std::map<std::string, float>	rates;
		std::ifstream					inputFile;
	
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange &be);
		BitcoinExchange	&operator=(BitcoinExchange const &be);
		~BitcoinExchange();
		bool		loadData();
		bool		loadInput(char *file);
		void		process();
		std::string	trim(std::string const &str);
		bool		checkValue(std::string, float *fValue);
		bool		checkDate(std::string date);
		bool		validDate(int year, int month, int day);
};

#endif
