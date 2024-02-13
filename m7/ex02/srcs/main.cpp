#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    std::cout << "--- value entry" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "--- copy assignment" << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    std::cout << "--- comparison" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "--- try catch" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "--- use [] operator" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
        if (i < 5)
            std::cout << numbers[i] << std::endl;// oh.. not overload '<<'
    }

    std::cout << "--- size() function" << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        numbers[i] = rand();
        if (i < 5)
            std::cout << numbers[i] << std::endl;
    }

    delete [] mirror;//
    return 0;
}

__attribute__((destructor))
static void destructor()
{
    system("leaks -q cpp07ex02");
}