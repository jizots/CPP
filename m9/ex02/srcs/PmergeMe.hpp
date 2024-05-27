#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <sstream>
# include <iostream>
# include <iomanip> //setw()
# include <cmath> // pow()

# define DEFAULT_DATA_SIZE 21
# define PAIR_VAL_AND_ITR std::pair<typename TContainer::value_type, typename TContainer::const_iterator>

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned int uint32;

class PmergeMe
{
public:
	PmergeMe(int ac, char** argv);
	PmergeMe(const PmergeMe& other);
	~PmergeMe(void);

private:
	PmergeMe(void);

private:
	std::vector<uint32> m_containerVec;
	std::deque<uint32> m_containerDeque;
	size_t m_compareCount;

public:
	PmergeMe& operator=(const PmergeMe& rhs);
	std::vector<uint32>& getContainerVec(void);
	const std::vector<uint32>& getContainerVec(void) const;
	std::deque<uint32>& getContainerDeque(void);
	const std::deque<uint32>& getContainerDeque(void) const;

	template <typename TContainer>
	void mergeInsertionSort(TContainer& data, const typename TContainer::size_type chunkScale,
		const typename TContainer::size_type chunkSize, const bool hasRemainder)
	{
		if (chunkSize < 1)
		{
			return ;
		}
		// ここでchunkScale内のbiggest要素をとなりのchunkと比較して小大の順に並べる
		compareChunkAndSwap(data, chunkScale);
		# ifdef DEBUG
			std::cout << "### After compare Chunk ###" << std::endl;
			printContainer(data);
		# endif //DEBUG
		// 再帰から帰ってくると、chunkSize + 1の要素が降順に並んだ状態になっている
		mergeInsertionSort(data, chunkScale * 2, chunkSize / 2, chunkSize % 2);
		// chunkSize * 2の要素数を、一列に並べる。
		if (1 < chunkScale)
			integrateToMainChain<TContainer>(data, chunkScale, chunkSize, (hasRemainder ? 1 : 0));
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

	template <typename TContainer>
	void printContainer(const TContainer& data)
	{
		for (typename TContainer::size_type i = 0; i < data.size(); ++i)
			std::cout << data[i] << " ";
		std::cout << std::endl;
	};

private:
	void addContainerByArgs(int ac, char** argv);

	template <typename TContainer>
	void compareChunkAndSwap(TContainer& data, const typename TContainer::size_type chunkScale)
	{
		// iがさすのは、比較元（chunkLeft）の開始位置
		for (typename TContainer::size_type i = 0; i + (chunkScale * 2) <= data.size(); i += (chunkScale * 2))
		{
			if (!isLittleLeftChunk(data, i + (chunkScale - 1), i + (chunkScale * 2) - 1))
			{
				swapChunk(data, chunkScale, i, i + chunkScale);
			}
		}
	}

	template <typename TContainer>
	bool isLittleLeftChunk(TContainer& data,
		const typename TContainer::size_type iLeftChunkEnd, const typename TContainer::size_type iRightChunkEnd)
	{
		# ifdef DEBUG
			std::cout << "compareChunk: " << data[iLeftChunkEnd] << " vs " << data[iRightChunkEnd] << std::endl;
		# endif //DEBUG
		++m_compareCount;
		if (data[iLeftChunkEnd] <= data[iRightChunkEnd])
			return (true);
		return (false);
	}

	template <typename TContainer>
	void swapChunk(TContainer& data, const typename TContainer::size_type chunkScale,
		const typename TContainer::size_type iLeftChunkStart, const typename TContainer::size_type iRightChunkStart)
	{
		TContainer copyRight(data.begin() + iRightChunkStart, data.begin() + iRightChunkStart + chunkScale);

		data.erase(data.begin() + iRightChunkStart, data.begin() + iRightChunkStart + chunkScale);
		data.insert(data.begin() + iLeftChunkStart, copyRight.begin(), copyRight.end());
	}

	template <typename TContainer>
	void integrateToMainChain(TContainer& data, const typename TContainer::size_type chunkScale,
		const typename TContainer::size_type chunkSize, int hasRemainder)
	{
		typename TContainer::size_type iEnd = getNextIntegratePos<TContainer>(1); //return 1
		std::vector< PAIR_VAL_AND_ITR > tmpMainChain
			= makeTempMainChain(data, chunkScale);
		# ifdef DEBUG
			std::cout << "tmpMainChain: ";
			for (typename std::vector< PAIR_VAL_AND_ITR >::size_type i = 0; i < tmpMainChain.size(); ++i)
				std::cout << *(tmpMainChain[i].second) << " ";
			std::cout << std::endl;
		# endif //DEBUG	

		for (typename TContainer::size_type iIntegrateGroup = 2; iEnd < chunkSize + hasRemainder; ++iIntegrateGroup)
		{
			typename TContainer::size_type iTarget = getNextIntegratePos<TContainer>(iIntegrateGroup) - 1;
			while (iEnd <= iTarget)
			{
				// targetIndexが示すのは、MainChainに挿入したい数値のTContainer上のindex
				typename TContainer::size_type targetIndex = (chunkScale * iTarget) + (chunkScale / 2) - 1;
				# ifdef DEBUG
					std::cout << "iTarget: " << iTarget << ", iEnd: " << iEnd << ", targetIndex: " << targetIndex << ", chunkScale: " << chunkScale << std::endl;
				# endif //DEBUG
				if (iTarget < (chunkSize + hasRemainder))
				{
					typename TContainer::value_type targetVal = data[targetIndex];
					# ifdef DEBUG
						std::cout << "targetVal: " << targetVal << std::endl;
					# endif //DEBUG
					const typename std::vector< PAIR_VAL_AND_ITR >::const_iterator insertPos 
						= recursiveSearchInsertPos<std::vector< PAIR_VAL_AND_ITR > >
							(tmpMainChain.begin(), 
								(targetIndex + 1 < chunkScale * chunkSize ? 
									std::find(
										tmpMainChain.begin(),
										tmpMainChain.end(),
										std::make_pair(
											data[targetIndex + (chunkScale / 2)],
											static_cast<typename TContainer::const_iterator>(data.begin() + targetIndex + (chunkScale / 2)))
									)
									: tmpMainChain.end()
								)
								, std::make_pair(targetVal, data.begin() + targetIndex));
					tmpMainChain.insert(insertPos, std::make_pair(targetVal, data.begin() + targetIndex));
					# ifdef DEBUG
						std::cout << "tmpMainChain: ";
						for (typename std::vector< std::pair<uint32, typename TContainer::const_iterator> >::size_type i = 0; i < tmpMainChain.size(); ++i) std::cout << *(tmpMainChain[i].second) << " ";
						std::cout << std::endl;
					# endif //DEBUG
				}
				--iTarget;
			}
			iEnd = getNextIntegratePos<TContainer>(iIntegrateGroup);
		}
		data = reconstructContainerFromMainChain(data, chunkScale / 2, tmpMainChain);
		# ifdef DEBUG
			std::cout << "reconstruct vec: ";
			printContainer(data);
		# endif //DEBUG
	}

	template <typename TContainer>
	typename TContainer::size_type getNextIntegratePos(const typename TContainer::size_type number)
	{
		return ((std::pow(2, number + 1) + std::pow(-1, number)) / 3);
	}

	template <typename TContainer>
	std::vector< PAIR_VAL_AND_ITR > makeTempMainChain(TContainer& data, const typename TContainer::size_type chunkScale)
	{
		std::vector< PAIR_VAL_AND_ITR > tmpMainChain;

		tmpMainChain.push_back(std::make_pair(data[(chunkScale / 2) - 1], data.begin() + (chunkScale / 2) - 1));
		for (typename TContainer::size_type i = 1; (i * chunkScale - 1) < data.size(); ++i)
		{
			tmpMainChain.push_back(std::make_pair(data[(chunkScale * i) - 1], data.begin() + (chunkScale * i) - 1));
		}
		return (tmpMainChain);
	}

	template <typename T>
	const typename T::const_iterator recursiveSearchInsertPos(const typename T::const_iterator begin,
		const typename T::const_iterator end, const typename T::value_type targetVal)
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
			const typename T::const_iterator middle = begin + ((end - begin) / 2);
			# ifdef DEBUG
				std::cout << "compare: " << (*middle).first << " vs " << targetVal.first << std::endl;
			# endif //DEBUG
			if (targetVal < *middle)
				return (recursiveSearchInsertPos<T>(begin, middle, targetVal));
			else
				return (recursiveSearchInsertPos<T>(middle + 1, end, targetVal));
		}
	}

	template <typename TMainChain>
	std::vector<uint32> reconstructContainerFromMainChain(const std::vector<uint32>& data,
		const typename std::vector<uint32>::size_type& chunkScale, const TMainChain& mainChain)
	{
		std::vector<uint32>	reconstructData;
		unsigned int remainData = data.size() % chunkScale;

		reconstructData.reserve(data.size());
		for (typename std::vector<uint32>::size_type i = 0; i < mainChain.size(); ++i)
		{
			reconstructData.insert(reconstructData.end(), mainChain[i].second - chunkScale + 1, mainChain[i].second + 1);
		}
		if (remainData)
		{
			reconstructData.insert(reconstructData.end(), data.end() - remainData, data.end());
		}
		return (reconstructData);
	}

	template <typename TMainChain>
	std::deque<uint32> reconstructContainerFromMainChain(const std::deque<uint32>& data,
		const typename std::deque<uint32>::size_type& chunkScale, const TMainChain& mainChain)
	{
		std::deque<uint32>	reconstructData;
		unsigned int remainData = data.size() % chunkScale;

		for (typename std::deque<uint32>::size_type i = 0; i < mainChain.size(); ++i)
		{
			reconstructData.insert(reconstructData.end(), mainChain[i].second - chunkScale + 1, mainChain[i].second + 1);
		}
		if (remainData)
		{
			reconstructData.insert(reconstructData.end(), data.end() - remainData, data.end());
		}
		return (reconstructData);
	}

	template <typename T>
	static bool isUnsigned(){ return (false); };

	template <>
	bool isUnsigned<uint8>(){ return (true); };

	template <>
	bool isUnsigned<uint16>(){ return (true); };

	template <>
	bool isUnsigned<uint32>(){ return (true); };

	template <typename T>
	static bool isNumericType(const std::string& literal)
	{
		if (isUnsigned<T>() && (literal.find('-') != std::string::npos))
			return (false);
		std::istringstream iss(literal);
		T val;

		iss >> val;
		if (iss.fail() || !iss.eof())
			return (false);
		return (true);
	};

	template <typename T>
	static T toNumericType(const std::string& literal)
	{
		std::istringstream iss(literal);
		T val;

		iss >> val;
		if (iss.fail() || !iss.eof())
			throw (std::runtime_error("Error: iss.fail() or iss.eof()"));
		return (val);
	};
};

# endif //PMERGEME_HPP
