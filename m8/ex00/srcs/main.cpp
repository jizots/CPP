#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

/* https://learn.microsoft.com/ja-jp/cpp/standard-library/stl-containers?view=msvc-170 */

int	main(){
	std::cout << "---- test1 ----" << std::endl;
	//make vector data structures
	std::vector<int>	iv;
	for (int i = -5; i < 5 ; ++i)
		iv.push_back(i);
	//make list data structures
	std::list<int>		il;
	for (int i = 4; i < 15 ; ++i)
		il.push_back(i);
	int					ia[10];
	// for (int i = 0; i < 10 ; ++i)
	// 	ia[i] = i;
	// verify Easyfind Function
	int target = 4;
	std::cout << easyfind<std::vector<int>, int>(iv, target) << std::endl;
	std::cout << easyfind<std::list<int>, int>(il, target) << std::endl;
	// std::cout << easyfind<int*, int>(il, target) << std::endl; //make error
	std::cout << "---- test2 ----" << std::endl;
	return 0;
}