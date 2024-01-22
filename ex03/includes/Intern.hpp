#ifndef INTERN_HPP_INCLUDED
# define INTERN_HPP_INCLUDED

class AForm;

# include <string>
# include <stdexcept>

class Intern
{
	public:
		
		class FormNotFound : public std::exception
		{
			public:
				explicit FormNotFound(const std::string& message);
				virtual ~FormNotFound() throw();
				virtual const char* what() const throw();

			protected:
				std::string _message;
		};

		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm*	makeForm(const std::string& formName, const std::string& target) const;
	
	private:
		static const std::string	_formNames[3];

		typedef AForm* (Intern::*_FormCreator)(const std::string& target) const;
		static const _FormCreator _formCreators[3];


		AForm*	_makeShrubberyCreationForm(const std::string& target) const;
		AForm*	_makeRobotomyRequestForm(const std::string& target) const;
		AForm*	_makePresidentialPardonForm(const std::string& target) const;
};

#endif /* INTERN_HPP_INCLUDED */
