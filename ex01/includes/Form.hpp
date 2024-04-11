#ifndef FORM_HPP_INCLUDED
# define FORM_HPP_INCLUDED

class Bureaucrat;

# include <string>
# include <iosfwd>
# include <stdexcept>

class Form
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

		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string&	getName() const;
		bool								isSigned() const;
		int 								getGradeToSign() const;
		int 								getGradeToExecute() const;

		void								beSigned(const Bureaucrat& bureaucrat);

	private:
		const std::string	_name;
		bool							_signed;
		const int					_gradeToSign;
		const int					_gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif /* FORM_HPP_INCLUDED */