#include "iter.hpp"
#include <iostream>

#define ARRAY_SIZE 10
#define DIVISION_SIZE 1

template <typename T>
void	division(T&	num)
{
	num = num / DIVISION_SIZE;
}

template <typename T>
void	strAddition(T&	str)
{
	str = str + "_Add";
}

int main(){
	std::cout << "--- test1 ---" << std::endl;
	int	arrayInt[ARRAY_SIZE];
	for(int i = 0; i < ARRAY_SIZE; ++i)
		arrayInt[i] = i * 3;
	iter(arrayInt, ARRAY_SIZE, division);
	for(int i = 0; i < ARRAY_SIZE; ++i)
		std::cout << arrayInt[i] << std::endl;

	std::cout << "--- test2 ---" << std::endl;
	int*	null = NULL;
	iter(null, 0, division);
	for(int i = 0; i < ARRAY_SIZE; ++i)
		std::cout << arrayInt[i] << std::endl;

	std::cout << "--- test3 ---" << std::endl;
	double	arrayDouble[ARRAY_SIZE];
	for(int i = 0; i < ARRAY_SIZE; ++i)
		arrayDouble[i] = i * 1.5;
	iter(arrayDouble, ARRAY_SIZE, division);
	for(int i = 0; i < ARRAY_SIZE; ++i)
		std::cout << arrayDouble[i] << std::endl;

	std::cout << "--- test4 ---" << std::endl;
	std::string	arrayString[ARRAY_SIZE];
	for(int i = 0; i < ARRAY_SIZE; ++i)
		arrayString[i] = i + '0';
	iter(arrayString, ARRAY_SIZE, strAddition);
	for(int i = 0; i < ARRAY_SIZE; ++i)
		std::cout << arrayString[i] << std::endl;
	
	return (0);
}
