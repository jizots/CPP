#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <fstream>
#include <sstream>

#define SIZE_DATA 10

int compairCount = 0;

template <typename T>
bool compairVec(const std::vector<T>& vec1, const std::vector<T>& vec2)
{
	if (vec1.size() != vec2.size())
	{
		std::cout << "[Error] vector size is different" << std::endl;
		return (false);
	}
	for (typename std::vector<T>::size_type i = 0; i < vec1.size(); ++i)
	{
		if (vec1[i] != vec2[i])
			return (false);
	}
	return (true);
}

template <typename T>
const typename std::vector<T>::const_iterator recursiveSearchInsertPos(const typename std::vector<T>::const_iterator begin,
	const typename std::vector<T>::const_iterator end, const T targetVal)
{
	if (begin == end)
		return (begin);
	else if ((end - begin) == 1)
	{
		++compairCount;
		if (targetVal < *begin)
			return (begin);
		else
			return (begin + 1);
	}
	else
	{
		++compairCount;
		const typename std::vector<T>::const_iterator middle = begin + ((end - begin) / 2);
		std::cout << "compair: " << *middle << " vs " << targetVal << std::endl;
		if (targetVal < *middle)
			return (recursiveSearchInsertPos<T>(begin, middle, targetVal));
		else
			return (recursiveSearchInsertPos<T>(middle + 1, end, targetVal));
	}
}

template <typename T>
void binarySearchInsertionSort(std::vector<T>& vec)
{
	for (typename std::vector<T>::size_type index = 1; index < vec.size(); ++index)
	{
		T valueToMove = vec[index];
		const typename std::vector<T>::const_iterator insertPos = recursiveSearchInsertPos<T>(vec.begin(), vec.begin() + index, valueToMove);
		vec.erase((vec.begin() + index));
		vec.insert(insertPos, valueToMove);
		for (int i = 0; i < vec.size(); ++i) std::cout << vec[i] << " ";
		std::cout << std::endl;
	}
}

int main(int ac, char **av)
{
	std::srand((unsigned int) std::time(NULL));
	// std::vector<unsigned int> before {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};//c++11
	std::vector<unsigned int> before {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};//c++11

	// std::vector<unsigned int> before;//ソートしたい元データ
	// for (int i = 0; i < SIZE_DATA; ++i)//元データにランダムな数値を挿入
	// 	before.push_back(std::rand() / 100000);
	
	std::cout << "Before sort: " << std::endl;
	for (int i = 0; i < SIZE_DATA; ++i)
		std::cout << before[i] << " ";
	std::cout << std::endl;

	std::vector<unsigned int> copyVec1(before);
	binarySearchInsertionSort<unsigned int>(copyVec1);

	std::cout << "After sort: " << std::endl;
	for (int i = 0; i < SIZE_DATA; ++i)
		std::cout << copyVec1[i] << " ";
	std::cout << std::endl;

	std::vector<unsigned int> copyVec2(before);
	std::sort(copyVec2.begin(), copyVec2.end());

	std::cout << "compairCount: " << compairCount << std::endl;
	//自作ソートと、std::sortの結果を比較
	if (compairVec(copyVec1, copyVec2))
	{
		std::cout << "success" << std::endl;
		return (EXIT_SUCCESS);
	}
	else
	{
		std::cout << "fail" << std::endl;
		return (EXIT_FAILURE);
	}
}
