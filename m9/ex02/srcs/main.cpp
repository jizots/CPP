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

/* [compair] big numbers and mergeSort ペアの大きい方の数値を比較して、マージインサーションソート(過程は以下に続く)する*/
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
// [2  1]グループの右側から2分探索して挿入します。
// この時、8のペアである10よりも小さい9以下の数値で、均等な2分木の場合のルートから2分探索します(in-order traversalでソートされた状態)
// つまりこの場合、揷入したい数値の8は最初に7と比較、次に9と比較して揷入位置の特定が完了します。

// なんで右側からなの？というと、たぶん、2分探索で比較する要素数が一定になるように、かな。例えば以下のように
//  3  4  5
//       [2  1]
// となっていた場合、2を先に挿入すると、比較する要素数が2つなので比較回数2回で　2 3 4 5になります。そして1を挿入すると、比較する要素数が4つなので比較回数3回で 1 2 3 4 5となります。合計5回の比較です。
// これを、1を先に挿入すると、比較する要素数が3つなので比較回数2回で　1 3 4 5になります。そして2を挿入すると、比較する要素数が3つなので比較回数2回で 1 2 3 4 5となります。合計4回の比較です。
// このように2分探索で比較する要素数が、挿入順によって変わらない（増加しない）ようにするために、いい感じのグループでくくっているのでしょう。

/*
n       =  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17
log(n!) =  0  1  3  5  7 10 13 16 19 22 26 29 33 37 41 45 49
B(n)    =  0  1  3  5  8 11 14 17 21 25 29 33 37 41 45 49 54
L(n)    =  0  1  3  5  9 11 14 17 25 27 30 33 38 41 45 49 65
*/

