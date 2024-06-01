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
# include <ctime>


#define SIZE_DATA 100000

template <typename T>
void insertToContainer(T& container)
{
	for (int i = 0; i < SIZE_DATA; ++i)
	{
		container.push_back(i);
	}
}

template <typename T>
void eraseAndInsert(T& container)
{
	for (int i = 0; i < SIZE_DATA / 100; ++i)
	{
		T containerTmp(container.begin() + SIZE_DATA / 2, container.end());
		container.erase(container.begin() + SIZE_DATA / 2, container.end());
		container.insert(container.begin(), containerTmp.begin(), containerTmp.end());
	}
}


int main(void)
{
	std::vector<int> vec;
	std::deque<int> deq;

	std::cout << "### Time need to execute push_back ###" << std::endl;
	clock_t start = clock();
	insertToContainer(vec);
	std::cout << std::fixed << "time(vector): " << ((double)(clock() - start) / CLOCKS_PER_SEC) * 1000000 << std::endl;

	start = clock();
	insertToContainer(deq);
	std::cout<< "time(deque) : " << ((double)(clock() - start) / CLOCKS_PER_SEC) * 1000000 << std::endl;

	std::cout << "### Time need to execute erase & insert ###" << std::endl;
	start = clock();
	eraseAndInsert(vec);
	std::cout<< "time(vector): " << ((double)(clock() - start) / CLOCKS_PER_SEC) * 1000000 << std::endl;

	start = clock();
	eraseAndInsert(deq);
	std::cout<< "time(deque) : " << ((double)(clock() - start) / CLOCKS_PER_SEC) * 1000000 << std::endl;

	return 0;
}