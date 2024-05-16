#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char** argv)
	:m_compareCount(0)
{
	addContainerByArgs(ac, argv);

	std::cout << "Before: ";
	printContainer< std::vector <uint64_t> >(m_containerVec);
};

PmergeMe::PmergeMe(const PmergeMe& other)
	:m_containerVec(other.m_containerVec),
	 m_containerDeque(other.m_containerDeque)
{};

PmergeMe::~PmergeMe(void)
{};

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this == &rhs)
		;
	else
	{
		m_containerVec = rhs.m_containerVec;
		m_containerDeque = rhs.m_containerDeque;
	}
	return (*this);
};

void PmergeMe::addContainerByArgs(int ac, char** argv)
{
	if (ac < 2)
	{
		std::cout << "[notif] Set default data" << std::endl;
		for (unsigned int i = 21; 0 < i; --i)
		{
			m_containerVec.push_back(i);
			m_containerDeque.push_back(i);
		}
		return ;
	}
	for (int i = 1; i < ac; ++i)
	{
		if (isNumericType<uint64_t>(std::string(argv[i])))
		{
			m_containerVec.push_back(toNumericType<uint64_t>(std::string(argv[i])));
			m_containerDeque.push_back(toNumericType<uint64_t>(std::string(argv[i])));
		}
		else
			throw ("[erorr] " + std::string(argv[i]) + " is not an acceptable number");
	}
};
