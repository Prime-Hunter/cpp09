#include "../includes/BitcoinExchange.hpp"

Converter::Converter() {}

Converter::~Converter()
{
    if (this->_fd.is_open())
        this->_fd.close();
}

Converter::Converter(const Converter &copy) {(void) copy;}

Converter &Converter::operator=(const Converter &src)
{
    (void) &src;
    return (*this);
}



