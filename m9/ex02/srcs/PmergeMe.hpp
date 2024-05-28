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

class PmergeMe
{
public:
	typedef unsigned char uint8;
	typedef unsigned short int uint16;
	typedef unsigned int uint32;

	typedef std::vector<uint32> vecContainer;
	typedef std::pair<uint32, vecContainer::const_iterator> pairMainChain;
	typedef std::vector< pairMainChain > vecMainChain;

	typedef std::deque<uint32> deqContainer;
	typedef std::pair<uint32, deqContainer::const_iterator> pairMainChainDeq;
	typedef std::deque< pairMainChainDeq > deqMainChain;

public:
	PmergeMe(int ac, char** argv);
	PmergeMe(const PmergeMe& other);
	~PmergeMe(void);

	vecContainer& getContainerVec(void);
	const vecContainer& getContainerVec(void) const;
	deqContainer& getContainerDeque(void);
	const deqContainer& getContainerDeque(void) const;

	template <typename TContainer>
	void mergeInsertionSort(TContainer& data, const vecContainer::size_type chunkScale,
		const vecContainer::size_type chunkSize, const bool hasRemainder)
	{
		if (chunkSize < 1)
			return ;
		// ここでchunkScale内のbiggest要素をとなりのchunkと比較して小大の順に並べる
		compareChunkAndSwap(data, chunkScale);
		# ifdef DEBUG
			std::cout << "### After compare Chunk ###" << std::endl;
			printContainer(m_containerVec);
		# endif //DEBUG
		// 再帰から帰ってくると、chunkSize + 1の要素が降順に並んだ状態になっている
		mergeInsertionSort(data, chunkScale * 2, chunkSize / 2, chunkSize % 2);
		// chunkSize * 2の要素数を、一列に並べる。
		if (1 < chunkScale)
			integrateToMainChain(data, chunkScale, chunkSize, (hasRemainder ? 1 : 0));
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

private:	
	PmergeMe(void);

private:
	vecContainer m_containerVec;
	deqContainer m_containerDeque;
	size_t m_compareCount;

public:
	PmergeMe& operator=(const PmergeMe& rhs);

	template <typename TContainer>
	void printContainer(const TContainer& data)
	{
		for (typename TContainer::size_type i = 0; i < data.size(); ++i)
			std::cout << data[i] << " ";
		std::cout << std::endl;
	};

private:
	void addContainerByArgs(int ac, char** argv);
	vecMainChain makeTempMainChain(const vecContainer& data, const vecContainer::size_type chunkScale);
	deqMainChain makeTempMainChain(const deqContainer& data, const deqContainer::size_type chunkScale);
	void integrateToMainChain(vecContainer& data, const vecContainer::size_type chunkScale,
		const vecContainer::size_type chunkSize, int hasRemainder);
	void integrateToMainChain(deqContainer& data, const deqContainer::size_type chunkScale,
		const deqContainer::size_type chunkSize, int hasRemainder);
	vecContainer buildContainerFromMainchain(const vecContainer& data,
		const vecContainer::size_type& chunkScale, const vecMainChain& mainChain);
	deqContainer buildContainerFromMainchain(const deqContainer& data,
		const deqContainer::size_type& chunkScale, const deqMainChain& mainChain);

	template <typename TContainer>
	void compareChunkAndSwap(TContainer& data, const typename TContainer::size_type chunkScale)
	{
		// iがさすのは、比較元（chunkLeft）の開始位置
		for (typename TContainer::size_type i = 0; i + (chunkScale * 2) <= data.size(); i += (chunkScale * 2))
		{
			if (!isLittleLeftChunk(data, i + (chunkScale - 1), i + (chunkScale * 2) - 1))
				swapChunk(data, chunkScale, i, i + chunkScale);
		}
	}

	template <typename TContainer>
	bool isLittleLeftChunk(TContainer& data, const typename TContainer::size_type iLeftChunkEnd,
		const typename TContainer::size_type iRightChunkEnd)
	{
		# ifdef DEBUG
			std::cout << "compareChunk: " << data[iLeftChunkEnd] << " vs " 
				<< data[iRightChunkEnd] << std::endl;
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
	typename TContainer::size_type getNextIntegratePos(const typename TContainer::size_type number)
	{
		return ((std::pow(2, number + 1) + std::pow(-1, number)) / 3);
	}

	template <typename TMainChain>
	const typename TMainChain::const_iterator recursiveSearchInsertPos(const typename TMainChain::const_iterator begin,
		const typename TMainChain::const_iterator end, const typename TMainChain::value_type targetVal)
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
			const typename TMainChain::const_iterator middle = begin + ((end - begin) / 2);
			# ifdef DEBUG
				std::cout << "compare: " << (*middle).first << " vs " << targetVal.first << std::endl;
			# endif //DEBUG
			if (targetVal < *middle)
				return (recursiveSearchInsertPos<TMainChain>(begin, middle, targetVal));
			else
				return (recursiveSearchInsertPos<TMainChain>(middle + 1, end, targetVal));
		}
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
