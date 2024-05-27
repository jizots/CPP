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

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned int uint32;

typedef std::vector<uint32> vecContainer;
typedef std::pair<uint32, vecContainer::const_iterator> pairMainChain;
typedef std::vector< pairMainChain > vecMainChain;

class PmergeMe
{
public:
	PmergeMe(int ac, char** argv);
	PmergeMe(const PmergeMe& other);
	~PmergeMe(void);

	vecContainer& getContainerVec(void);
	const vecContainer& getContainerVec(void) const;
	std::deque<uint32>& getContainerDeque(void);
	const std::deque<uint32>& getContainerDeque(void) const;

	void mergeInsertionSortVec(const vecContainer::size_type chunkScale, 
		const vecContainer::size_type chunkSize, const bool hasRemainder);

private:
	PmergeMe(void);

private:
	vecContainer m_containerVec;
	std::deque<uint32> m_containerDeque;
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
	void compareChunkAndSwap(const vecContainer::size_type chunkScale);
	bool isLittleLeftChunk(const vecContainer::size_type iLeftChunkEnd,
		const vecContainer::size_type iRightChunkEnd);
	void swapChunk(const vecContainer::size_type chunkScale,
		const vecContainer::size_type iLeftChunkStart, const vecContainer::size_type iRightChunkStart);
	vecContainer::size_type getNextIntegratePos(const vecContainer::size_type number);
	std::vector< pairMainChain > makeTempMainChain(const vecContainer::size_type chunkScale);
	void integrateToMainChain(const vecContainer::size_type chunkScale,
		const vecContainer::size_type chunkSize, int hasRemainder);
	const vecMainChain::const_iterator recursiveSearchInsertPos(const vecMainChain::const_iterator begin,
		const vecMainChain::const_iterator end, const vecMainChain::value_type targetVal);
	vecContainer buildContainerFromMainchain(const vecContainer::size_type& chunkScale, const vecMainChain& mainChain);

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
