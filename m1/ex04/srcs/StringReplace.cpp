#include "StringReplace.hpp"

StringReplace::StringReplace(char *filename):m_ifs(filename)
{
	std::string	outfile;
	if (!m_ifs)
	{
		std::cerr << filename << ": " << strerror(errno) << std::endl;
		exit (1);
	}
}

void	StringReplace::set_ofstream(std::string _newname)
{
	m_ofs.open(_newname.c_str(), std::ios::app);
	if (!m_ofs)
	{
		std::cerr << _newname << ": " << strerror(errno) << std::endl;
		exit (1);
	}

}

const std::string& StringReplace::replace_to_newfile(const std::string& s1, const std::string& s2)
{
	std::string	buf;

	if (s1.empty() || s2.empty())
	{
		std::cout << "empty" << std::endl;
		while (!m_ifs.eof())
		{
			std::getline(m_ifs, buf);
			m_ofs << buf << std::endl;
		}
		return (s2);
	}
	return (s1);
}
