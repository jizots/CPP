#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::getline(std::cin, s); // 標準入力から 1 行を読み込む
	std::cout << s << '\n';
	std::cout << s.size() << '\n';
}