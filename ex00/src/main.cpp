#include "../includes/BitcoinExchange.hpp"

static int is_file(char *filename)
{
    std::fstream file;
    file.open(filename, std::fstream::in);
    if (file.is_open())
    {
        file.close();
        return (1);
    }
    return (0);
}

static int is_valid_date(char *date) {}

static int is_valid_value(char *value) {}

static int is_valid_format(char *filename)
{
    std::fstream file;
    file.open(filename, std::fstream::in);
    std::string line;

    while(std::getline(file, line))
    {
        std::cout << line << std::endl;
    }
    file.close();
    return (1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Invalid arguments number. Correct syntax: './btc [filename]'" << std::endl;
        return (1);
    }
    if (!is_file(argv[1]))
    {
        std::cerr << "Error when opening the file. Verify thath the file exists or that the permissions are correct" << std::endl;
        return (1);        
    }
    is_valid_format(argv[1]);
    return (0);
}