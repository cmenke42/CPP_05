#ifndef FORM_HPP_INCLUDED
# define FORM_HPP_INCLUDED

class Bureaucrat;

# include <string>
# include <iosfwd>
# include <stdexcept>

class AForm
{
	public:

		class FormException : public std::exception
		{
			public:
				FormException();
				explicit FormException(const std::string& message);
				virtual ~FormException() throw();
				virtual const char* what() const throw();

			protected:
				std::string _message;
		};

		class GradeTooHighException : public FormException
		{
			public:
				GradeTooHighException();
				explicit GradeTooHighException(const std::string& message);
		};

		class GradeTooLowException : public FormException
		{
			public:
				GradeTooLowException();
				explicit GradeTooLowException(const std::string& message);
		};

		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string&	getName() const;
		bool				isSigned() const;
		int 				getGradeToSign() const;
		int 				getGradeToExecute() const;

		void				beSigned(const Bureaucrat& bureaucrat);
		void				execute(const Bureaucrat& executor) const;

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

		virtual void		_executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif /* FORM_HPP_INCLUDED */