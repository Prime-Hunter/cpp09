#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <exception>

class RPN
{
	private:
		std::stack<double> _stack;
		void _executeStack(double (RPN::*f)(double, double));
		double _plus(double a, double b);
		double _minus(double a, double b);
		double _multiply(double a, double b);
		double _divide(double a, double b);

	public:
		RPN();
		RPN(const std::string  &inputStr);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		double getResult() const;

		class InvalidArgument : public std::runtime_error
		{
			public:
				explicit InvalidArgument(const std::string& msg);
		};

		class EmptyStack : public std::runtime_error
		{
			public:
				explicit EmptyStack(const std::string& msg);
		};

		class DivisionByZero : public std::runtime_error
		{
			public:
				explicit DivisionByZero(const std::string& msg);
		};	
};

#endif