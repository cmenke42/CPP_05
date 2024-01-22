#ifndef SHRUBBERY_CREATION_FORM_HPP_INCLUDED
# define SHRUBBERY_CREATION_FORM_HPP_INCLUDED

# include <string>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

	private:
		const std::string	_target;

		void				_executeAction() const;
};

#endif /* SHRUBBERY_CREATION_FORM_HPP_INCLUDED */
