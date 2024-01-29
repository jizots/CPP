#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# define NUM_FORM 3

class Intern
{
public:
	inline Intern(void){};
	inline Intern(const Intern& other){(void)other;};
	inline ~Intern(void){};
	AForm*	makeForm(const std::string& form, const std::string& target);

class FormNotFoundException : public std::exception
{
public:
	inline virtual const char* what() const _NOEXCEPT{return ("Form not found");}
};


private:
	AForm* 	makeNewPres(const std::string& target);
	AForm* 	makeNewRobo(const std::string& target);
	AForm* 	makeNewShru(const std::string& target);
	static bool		isCorrectForm(const std::string& forms, const std::string& target);

public:
	inline Intern&	operator=(const Intern& rhs){(void)rhs; return (*this);};
};

#endif
