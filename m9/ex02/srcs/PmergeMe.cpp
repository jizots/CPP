# include <ctime>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char** argv)
	:m_compareCount(0)
{
	addContainerByArgs(ac, argv);
	std::cout << "Before: ";
	printContainer< std::vector <uint32> >(m_containerVec);
};

PmergeMe::PmergeMe(const PmergeMe& other)
	:m_containerVec(other.m_containerVec),
	 m_containerDeque(other.m_containerDeque),
	 m_compareCount(other.m_compareCount)
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
		m_compareCount = rhs.m_compareCount;
	}
	return (*this);
};

PmergeMe::vecContainer& PmergeMe::getContainerVec(void)
{
	return (m_containerVec);
};

const PmergeMe::vecContainer& PmergeMe::getContainerVec(void) const
{
	return (m_containerVec);
};

PmergeMe::deqContainer& PmergeMe::getContainerDeque(void)
{
	return (m_containerDeque);
};

const PmergeMe::deqContainer& PmergeMe::getContainerDeque(void) const
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
		if (isNumericType<uint32>(std::string(argv[i])))
		{
			m_containerVec.push_back(toNumericType<uint32>(std::string(argv[i])));
			m_containerDeque.push_back(toNumericType<uint32>(std::string(argv[i])));
		}
		else
			throw (std::invalid_argument("[error] " + std::string(argv[i]) + " is not an acceptable number"));
	}
};

void PmergeMe::integrateToMainChain(vecContainer& data, const vecContainer::size_type chunkScale,
		const vecContainer::size_type chunkSize, int hasRemainder)
{
	vecContainer::size_type iEnd = getNextIntegratePos<vecContainer>(1); //return 1
	vecMainChain tmpMainChain = makeTempMainChain(data, chunkScale);
	# ifdef DEBUG
		std::cout << "tmpMainChain: ";
		for (vecMainChain::size_type i = 0; i < tmpMainChain.size(); ++i)
			std::cout << *(tmpMainChain[i].second) << " ";
		std::cout << std::endl;
	# endif //DEBUG	

	for (vecContainer::size_type iIntegrateGroup = 2; iEnd < chunkSize + hasRemainder; ++iIntegrateGroup)
	{
		vecContainer::size_type iTarget = getNextIntegratePos<vecContainer>(iIntegrateGroup) - 1;
		while (iEnd <= iTarget)
		{
			// targetIndexが示すのは、MainChainに挿入したい数値のTContainer上のindex
			vecContainer::size_type targetIndex = (chunkScale * iTarget) + (chunkScale / 2) - 1;
			# ifdef DEBUG
				std::cout << "iTarget: " << iTarget << ", iEnd: " << iEnd 
				<< ", targetIndex: " << targetIndex << ", chunkScale: " << chunkScale << std::endl;
			# endif //DEBUG
			if (iTarget < (chunkSize + hasRemainder))
			{
				vecContainer::value_type targetVal = data[targetIndex];
				# ifdef DEBUG
					std::cout << "targetVal: " << targetVal << std::endl;
				# endif //DEBUG
				const vecMainChain::const_iterator insertPos = recursiveSearchInsertPos<vecMainChain>
						(tmpMainChain.begin(), 
							(targetIndex + 1 < chunkScale * chunkSize ? 
								std::find(
									tmpMainChain.begin(),
									tmpMainChain.end(),
									std::make_pair(
										data[targetIndex + (chunkScale / 2)],
										static_cast<vecContainer::const_iterator>(data.begin() + targetIndex + (chunkScale / 2)))
								)
								: tmpMainChain.end()
							)
							, std::make_pair(targetVal, data.begin() + targetIndex)
						);
				tmpMainChain.insert(insertPos, std::make_pair(targetVal, data.begin() + targetIndex));
				# ifdef DEBUG
					std::cout << "tmpMainChain: ";
					for (vecMainChain::size_type i = 0; i < tmpMainChain.size(); ++i) std::cout << *(tmpMainChain[i].second) << " ";
					std::cout << std::endl;
				# endif //DEBUG
			}
			--iTarget;
		}
		iEnd = getNextIntegratePos<vecContainer>(iIntegrateGroup);
	}
	data = buildContainerFromMainchain(data, chunkScale / 2, tmpMainChain);
	# ifdef DEBUG
		std::cout << "reconstruct vec: ";
		printContainer(data);
	# endif //DEBUG
}

void PmergeMe::integrateToMainChain(deqContainer& data, const deqContainer::size_type chunkScale,
		const deqContainer::size_type chunkSize, int hasRemainder)
{
	deqContainer::size_type iEnd = getNextIntegratePos<deqContainer>(1); //return 1
	deqMainChain tmpMainChain = makeTempMainChain(data, chunkScale);
	# ifdef DEBUG
		std::cout << "tmpMainChain: ";
		for (deqMainChain::size_type i = 0; i < tmpMainChain.size(); ++i)
			std::cout << *(tmpMainChain[i].second) << " ";
		std::cout << std::endl;
	# endif //DEBUG	

	for (deqContainer::size_type iIntegrateGroup = 2; iEnd < chunkSize + hasRemainder; ++iIntegrateGroup)
	{
		deqContainer::size_type iTarget = getNextIntegratePos<deqContainer>(iIntegrateGroup) - 1;
		while (iEnd <= iTarget)
		{
			// targetIndexが示すのは、MainChainに挿入したい数値のTContainer上のindex
			deqContainer::size_type targetIndex = (chunkScale * iTarget) + (chunkScale / 2) - 1;
			# ifdef DEBUG
				std::cout << "iTarget: " << iTarget << ", iEnd: " << iEnd 
				<< ", targetIndex: " << targetIndex << ", chunkScale: " << chunkScale << std::endl;
			# endif //DEBUG
			if (iTarget < (chunkSize + hasRemainder))
			{
				deqContainer::value_type targetVal = data[targetIndex];
				# ifdef DEBUG
					std::cout << "targetVal: " << targetVal << std::endl;
				# endif //DEBUG
				const deqMainChain::const_iterator insertPos = recursiveSearchInsertPos<deqMainChain>
						(tmpMainChain.begin(), 
							(targetIndex + 1 < chunkScale * chunkSize ? 
								std::find(
									tmpMainChain.begin(),
									tmpMainChain.end(),
									std::make_pair(
										data[targetIndex + (chunkScale / 2)],
										static_cast<deqContainer::const_iterator>(data.begin() + targetIndex + (chunkScale / 2)))
								)
								: tmpMainChain.end()
							)
							, std::make_pair(targetVal, data.begin() + targetIndex)
						);
				tmpMainChain.insert(insertPos, std::make_pair(targetVal, data.begin() + targetIndex));
				# ifdef DEBUG
					std::cout << "tmpMainChain: ";
					for (deqMainChain::size_type i = 0; i < tmpMainChain.size(); ++i) std::cout << *(tmpMainChain[i].second) << " ";
					std::cout << std::endl;
				# endif //DEBUG
			}
			--iTarget;
		}
		iEnd = getNextIntegratePos<deqContainer>(iIntegrateGroup);
	}
	data = buildContainerFromMainchain(data, chunkScale / 2, tmpMainChain);
	# ifdef DEBUG
		std::cout << "reconstruct vec: ";
		printContainer(data);
	# endif //DEBUG
}

PmergeMe::vecMainChain PmergeMe::makeTempMainChain(const vecContainer& data, const vecContainer::size_type chunkScale)
{
	vecMainChain tmpMainChain;

	tmpMainChain.push_back(std::make_pair(data[(chunkScale / 2) - 1], data.begin() + (chunkScale / 2) - 1));
	for (vecContainer::size_type i = 1; (i * chunkScale - 1) < data.size(); ++i)
		tmpMainChain.push_back(std::make_pair(data[(chunkScale * i) - 1], data.begin() + (chunkScale * i) - 1));
	return (tmpMainChain);
}

PmergeMe::deqMainChain PmergeMe::makeTempMainChain(const deqContainer& data, const deqContainer::size_type chunkScale)
{
	deqMainChain tmpMainChain;

	tmpMainChain.push_back(std::make_pair(data[(chunkScale / 2) - 1], data.begin() + (chunkScale / 2) - 1));
	for (vecContainer::size_type i = 1; (i * chunkScale - 1) < data.size(); ++i)
		tmpMainChain.push_back(std::make_pair(data[(chunkScale * i) - 1], data.begin() + (chunkScale * i) - 1));
	return (tmpMainChain);
}

PmergeMe::vecContainer PmergeMe::buildContainerFromMainchain(const vecContainer& data,
	const vecContainer::size_type& chunkScale, const vecMainChain& mainChain)
{
	vecContainer	reconstructData;
	unsigned int remainData = data.size() % chunkScale;

	reconstructData.reserve(data.size());
	for (vecContainer::size_type i = 0; i < mainChain.size(); ++i)
		reconstructData.insert(reconstructData.end(), mainChain[i].second - chunkScale + 1, mainChain[i].second + 1);
	if (remainData)
		reconstructData.insert(reconstructData.end(), data.end() - remainData, data.end());
	return (reconstructData);
}

PmergeMe::deqContainer PmergeMe::buildContainerFromMainchain(const deqContainer& data,
	const deqContainer::size_type& chunkScale, const deqMainChain& mainChain)
{
	deqContainer	reconstructData;
	unsigned int remainData = data.size() % chunkScale;

	for (deqContainer::size_type i = 0; i < mainChain.size(); ++i)
		reconstructData.insert(reconstructData.end(), mainChain[i].second - chunkScale + 1, mainChain[i].second + 1);
	if (remainData)
		reconstructData.insert(reconstructData.end(), data.end() - remainData, data.end());
	return (reconstructData);
}
