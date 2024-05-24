#include "PmergeMe.hpp"
#include <iostream>

template <typename T>
bool compairVec(const T& vec1, const T& vec2)
{
	if (vec1.size() != vec2.size())
	{
		std::cout << "fail at size: " << vec1.size() << " vs " << vec2.size() << "(std::sort)" << std::endl;
		return (false);
	}
	for (typename std::vector<T>::size_type i = 0; i < vec1.size(); ++i)
	{
		if (vec1[i] != vec2[i])
		{
			std::cout << "fail at element: " << vec1[i] << " vs " << vec2[i] << "(std::sort)" << std::endl;
			return (false);
		}
	}
	return (true);
}

template <typename P, typename T1, typename T2>
int mysortVSstdsort(P data1, T1 copyContainerVec, T2 copyContainerDeque)
{
	std::cout << "--- my::sort vs std::sort ---" << std::endl;
	std::sort(copyContainerVec.begin(), copyContainerVec.end());
	std::sort(copyContainerDeque.begin(), copyContainerDeque.end());
	std::cout << "-- part Vector --" << std::endl;
	if (compairVec(data1.getContainerVec(), copyContainerVec))
	{
		std::cout << "success" << std::endl;
		return (EXIT_SUCCESS);
	}
	else
	{
		std::cout << "fail" << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout << "-- part Deque --" << std::endl;
	if (compairVec(data1.getContainerDeque(), copyContainerDeque))
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

int	main(int ac, char** argv)
{
	try
	{
		PmergeMe data1(ac, argv);

			std::vector<uint32_t> copyContainerVec = data1.getContainerVec();
			std::deque<uint32_t> copyContainerDeque = data1.getContainerDeque();

		data1.mergeInsertionSort(data1.getContainerVec(), 1, data1.getContainerVec().size(), false);

		//自作ソートと、std::sortの結果を比較
		return (mysortVSstdsort(data1, copyContainerVec, copyContainerDeque));
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

/* 1. initial 1~21 をランダムに配置*/
//  21 1 13 2 17 3 12 4 20 5 15 6 19 7 14 8 18 9 16 10 11

/* 2. make pair 横に並んでる数値でペアを作成*/
// 21 13 17 12 20 15 19 14 18 16    <- MainChain
//  1  2  3  4  5  6  7  8  9 10 11

/* 3. [compair] pair ペア間で大きい方の数値を比較して、片側（以下では上側）に寄せる*/
// 21 13 17 12 20 15 19 14 18 16    <- MainChain
//  1  2  3  4  5  6  7  8  9 10 11

/* 4. ペアの大きい方の数値で、2と3を、要素が1つになるまで繰り返す*/
// ペアを作成して、大きい方の数値を上側へ（2回目）
// 21 17 20 19 18    <- MainChain
// 13 12 15 14 16

// ペアを作成して、大きい方の数値を上側へ（3回目）
// 21 20    <- MainChain
// 17 19 18

// ペアを作成して、大きい方の数値を上側へ（4回目）
// 21    <- MainChain
// 20

// 21 繰り返し終了
// この時点で、私の期待ではベクター内は、8 14 7 19 6 15 5 20 4 12 3 17 2 13 1 21 10 16 9 18 11 となっている。

/* 5. ヤコブスタール数を用いて、並んでいない要素を2分挿入する*/
// この時、グループにするべき要素数より少ない場合は、少ないことを気にせずにグループにして良い。
// (2^(k+1) + (-1)^k) / 3 で、グループの中で最初に2分木挿入するインデックスを求めている。
// Befor: 8 14 7 [19] 6 15 5 [20] 4 12 3 17 2 13 1 [21] 10 16 9 18 11 , chunkScale: 8
// 19 20 21    <- MainChain
//      [17 18]
// Befor: 10 12 9 [13] 8 14 7 [15] 6 16 5 [17] 4 18 3 19 2 20 1 [21] 22 , chunkScale: 8
// 13 15 17 21    <- MainChain
//         [19   ]
// -> 13 15 17 19 21    <- MainChain

// Befor: 10 [12] 9 [13] 8 14 7 [15] 6 16 5 [17] 4 18 3 [19] 2 20 1 [21] 22 , chunkScale: 4
// 12  13  15  17  19  21    <- MainChain
//        [14  16][18  20]
// 12  13  15  16  17  19  21    <- MainChain
//        [14    ]    [18  20]
// 12  13  14  15  16  17  19  21    <- MainChain
//            [      ]    [18  20]
// 12  13  14  15  16  17  19  20  21    <- MainChain
//            [      ]    [18    ]



//  10  12  13  14  15  16  17  18  19  20  21
//        [ 9   8][ 7   6][ 5   4   3   2   1  22]
// [9  8]グループの右側から2分探索して挿入します。
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

