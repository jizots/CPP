#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack(void);
	MutantStack(const MutantStack& other);
	~MutantStack(void);

	iterator		begin(void);
	const_iterator	begin(void) const;
	iterator		end(void);
	const_iterator	end(void) const;
public:
	MutantStack& operator=(const MutantStack& rhs);
};

# include "MutantStack.tpp"

#endif