#include "StringReplace.hpp"

StringReplace::StringReplace(char *filename):m_ifs(filename)
{
	if (!m_ifs)
	{
		std::cerr << filename << ": " << strerror(errno) << std::endl;
		exit (1);
	}
}

void	StringReplace::set_ofstream(std::string _newname)
{
	m_ofs.open(_newname.c_str(), std::ios::out | std::ios::trunc);
	if (!m_ofs)
	{
		std::cerr << _newname << ": " << strerror(errno) << std::endl;
		exit (1);
	}
	m_ofs.close();
	m_ofs.open(_newname.c_str(), std::ios::app);
	if (!m_ofs)
	{
		std::cerr << _newname << ": " << strerror(errno) << std::endl;
		exit (1);
	}
}

void	StringReplace::create_copy_file(void)
{
	std::string	buf;

	while (std::getline(m_ifs, buf))
	{
		m_ofs << buf;
		if (!m_ifs.eof())
			m_ofs << std::endl;
	}
}

void StringReplace::replace_to_newfile(const std::string& s1, const std::string& s2)
{
	std::string	buf;
	size_t		startPos;
	size_t		endPos;

	if (s1.empty() || s2.empty())
	{
		this->create_copy_file();
		return ;
	}
	while (std::getline(m_ifs, buf))
	{
		startPos = 0;
		endPos = buf.length() - s2.length() + 1;
		while (startPos < endPos)
		{
			startPos = buf.find(s1, startPos);
			if (startPos == std::string::npos)
				break ;
			else
			{
				buf.erase(startPos, s1.length());
				buf.insert(startPos, s2);
				startPos += s2.length();
			}
		}
		m_ofs << buf;
		if (!m_ifs.eof())
			m_ofs << std::endl;
	}
}
