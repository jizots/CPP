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
	bool vecResult = compairVec(data1.getContainerVec(), copyContainerVec);
	std::cout << (vecResult ? "success" : "fail") << std::endl;
	if (!vecResult)
		return (EXIT_FAILURE);

	std::cout << "-- part Deque --" << std::endl;
	bool deqResult = compairVec(data1.getContainerDeque(), copyContainerDeque);
	std::cout << (deqResult ? "success" : "fail") << std::endl;
	if (!deqResult)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}

int	main(int ac, char** argv)
{
	try
	{
		PmergeMe data1(ac, argv);

		std::clock_t save;
		PmergeMe::vecContainer copyContainerVec = data1.getContainerVec();
		PmergeMe::deqContainer copyContainerDeque = data1.getContainerDeque();

		// time start
		save = std::clock();
		// sort
		data1.mergeInsertionSortVec(1, data1.getContainerVec().size(), false);
		// time end
		double duration = static_cast<double>(std::clock() - save) / CLOCKS_PER_SEC;
		std::cout << "After:  ";
		data1.printContainer(data1.getContainerVec());
		// time to sort
		std::cout << "Time to process a range of " <<  data1.getContainerVec().size() << " elements with std::vector : " << duration * 1000000 << " us(microsecond)" << std::endl;

		// time start
		save = std::clock();
		// sort
		// data1.mergeInsertionSort(data1.getContainerDeque(), 1, data1.getContainerDeque().size(), false);
		// time end
		duration = static_cast<double>(std::clock() - save) / CLOCKS_PER_SEC;
		// time to sort
		std::cout << "Time to process a range of " <<  data1.getContainerDeque().size() << " elements with std::deque : " << duration * 1000000 << " us(microsecond)" << std::endl;


		// compare mySort vs std::sort for verify sorted or not
		return (mysortVSstdsort(data1, copyContainerVec, copyContainerDeque));
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return (1);
	}
	return (0);
}


// Tool
//  https://jp.piliapp.com/random/number/ 乱数ジェネレーター
// Background knowledge
//  Jacobsthal number: J(0) = 0, J(1) = 1, J(n) = J(n-1) + (J(n-2) * 2) -> 0,1,1,3,5,11,21,43, J(8) = 85,…
// copy of Merge-Insertion Sort Document(42tokyoの書籍に日本語版もある)
//	https://warwick.ac.uk/fac/sci/dcs/teaching/material-archive/cs341/fj.pdf

/* 1. initial 1~21 をランダムに配置*/
	//  1 21 13 2 17 3 12 4 20 5 15 6 19 7 14 8 18 9 16 10 11

/* 2. make pair 横に並んでる数値でペアを作成*/
	//  1 13 17 12 20 15 19 14 18 16    <- MainChain
	// 21  2  3  4  5  6  7  8  9 10 11

/* 3. [compair] pair ペア間で大きい方の数値を比較して、片側（以下では上側）に寄せる（1回目）*/
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

	// 要素が1つになったので(ペアが作成できないので)繰り返し終了
	// 21    <- MainChain
	// この時点で、私の期待ではベクター内は、8 14 7 19 6 15 5 20 4 12 3 17 2 13 1 [21] 10 16 9 18 11 となっている。

/* 5. ヤコブスタール数を用いて、並んでいない要素を2分挿入する*/
	// この時、グループにするべき要素数より少ない場合は、少ないことを気にせずにグループにして良い。
	// (2^(k+1) + (-1)^k) / 3 で、グループ(k)の中で最初に2分木挿入するインデックスを求めている。

	// Befor: 8 14 7 [19] 6 15 5 [20] 4 12 3 17 2 13 1 [21] 10 16 9 18 11 , chunkScale: 8
	// 19 20 21    <- MainChain
	//      [17 18]
	// [17  18]グループの右側から2分探索して挿入します。
	// この時、18のペアはないので、MainChainの最大値21以下の数値で、均等な2分木の場合のルートから2分探索します(in-order traversalでソートされた状態)
	// つまりこの場合、揷入したい数値の18は最初に20と比較、次に19と比較して揷入位置の特定が完了します。

	// なんで右側からなの？というと、たぶん、2分探索で比較する要素数が一定になるように。例えば以下のように
	//  3  4  5
	//       [2  1]
	// となっていた場合、2を先に挿入すると、比較する要素数が2つなので比較回数2回で　2 3 4 5になります。そして1を挿入すると、比較する要素数が4つなので比較回数3回で 1 2 3 4 5となります。合計5回の比較です。
	// これを、1を先に挿入すると、比較する要素数が3つなので比較回数2回で　1 3 4 5になります。そして2を挿入すると、比較する要素数が3つなので比較回数2回で 1 2 3 4 5となります。合計4回の比較です。
	// このように2分探索で比較する要素数が、挿入順によって変わらない（増加しない）ようにするために、いい感じのグループでくくっているのでしょう。

	// Befor: 10 16 9 [18] 8 14 7 [19] 6 15 5 [20] 4 12 3 17 2 13 1 [21] 11 , chunkScale: 8
	// 18 19 20 21    <- MainChain
	//         [17   ]
	// -> 17 18 19 20 21    <- MainChain

	// Befor: 4 [12] 3 [17] 10 16 9 [18] 8 14 7 [19] 6 15 5 [20] 2 13 1 [21] 11 , chunkScale: 4
	// 12  17  18  19  20  21    <- MainChain
	//        [16  14][15  13]
	// 12  14  17  18  19  20  21    <- MainChain
	//            [16    ][15  13]
	// 12  14  16  17  18  19  20  21    <- MainChain
	//                [      ][15  13]
	// 12  13  14  16  17  18  19  20  21    <- MainChain
	//                    [      ][15    ]
	// -> 12  13  14  15  16  17  18  19  20  21    <- MainChain

	// Before: [4] [12] 2 [13] 8 [14] 6 [15] 10 [16] 3 [17] 9 [18] 7 [19] 5 [20] 1 [21] 11
 	//   4  12  13  14  15  16  17  18  19  20  21    <- MainChain
	//         [ 2   8][ 6  10][ 3   9   7   5   1  11]

/*
n       =  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17
log(n!) =  0  1  3  5  7 10 13 16 19 22 26 29 33 37 41 45 49
B(n)    =  0  1  3  5  8 11 14 17 21 25 29 33 37 41 45 49 54
L(n)    =  0  1  3  5  9 11 14 17 25 27 30 33 38 41 45 49 65
*/
