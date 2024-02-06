#include <iostream>
#include "Base.hpp"
#include "Utils.hpp"

int	main()
{
	Base a;
	for (int i = 0; i < 5; ++i)
	{
		try
		{
			Base*	m_random = Utils::generate();
			if (m_random == NULL)
				continue;
			Utils::identify(m_random);
			Utils::identify(static_cast<Base&>(*m_random));
			delete m_random;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q cpp06ex02");
}

/*
	https://www.ibm.com/docs/ja/i/7.1?topic=ssw_ibm_i_71/rzarg/keyword_dynamic_cast.html
*/