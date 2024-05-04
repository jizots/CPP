#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <sstream>

class RPN
{
public:
	RPN(const char *calculationSrc);
	RPN(const RPN& other);
	~RPN(void);
	RPN& operator=(const RPN& rhs);

private:
	std::stack<u_int8_t> m_stack;
	std::istringstream m_iss;
	double	m_result;

private:
	RPN(void);
	
	template <typename T>
	bool isNumericType(const std::string& literal)
	{
		std::istringstream iss(literal);
		T t;

		iss >> t;
		if (iss.fail() || !iss.eof())
			return (false);
		return (true);
	};

	template <typename T>
	T toNumericType(const std::string& literal)
	{
		std::istringstream iss(literal);
		T t;

		iss >> t;
		if (iss.fail() || !iss.eof())
			throw ("Error: Argument is invalid literal => " + literal);
		return (t);
	};

	bool isArithmeticOparator(const std::string& token);
	std::string popNextToken(void);
	void clearStream(void);
};

#endif