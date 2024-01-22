#ifndef PRESIDENTIAL_PARDON_FORMHPP_INCLUDED
# define PRESIDENTIAL_PARDON_FORMHPP_INCLUDED

# include <string>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

	private:
		const std::string	_target;

		void				_executeAction() const;
};

#endif /* PRESIDENTIAL_PARDON_FORMHPP_INCLUDED */
