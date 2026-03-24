#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>

class Converter
{
    private:
        std::fstream _fd;
        std::map<char, int> _map;
    
    public:
        Converter();
        Converter(std::fstream fd);
        ~Converter();
        Converter(const Converter &copy);
        Converter &operator =(const Converter &src);

        void openFile(char *filename);
};

#endif