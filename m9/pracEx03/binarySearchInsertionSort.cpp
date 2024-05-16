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

#define SIZE_DATA 21

int compairCount = 0;

template <typename T>
bool compairVec(std::vector<T>& vec1, std::vector<T>& vec2)
{
	if (vec1.size() != vec2.size())
		return (false);
	for (typename std::vector<T>::size_type i = 0; i < vec1.size(); ++i)
	{
		if (vec1[i] != vec2[i])
			return (false);
	}
	return (true);
}

template <typename T>
typename std::vector<T>::iterator recursiveSearchInsertPos(typename std::vector<T>::iterator begin,
	typename std::vector<T>::iterator end, const T val)
{

}

template <typename T>
void binarySearchInsertionSort(std::vector<T>& vec)
{
	for (typename std::vector<T>::iterator itr = vec.begin() + 1; itr < vec.size(); ++itr)
	{
		T valueToMove = *itr;
		typename std::vector<T>::iterator insertPos = recursiveSerchInsertPos(vec.begin(), itr, valueToMove);
		// itrの値をvectorから除去する
		// valueToMoveを正しい位置に挿入する　
	}
}

int main(int ac, char **av)
{
	std::srand((unsigned int) std::time(NULL));
	// std::vector<unsigned int> before {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};//c++11

	std::vector<unsigned int> before;//ソートしたい元データ
	for (int i = 0; i < SIZE_DATA; ++i)//元データにランダムな数値を挿入
		before.push_back(std::rand());
	
	std::cout << "Before sort: " << std::endl;
	for (int i = 0; i < SIZE_DATA; ++i)
		std::cout << before[i] << " ";
	std::cout << std::endl;

	std::vector<unsigned int> copyVec1(before);
	// binarySearchInsertionSort<unsigned int>(copyVec1);

	std::cout << "After sort: " << std::endl;
	for (int i = 0; i < SIZE_DATA; ++i)
		std::cout << copyVec1[i] << " ";
	std::cout << std::endl;

	std::vector<unsigned int> copyVec2(before);
	std::sort(copyVec2.begin(), copyVec2.end());

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