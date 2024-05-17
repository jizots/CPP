#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <sstream>
# include <iostream>
# include <ctime>
# include <iomanip> //setw()

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
	std::vector<std::pair<int64_t, int64_t> > m_pairContainer;

public:
	PmergeMe& operator=(const PmergeMe& rhs);

private:
	void addContainerByArgs(int ac, char** argv);
	void mergeInsertionSort();
	void paitMakeAndCompare();
	void pairBinaryInsertionSort();

	template <typename TContainer>
	void printContainer(const TContainer& data)
	{
		for (typename TContainer::size_type i = 0; i < data.size(); ++i)
			std::cout << data[i] << " ";
		std::cout << std::endl;
	};

	template <typename TContainer>
	void printPairContainer(const TContainer& data)
	{
		for (typename TContainer::size_type i = 0; i < data.size(); ++i)
			std::cout << std::setw(2) << data[i].first << " ";
		std::cout << std::endl;
		for (typename TContainer::size_type i = 0; i < data.size(); ++i)
			std::cout << std::setw(2) << data[i].second << " ";
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