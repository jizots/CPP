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
void insertionSort(std::vector<T>& vec)
{
	// 要素を1つづつ走査（i）
	for (typename std::vector<T>::size_type i = 1; i < vec.size(); ++i)
	{
		// vec[i]と、それより前方にある要素を比較するためのインデックス(j)
		typename std::vector<T>::size_type j = i;
		// 1つ前方の要素と比較し、前方の方が大きければswapする
		while (j > 0 && vec[j - 1] > vec[j])
		{
			std::swap(vec[j - 1], vec[j]);
			--j; // インデックスをデクリメントして、次はさらに前の要素と比較する
			++compairCount;
		}
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
	insertionSort<unsigned int>(copyVec1);

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
