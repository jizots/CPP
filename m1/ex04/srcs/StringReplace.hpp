#ifndef StringReplace_HPP
# define StringReplace_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cerrno>

class StringReplace
{
public:
	void	set_ofstream(std::string _newname);
	void	create_copy_file(void);
	void	replace_to_newfile(const std::string& s1, const std::string& s2);

	StringReplace(char *filename);

private:
	std::ifstream	m_ifs;
	std::ofstream	m_ofs;
};


#endif
