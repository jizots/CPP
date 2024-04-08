#include "MutantStack.hpp"
#include <iostream>
#include <algorithm>
#include <list>

int main()
{
	std::cout << "---- subject test1 ----" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737); //[...] mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	/*stackの内部では基本的にdequeを利用している。(listやvectorもあるかも、とのこと by cppreference.com)
	そのため上記itの出力はdequeのbegin()に依存して、stackのbottom側が先に出力される*/
	std::stack<int> s(mstack);
	std::cout << std::endl;

	std::cout << "---- my test1 ----" << std::endl;
	std::cout << "## stack s include ##" << std::endl;
	std::cout << "s.size(): " << s.size() << std::endl;
	while (s.size() != 0)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	std::cout << std::endl;

	std::cout << "---- subject test2 ----" << std::endl;
	std::cout << "## Replace MutantStack to std::list##" << std::endl;
	std::list<int> mlist;
	mlist.push_front(5);
	mlist.push_front(17);
	std::cout << "mlist.front(): " << mlist.front() << std::endl;
	mlist.pop_front();
	std::cout << "mlist.size(): " << mlist.size() << std::endl;
	mlist.push_front(3);
	mlist.push_front(5);
	mlist.push_front(737); //[...] mlist.push(0);
	std::list<int>::iterator itl = mlist.begin();
	std::list<int>::iterator itle = mlist.end();
	++it;
	--it;
	while (itl != itle)
	{
		std::cout << *itl << std::endl;
		++itl;
	}
	std::cout << std::endl;

	// std::stack<int> s(mlist);//listとstackは基底クラスも一致してないのでエラーになるわな。
	std::stack<int, std::list<int> > sl(mlist);
	std::cout << "## stack sl include ##" << std::endl;
	while (sl.size() != 0)
	{
		std::cout << sl.top() << std::endl;
		sl.pop();
	}
	std::cout << std::endl;

	std::cout << "---- my test2 ----" << std::endl;
	std::cout << "## const valiable ##" << std::endl;
	const MutantStack<int> m2(mstack);
	MutantStack<int>::const_iterator it2 = m2.begin();
	MutantStack<int>::const_iterator ite2 = m2.end();
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	return 0;
}
