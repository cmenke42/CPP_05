#ifndef ROBOTOMY_REQUEST_FORM_HPP_INCLUDED
# define ROBOTOMY_REQUEST_FORM_HPP_INCLUDED

# include <string>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

	private:
		const std::string	_target;

		void				_executeAction() const;
};

#endif /* ROBOTOMY_REQUEST_FORM_HPP_INCLUDED */
