#include "PmergeMe.hpp"
#include <iostream>

int	main(int ac, char** argv)
{
	try
	{
		PmergeMe data1(ac, argv);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return (1);
	}
	catch(const std::string& e)
	{
		std::cout << e << '\n';
		return (1);
	}
}


// Tool
//  https://jp.piliapp.com/random/number/ 乱数ジェネレーター
// Background knowledge
//  Jacobsthal number: J(0) = 0, J(1) = 1, J(n) = J(n-1) + (J(n-2) * 2) -> 0,1,1,3,5,11,21,43, J(8) = 85,…
// https://warwick.ac.uk/fac/sci/dcs/teaching/material-archive/cs341/fj.pdf

/* initial 1~21 をランダムに配置*/
//  9 2 16 21 20 18 15 13 5 7 10 8 14 3 1 17 19 6 4 11 12

/* make pair 横に並んでる数値でペアを作成*/
//  9 16 20 15  5 10 14  1 19  4 12
//  2 21 18 13  7  8  3 17  6 11

/* [compair] pair ペア間で大きい方の数値を比較して、片側（以下では上側）に寄せる*/
//  9 21 20 15  7 10 14 17 19 11
//  2 16 18 13  5  8  3  1  6  4 12

/* [compair] big numbers and mergeSort ペアの大きい方の数値を比較して、マージソート(過程は省略)する*/
//  7  9 10 11 14 15 17 19 20 21
//  5  2  8  4  3 13  1  6 18 16 12
// この時、上の列はソートされた状態になります。さらに下の列の左端(5)を含めてもソートされています。

/* [compair] ソートされていない要素(下の列)をJacobsthalの2倍の数でグループにする*/
//  5  7  9 10 11 14 15 17 19 20 21
//       [2  8][4 3][13  1  6 18 16 12]
// この時、グループにするべき要素数より少ない場合は、少ないことを気にせずにグループにして良い。
// (2^(k+1) + (-1)^k) / 3 で、グループの中で最初に2分木挿入するインデックスを求めている。

//  5  7  8  9 10 11 14 15 17 19 20 21
//          [2   ][4 3][13  1  6 18 16 12]
// [2  1]グループの右側を2分木探索して挿入します。
// この時、1のペアである10よりも小さい9との比較からではなく、均等な2分木の場合のルートから2分木探索する(in-order traversalでソートされた状態)
// なんで右側からなの？というと、ワンチャン、9  10 の間に入る数値だった場合（今回は違いました）、次の2を比較する回数が減るかもしれないから、かな？
