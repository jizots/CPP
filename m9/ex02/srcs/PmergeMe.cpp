#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char** argv)
	:m_compareCount(0)
{
	addContainerByArgs(ac, argv);
	# ifdef DEBUG
		std::cout << "### Initial ###" << std::endl;
		printContainer< std::vector <uint32_t> >(m_containerVec);
	# endif //DEBUG
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

std::vector<uint32_t>& PmergeMe::getContainerVec(void)
{
	return (m_containerVec);
};

const std::vector<uint32_t>& PmergeMe::getContainerVec(void) const
{
	return (m_containerVec);
};

std::deque<uint32_t>& PmergeMe::getContainerDeque(void)
{
	return (m_containerDeque);
};

const std::deque<uint32_t>& PmergeMe::getContainerDeque(void) const
{
	return (m_containerDeque);
};


void PmergeMe::addContainerByArgs(int ac, char** argv)
{
	if (ac < 2)
	{
		unsigned int defaultData[] = {21, 1, 13, 2, 17, 3, 12, 4, 20, 5, 15, 6, 19, 7, 14, 8, 18, 9, 16, 10, 11};
	
		std::cout << "[notif] Set default data" << std::endl;
		for (unsigned int i = 0; i < DEFAULT_DATA_SIZE; ++i)
		{
			m_containerVec.push_back(defaultData[i]);
			m_containerDeque.push_back(defaultData[i]);
		}
		return ;
	}
	for (int i = 1; i < ac; ++i)
	{
		if (isNumericType<uint32_t>(std::string(argv[i])))
		{
			m_containerVec.push_back(toNumericType<uint32_t>(std::string(argv[i])));
			m_containerDeque.push_back(toNumericType<uint32_t>(std::string(argv[i])));
		}
		else
			throw ("[erorr] " + std::string(argv[i]) + " is not an acceptable number");
	}
};
