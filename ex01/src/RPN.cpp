#include "../includes/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string &inputStr)
{
	std::stringstream ss(inputStr);
	std::string token;
	int num;

	while (std::getline(ss, token, ' '))
	{
		if ((token.length() == 1 && isdigit(token[0])) || (token.length() == 2 && token[0] == '-' && isdigit(token[1])))
		{
			std::stringstream(token) >> num;
			_stack.push(num);
		}
		else if (token == "+")
			_executeStack(&RPN::_plus);
		else if (token == "-")
			_executeStack(&RPN::_minus);
		else if (token == "*")
			_executeStack(&RPN::_multiply);
		else if (token == "/")
			_executeStack(&RPN::_divide);
		else
			throw (RPN::InvalidArgument("Invalid argumentt: " + token));
	}
}

RPN::RPN(const RPN &copy) {*this = copy;}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
		_stack = src._stack;
	return (*this);
}

RPN::~RPN()
{
}

// Exceptions
RPN::InvalidArgument::InvalidArgument(const std::string& msg) : std::runtime_error(msg)
{
}

RPN::EmptyStack::EmptyStack(const std::string& msg) : std::runtime_error(msg)
{
}

RPN::DivisionByZero::DivisionByZero(const std::string& msg) : std::runtime_error(msg)
{
}

double RPN::getResult() const
{
	if (_stack.empty())
		throw RPN::EmptyStack("Empty stack");
	else if (_stack.size() > 1)
		throw RPN::InvalidArgument("Invalid argument");
	return (_stack.top());
}

void RPN::_executeStack(double (RPN::*f)(double, double))
{
	double a;
	double b;
	if (_stack.size() < 2)
		throw RPN::EmptyStack("Empty stack");
	a = _stack.top();
	_stack.pop();
	b = _stack.top();
	_stack.pop();
	_stack.push((this->*f)(a, b));
}

double RPN::_plus(double a, double b)
{
	return (b + a);
}

double RPN::_minus(double a, double b)
{
	return (b - a);
}

double RPN::_multiply(double a, double b)
{
	return (b * a);
}

double RPN::_divide(double a, double b)
{
	if (a == 0)
		throw RPN::DivisionByZero("Division by zero");
	return (b / a);
}