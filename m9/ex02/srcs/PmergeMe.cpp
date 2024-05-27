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

vecContainer& PmergeMe::getContainerVec(void)
{
	return (m_containerVec);
};

const vecContainer& PmergeMe::getContainerVec(void) const
{
	return (m_containerVec);
};

std::deque<uint32>& PmergeMe::getContainerDeque(void)
{
	return (m_containerDeque);
};

const std::deque<uint32>& PmergeMe::getContainerDeque(void) const
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

void PmergeMe::mergeInsertionSortVec(const vecContainer::size_type chunkScale,
	const vecContainer::size_type chunkSize, const bool hasRemainder)
{
	if (chunkSize < 1)
		return ;
	// ここでchunkScale内のbiggest要素をとなりのchunkと比較して小大の順に並べる
	compareChunkAndSwap(chunkScale);
	# ifdef DEBUG
		std::cout << "### After compare Chunk ###" << std::endl;
		printContainer(m_containerVec);
	# endif //DEBUG
	// 再帰から帰ってくると、chunkSize + 1の要素が降順に並んだ状態になっている
	mergeInsertionSortVec(chunkScale * 2, chunkSize / 2, chunkSize % 2);
	// chunkSize * 2の要素数を、一列に並べる。
	if (1 < chunkScale)
		integrateToMainChain(chunkScale, chunkSize, (hasRemainder ? 1 : 0));
	# ifdef DEBUG
		if (chunkScale == 1)
		{
			std::cout << "compare count: " << m_compareCount << std::endl;
			m_compareCount = 0;
			std::cout << std::endl;
			std::cout << std::endl;
		}
	# endif //DEBUG
};

void PmergeMe::compareChunkAndSwap(const vecContainer::size_type chunkScale)
{
	// iがさすのは、比較元（chunkLeft）の開始位置
	for (vecContainer::size_type i = 0; i + (chunkScale * 2) <= m_containerVec.size(); i += (chunkScale * 2))
	{
		if (!isLittleLeftChunk(i + (chunkScale - 1), i + (chunkScale * 2) - 1))
			swapChunk(chunkScale, i, i + chunkScale);
	}
}

bool PmergeMe::isLittleLeftChunk(const vecContainer::size_type iLeftChunkEnd,
	const vecContainer::size_type iRightChunkEnd)
{
	# ifdef DEBUG
		std::cout << "compareChunk: " << m_containerVec[iLeftChunkEnd] << " vs " << m_containerVec[iRightChunkEnd] << std::endl;
	# endif //DEBUG
	++m_compareCount;
	if (m_containerVec[iLeftChunkEnd] <= m_containerVec[iRightChunkEnd])
		return (true);
	return (false);
}

void PmergeMe::swapChunk(const vecContainer::size_type chunkScale,
		const vecContainer::size_type iLeftChunkStart, const vecContainer::size_type iRightChunkStart)
{
	vecContainer copyRight(m_containerVec.begin() + iRightChunkStart, m_containerVec.begin() + iRightChunkStart + chunkScale);

	m_containerVec.erase(m_containerVec.begin() + iRightChunkStart, m_containerVec.begin() + iRightChunkStart + chunkScale);
	m_containerVec.insert(m_containerVec.begin() + iLeftChunkStart, copyRight.begin(), copyRight.end());
}

void PmergeMe::integrateToMainChain(const vecContainer::size_type chunkScale,
		const vecContainer::size_type chunkSize, int hasRemainder)
{
	vecContainer::size_type iEnd = getNextIntegratePos(1); //return 1
	vecMainChain tmpMainChain = makeTempMainChain(chunkScale);
	# ifdef DEBUG
		std::cout << "tmpMainChain: ";
		for (vecMainChain::size_type i = 0; i < tmpMainChain.size(); ++i)
			std::cout << *(tmpMainChain[i].second) << " ";
		std::cout << std::endl;
	# endif //DEBUG	

	for (vecContainer::size_type iIntegrateGroup = 2; iEnd < chunkSize + hasRemainder; ++iIntegrateGroup)
	{
		vecContainer::size_type iTarget = getNextIntegratePos(iIntegrateGroup) - 1;
		while (iEnd <= iTarget)
		{
			// targetIndexが示すのは、MainChainに挿入したい数値のTContainer上のindex
			vecContainer::size_type targetIndex = (chunkScale * iTarget) + (chunkScale / 2) - 1;
			# ifdef DEBUG
				std::cout << "iTarget: " << iTarget << ", iEnd: " << iEnd << ", targetIndex: " << targetIndex << ", chunkScale: " << chunkScale << std::endl;
			# endif //DEBUG
			if (iTarget < (chunkSize + hasRemainder))
			{
				vecContainer::value_type targetVal = m_containerVec[targetIndex];
				# ifdef DEBUG
					std::cout << "targetVal: " << targetVal << std::endl;
				# endif //DEBUG
				const vecMainChain::const_iterator insertPos = recursiveSearchInsertPos
						(tmpMainChain.begin(), 
							(targetIndex + 1 < chunkScale * chunkSize ? 
								std::find(
									tmpMainChain.begin(),
									tmpMainChain.end(),
									std::make_pair(
										m_containerVec[targetIndex + (chunkScale / 2)],
										static_cast<vecContainer::const_iterator>(m_containerVec.begin() + targetIndex + (chunkScale / 2)))
								)
								: tmpMainChain.end()
							)
							, std::make_pair(targetVal, m_containerVec.begin() + targetIndex)
						);
				tmpMainChain.insert(insertPos, std::make_pair(targetVal, m_containerVec.begin() + targetIndex));
				# ifdef DEBUG
					std::cout << "tmpMainChain: ";
					for (vecMainChain::size_type i = 0; i < tmpMainChain.size(); ++i) std::cout << *(tmpMainChain[i].second) << " ";
					std::cout << std::endl;
				# endif //DEBUG
			}
			--iTarget;
		}
		iEnd = getNextIntegratePos(iIntegrateGroup);
	}
	m_containerVec = buildContainerFromMainchain(chunkScale / 2, tmpMainChain);
	# ifdef DEBUG
		std::cout << "reconstruct vec: ";
		printContainer(m_containerVec);
	# endif //DEBUG
}

vecContainer::size_type PmergeMe::getNextIntegratePos(const vecContainer::size_type number)
{
	return ((std::pow(2, number + 1) + std::pow(-1, number)) / 3);
}

vecMainChain PmergeMe::makeTempMainChain(const vecContainer::size_type chunkScale)
{
	vecMainChain tmpMainChain;

	tmpMainChain.push_back(std::make_pair(m_containerVec[(chunkScale / 2) - 1], m_containerVec.begin() + (chunkScale / 2) - 1));
	for (vecContainer::size_type i = 1; (i * chunkScale - 1) < m_containerVec.size(); ++i)
		tmpMainChain.push_back(std::make_pair(m_containerVec[(chunkScale * i) - 1], m_containerVec.begin() + (chunkScale * i) - 1));
	return (tmpMainChain);
}

const vecMainChain::const_iterator PmergeMe::recursiveSearchInsertPos(const vecMainChain::const_iterator begin,
	const vecMainChain::const_iterator end, const vecMainChain::value_type targetVal)
{
	if (begin == end)
		return (begin);
	else if ((end - begin) == 1)
	{
		++m_compareCount;

		# ifdef DEBUG
			std::cout << "compare: " << (*begin).first << " vs " << targetVal.first << std::endl;
		# endif //DEBUG
		if (targetVal.first < (*begin).first)
			return (begin);
		else
			return (begin + 1);
	}
	else
	{
		++m_compareCount;
		const vecMainChain::const_iterator middle = begin + ((end - begin) / 2);
		# ifdef DEBUG
			std::cout << "compare: " << (*middle).first << " vs " << targetVal.first << std::endl;
		# endif //DEBUG
		if (targetVal < *middle)
			return (recursiveSearchInsertPos(begin, middle, targetVal));
		else
			return (recursiveSearchInsertPos(middle + 1, end, targetVal));
	}
}

vecContainer PmergeMe::buildContainerFromMainchain(const vecContainer::size_type& chunkScale, const vecMainChain& mainChain)
{
	vecContainer	reconstructData;
	unsigned int remainData = m_containerVec.size() % chunkScale;

	reconstructData.reserve(m_containerVec.size());
	for (vecContainer::size_type i = 0; i < mainChain.size(); ++i)
		reconstructData.insert(reconstructData.end(), mainChain[i].second - chunkScale + 1, mainChain[i].second + 1);
	if (remainData)
		reconstructData.insert(reconstructData.end(), m_containerVec.end() - remainData, m_containerVec.end());
	return (reconstructData);
}
