#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <exception>
# include <string>

class Converter
{
	private:
		std::map<std::string, double>	_quotes;
		void _readDatabase();
		bool _validateDate(std::string const &date);
		double _validatePrice(std::string const &price);
		void _multiplyWithQuote(std::string const &date, double price);
	
	public:
		Converter();
		Converter(Converter const &other);
		Converter &operator=(Converter const &other);
		~Converter();

		std::map<std::string, double> const &getQuotes() const;
		void execute(char const *fileName);

		class CouldNotOpenFile : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Could not open file");
				}
		};

		class InvalidColumnFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid column format. Expected 'date | value'");
				}
		};

		class InvalidDateFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid date format. Expected 'YYYY-MM-DD'");
				}
		};

		class InvalidPriceFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid price format. Expected a number between 0.0 and 1000.0");
				}
		};
};


#endif