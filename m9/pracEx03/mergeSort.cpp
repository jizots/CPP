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
//coding with c++98
#include <stdio.h>

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
T popFromVector(std::vector<T>& vec)
{
	T tmp(vec.front());

	vec.erase(vec.begin());
	return (tmp);
}

// 2つの要素の集合(それぞれはソート済み)を、ソートしながら(仮想的に)マージする。
// result: 2つの要素の集合を含む配列。マージした結果もここに格納される。
// startLeft: result配列の中で、1つ目の要素の集合の開始インデント。
// middle: result配列の中で、1つ目の要素の集合の終了インデント。かつ +1 で2つ目の要素の集合の開始インデントとなる。
// endRight: result配列の中で、2つ目の要素の集合の終了インデント。
template <typename T>
void mergeVector(std::vector<T>& result, unsigned int startLeft, unsigned int middle, unsigned int endRight)
{
	// 1つ目の要素の集合（vecLeft）と2つ目の要素の集合（vecRight）をそれぞれresultからコピーする。それぞれの集合はソート済みである。（集合の要素が1つの場合もある）
	std::vector<T> vecLeft(result.begin() + startLeft, result.begin() + middle + 1);//2つめの引数の+1が意味するのは、最後の要素の次の要素(≒end())
	std::vector<T> vecRight(result.begin() + middle + 1, result.begin() + endRight + 1);

	unsigned int iLeft = 0; // vecLeftを走査するためのインデックス
	unsigned int iRight = 0; // vecRightを走査するためのインデックス
	unsigned int index = startLeft; // resultにデータを書き込むためのインデックス
	// vecLeft or vecRightを走査し終わるまで、それぞれのインデックスの要素を比較
	while (iLeft < vecLeft.size() && iRight < vecRight.size())
	{
		++compairCount;
		if (vecLeft[iLeft] <= vecRight[iRight])
			result[index++] = vecLeft[iLeft++]; //vecLeftの要素の方が小さければresultに挿入。そしてvecLeftを走査するインデックスをインクリメント
		else
			result[index++] = vecRight[iRight++];
	}

	// vecLeftが走査し終わっていなければ、vecLeftの残りの要素をresultに挿入
	while (iLeft < vecLeft.size())
	{
		result[index++] = vecLeft[iLeft++];
		// ++compairCount;
	}
	// vecRight 〃
	while (iRight < vecRight.size())
	{
		result[index++] = vecRight[iRight++];
		// ++compairCount;
	}
}

//要素の集合を再帰的に分割する
//vec: マージソートを行う要素の配列で、分割や併合は発生しないのでいつも同じベクターを参照している。
//left: vecを（仮想的に）分割した集合の左端のインデント
//right: vecを（仮想的に）分割した集合の右端のインデント
template <typename T>
void mergeSort(std::vector<T>& vec, unsigned int left, unsigned int right)
{
	if (left < right) // left == rightになった時は、要素が1つになっているので、それ以上は分割しない
	{
		// leftとrightの中間地点のインデックスを求める。
		// middleを利用することで、①集合を半分ずつに分割し、②分割した集合をマージするときの集合間の目印とする
		unsigned int middle = left + (right - left) / 2;

		mergeSort(vec, left, middle);//集合の左半分を、再帰的に（仮想）分割する
		mergeSort(vec, middle + 1, right);// 〃 右半分 〃

		// ここにきたとき、要素（left - right + 1）は2つ以上で、かつ、middleとmiddle + 1、を境にソートされた集合になっている。
		mergeVector(vec, left, middle, right);
	}
}

int main(int ac, char **av)
{
	std::srand((unsigned int) std::time(NULL));
	// std::vector<unsigned int> before {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};//c++11

	std::vector<unsigned int> before;//ソートしたい元データ
	for (int i = 0; i < SIZE_DATA; ++i)//元データにランダムな数値を挿入
		before.push_back(std::rand());

	//元データを出力
	std::cout << "Before sort: " << std::endl;
	for (int i = 0; i < SIZE_DATA; ++i)
		std::cout << before[i] << " ";
	std::cout << std::endl;

	//自作マージソートのために、元データをコピー
	std::vector<unsigned int> copyVec1(before);
	//自作マージソートの実行
	mergeSort(copyVec1, 0, copyVec1.size() - 1);

	//ソート後のデータを出力
	std::cout << "After sort: " << std::endl;//元データを出力
	for (int i = 0; i < SIZE_DATA; ++i)
		std::cout << copyVec1[i] << " ";
	std::cout << std::endl;

	//マージソートが正しく実行できているかを確認するために、std::sortで元データをソート
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
