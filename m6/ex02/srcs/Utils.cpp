#include "Utils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

Base*	Utils::generate(void)
{
	std::srand(time(NULL)); /*乱数生成のseedを時間にする。seedを変更しないと、rand()の結果が変わらない*/
	char	remainder = (rand() % 3);
	char	timeSleep = (rand() * rand()) % 3; /*overflowの可能性あり*/

	if (timeSleep < 0)
		timeSleep *= -1;
	sleep(timeSleep + 1); /*time()は秒単位の精度。seedがforループで同じにならないようにスリープする*/
	switch (remainder)
	{
		case 0:
			std::cout << "A class made!" << std::endl;
			return (static_cast<Base*>(new A));
			break;
		case 1:
			std::cout << "B class made!" << std::endl;
			return (static_cast<Base*>(new B));
			break;
		case 2:
			std::cout << "C class made!" << std::endl;
			return (static_cast<Base*>(new C));
			break;
		default:
			std::cout << "swich error?" << std::endl;
			break;
	}
	return (NULL);
};

void	Utils::identify(Base* p)
{
	A*	m_A = dynamic_cast<A*>(p); // ポインタのdynamic_castは失敗するとNULL(0)をリターンする。
	B*	m_B = dynamic_cast<B*>(p);
	C*	m_C = dynamic_cast<C*>(p);

	if (m_A)
		std::cout << "I'm A*!" << std::endl;
	else if (m_B)
		std::cout << "I'm B*!" << std::endl;
	else if (m_C)
		std::cout << "I'm C*!" << std::endl;
	else
		std::cout << "Who Am I???" << std::endl;
};

void	Utils::identify(Base& p)
{
	try
	{
		A& m_A = dynamic_cast<A&>(p); //参照のdynamic_castは失敗すると、bad_castをthrowする
		std::cout << "I'm A&!" << std::endl;
		(void)m_A;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << std::endl;
		// catchはするが、それを無視して次のパターンで代入を試みる
	}
	try
	{
		B& m_B = dynamic_cast<B&>(p);
		std::cout << "I'm B&!" << std::endl;
		(void)m_B;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << std::endl;
	}
	try
	{
		C& m_C = dynamic_cast<C&>(p);
		std::cout << "I'm C&!" << std::endl;
		(void)m_C;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << std::endl;
	}
};