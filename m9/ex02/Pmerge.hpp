#ifndef PMERGE_HPP
# define PMERGE_HPP

# include <vector>
# include <list>

class Pmerge
{
public:
	Pmerge(void);
	Pmerge(const Pmerge& other);
	~Pmerge(void);

private:
	std::vector<uint64_t> containerFirst;
	std::vector<uint64_t> containerSecond;

public:
	Pmerge& operator=(const Pmerge& rhs);

};

#endif