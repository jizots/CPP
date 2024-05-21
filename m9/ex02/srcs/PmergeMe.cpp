#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char** argv)
	:m_compareCount(0)
{
	addContainerByArgs(ac, argv);
	std::cout << "Before: ";
	printContainer< std::vector <uint32_t> >(m_containerVec);

	mergeInsertionSort(m_containerVec, 1, m_containerVec.size());
	std::cout << "compare count: " << m_compareCount << std::endl;

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
		unsigned int defaultData[] = {21, 1, 20, 2, 19, 3, 18, 4, 17, 5, 16, 6, 15, 7, 14, 8, 13, 9, 12, 10, 11};
	
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
