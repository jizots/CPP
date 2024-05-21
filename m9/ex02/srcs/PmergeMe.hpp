#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <sstream>
# include <iostream>
# include <ctime>
# include <iomanip> //setw()
# include <cmath> // pow()

# define DEFAULT_DATA_SIZE 21

class PmergeMe
{
public:
	PmergeMe(int ac, char** argv);
	PmergeMe(const PmergeMe& other);
	~PmergeMe(void);

private:
	PmergeMe(void);

private:
	std::vector<uint32_t> m_containerVec;
	std::deque<uint32_t> m_containerDeque;
	std::clock_t m_startTime;
	size_t m_compareCount;

public:
	PmergeMe& operator=(const PmergeMe& rhs);

private:
	void addContainerByArgs(int ac, char** argv);

	template <typename TContainer>
	void mergeInsertionSort(TContainer& data, const typename TContainer::size_type chunkScale, const typename TContainer::size_type chunkSize, const bool hasRemainder)
	{
		if (chunkSize < 2)
		{
			return ;
		}
		// ここでchunkScale内のbiggest要素をとなりのchunkと比較して小大の順に並べる
		compareChunkAndSwap(data, chunkScale);
printContainer(data);
		// 再帰から帰ってくると、chunkSize + 1の要素が降順に並んだ状態になっている
		mergeInsertionSort(data, chunkScale * 2, chunkSize / 2, chunkSize % 2);
		// chunkSize * 2の要素数を、一列に並べる。
		integrateToMainChain(data, chunkScale, chunkSize, (hasRemainder ? 1 : 0));
	};

	template <typename TContainer>
	void compareChunkAndSwap(TContainer& data, const typename TContainer::size_type chunkScale)
	{
		for (typename TContainer::size_type i = 0; i + (chunkScale * 2) <= TContainer.size(); i += (chunkScale * 2)) // iがさすのは、比較元（chunkLeft）の開始位置
		{
			if (!isLittleLeftChunk(data, chunkScale, i + (chunkScale - 1), i + (chunkScale * 2) - 1))
			{
				swapChunk(data, chunkScale, i, i + chunkScale);
			}
		}
	}

	template <typename TContainer>
	bool isLittleLeftChunk(TContainer& data, const typename TContainer::size_type chunkScale,
		const typename TContainer::size_type iLeftChunkEnd, const typename TContainer::size_type iRightChunkEnd)
	{
std::cout << "compareChunk: " << data[iLeftChunkEnd] << " vs " data[iRightChunkEnd] << std::endl;
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
	typename TContainer::size_type getNextIntegratePos(const typename TContainer::size_type number)
	{
		return ((std::pow(2, number + 1) + std::pow(-1, number)) / 3);
	}

	template <typename TContainer, typename TVal>
	void integrateToMainChain(TContainer& data, const typename TContainer::size_type chunkScale, const typename TContainer::size_type chunkSize, int hasRemainder)
	{
		typename TContainer::size_type iEnd = getNextIntegratePos(1); //return 1
	
		for (typename TContainer::size_type i = 2; iEnd < chunkSize + hasRemainder; ++i)
		{
			typename TContainer::size_type iStart = getNextIntegratePos(i) - 1;
			while (iEnd <= iStart)
			{
				if (iStart < (chunkSize + hasRemainder))
				{
					TVal targetVal = chunkScale * iStart
				// hikaku and insert

				}
				--iStart;
			}
			iEnd = iStart + 1;
		}
	}

	template <typename TContainer>
	void printContainer(const TContainer& data)
	{
		for (typename TContainer::size_type i = 0; i < data.size(); ++i)
			std::cout << data[i] << " ";
		std::cout << std::endl;
	};

	template <typename T>
	const typename std::vector<T>::const_iterator recursiveSearchInsertPos(const typename std::vector<T>::const_iterator begin,
		const typename std::vector<T>::const_iterator end, const T targetVal)
	{
		if (begin == end)
			return (begin);
		else if ((end - begin) == 1)
		{
std::cout << "compare: " << (*begin).first << " vs " << targetVal.first << std::endl;
			++m_compareCount;
			if (targetVal < *begin)
				return (begin);
			else
				return (begin + 1);
		}
		else
		{
			++m_compareCount;
			const typename std::vector<T>::const_iterator middle = begin + ((end - begin) / 2);
std::cout << "compare: " << (*middle).first << " vs " << targetVal.first << std::endl;
			if (targetVal < *middle)
				return (recursiveSearchInsertPos<T>(begin, middle, targetVal));
			else
				return (recursiveSearchInsertPos<T>(middle + 1, end, targetVal));
		}
	}

	template <typename T>
	void binarySearchInsertionSort(std::vector<T>& vec)
	{
		for (typename std::vector<T>::size_type index = 1; index < vec.size() - 1; ++index)
		{
			T valueToMove = vec[index];
			const typename std::vector<T>::const_iterator insertPos = recursiveSearchInsertPos<T>(vec.begin(), vec.begin() + index, valueToMove);
			vec.erase((vec.begin() + index));
			vec.insert(insertPos, valueToMove);
printPairContainer(m_pairContainer);
		}
	}

	template <typename T>
	static bool isUnsigned(){ return (true); };

	template <>
	bool isUnsigned<uint8_t>(){ return (true); };

	template <>
	bool isUnsigned<uint16_t>(){ return (true); };

	template <>
	bool isUnsigned<uint32_t>(){ return (true); };

	template <>
	bool isUnsigned<uint64_t>(){ return (true); };

	template <typename T>
	static bool isNumericType(const std::string& literal)
	{
		if (isUnsigned<T>() && literal.find('-') != std::string::npos)
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
			throw ("Error: Argument is invalid literal => " + literal);
		return (val);
	};
};

#endif