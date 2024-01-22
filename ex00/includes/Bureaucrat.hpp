#ifndef BUREAUCRAT_HPP_INCLUDED
# define BUREAUCRAT_HPP_INCLUDED

# include <stdexcept>
# include <string>
# include <iosfwd>

class Bureaucrat
{
	public:

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;
	private:
		const std::string	_name;
		int					_grade;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif /* BUREAUCRAT_HPP_INCLUDED */
