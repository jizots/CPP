#include "Intern.hpp"
#include <string>
#include <strings.h>
#include "Libft.hpp"

typedef AForm* (Intern::*t_makeForm)(const std::string& target);

AForm* Intern::makeNewPres(const std::string& target)
{
	return (new PresidentialPardonForm(target));
};

AForm* Intern::makeNewRobo(const std::string& target)
{
	return (new RobotomyRequestForm(target));
};

AForm* Intern::makeNewShru(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
};

bool	Intern::isCorrectForm(const std::string& forms, const std::string& reqform)
{
	size_t	startPos = 0;
	size_t	endPos = reqform.length();
	std::string	erasedReqForm = reqform;

	while (startPos < endPos)
	{
		startPos = erasedReqForm.find(" ", startPos);
		if (startPos == std::string::npos)
			break ;
		else
			erasedReqForm.erase(startPos, 1);
	}
	if (strcasecmp(forms.c_str(), erasedReqForm.c_str()) == 0)
		return (true);
	return (false);
};

AForm*	Intern::makeForm(const std::string& reqform, const std::string& target)
{
	t_makeForm	funcs[] = {&Intern::makeNewPres, &Intern::makeNewRobo, &Intern::makeNewShru};
	std::string	forms[] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};

	for (int i = 0; i < NUM_FORM; ++i)
	{
		if (isCorrectForm(forms[i], reqform))
			return (this->*funcs[i])(target);
	}
	throw (Intern::FormNotFoundException());
	return (NULL);
};
