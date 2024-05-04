#include "RPN.hpp"

#include <iostream>

RPN::RPN(const char *calculationSrc)
	:m_iss(std::string(calculationSrc))
{
	if (m_iss.fail())
		throw ("iss.fail(): Constructor");
	while (!m_iss.eof())
	{
		std::string token = popNextToken();
		if (isNumericType<uint8_t>(token))
			m_stack.push(toNumericType<uint8_t>(token));
		else if (isArithmeticOparator(token))
		{
			//スタックに2つ以上数字があることを確認して、算術式で計算してスタックに戻す
			if (1 < m_stack.size())
				;
			else
				throw ("Error");
		}
		else if (token.size() == 0)
			continue ;
		else
			throw ("Error");
	}
	if (m_stack.size() == 1)
		std::cout << m_result << std::endl;
	else
		throw ("Error");
};

RPN::RPN(const RPN& other)
{

};

RPN::~RPN(void)
{};

RPN& RPN::operator=(const RPN& rhs)
{

};

bool RPN::isArithmeticOparator(const std::string& token)
{
	if (token.size() == 1 && (token == "+" || token == "-" || token == "/" || token == "*"))
		return (true);
	return (false);
};

std::string RPN::popNextToken(void)
{
	std::string token;

	m_iss >> token;
	if (m_iss.fail())
	{
		if (m_iss.eof())
			return ("");
		else
			throw ("Error: iss.fail()");
	}
	return (token);
}		

void RPN::clearStream(void)
{

};
