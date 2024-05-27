#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <sstream>

class RPN
{
public:
	RPN(void);
	RPN(const RPN& other);
	~RPN(void);
	RPN& operator=(const RPN& rhs);
	double Calculation(const std::string& calculationSrc);

private:
	std::stack<double> m_stack;

private:

	template <typename T>
	bool isUnsigned(){ return (true); };

	template <>
	bool isUnsigned<uint8_t>(){ return (true); };

	template <>
	bool isUnsigned<uint16_t>(){ return (true); };

	template <>
	bool isUnsigned<uint32_t>(){ return (true); };

	template <>
	bool isUnsigned<uint64_t>(){ return (true); };

	template <typename T>
	bool isNumericType(const std::string& literal)
	{
		if (isUnsigned<T>() && (literal.find('-') != std::string::npos))
			return (false);
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
			throw (std::invalid_argument("Error: Argument is invalid literal => " + literal));
		return (t);
	};

	bool isArithmeticOparator(const std::string& token);
	std::string popNextToken(std::istringstream& iss);
};

#endif