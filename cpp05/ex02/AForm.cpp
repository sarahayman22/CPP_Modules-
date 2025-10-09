/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:49:43 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/09 18:55:01 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"AForm.hpp"
#include "Bureaucrat.hpp" // full type needed here
#include <sstream>

AForm::AForm() : 
    name("default"),
    sign(false),
    gradeSign(150),
    gradeExe(150) {
        std::cout << "AForm: Default constructor called\n";
}

AForm::AForm(const std::string &name, int gradeSign, int gradeExe)
    :name(name),sign(false),gradeSign(gradeSign),gradeExe(gradeExe)
{
    if (gradeSign < 1 || gradeExe < 1)
        throw AForm::GradeTooHighException();
    if(gradeSign > 150 || gradeExe > 150)
        throw AForm::GradeTooLowException();
     std::cout << "AForm: constructor called\n";
}

AForm::AForm(const AForm &copy) :
        name(copy.name),
        sign(copy.sign), 
        gradeSign(copy.gradeSign), 
        gradeExe(copy.gradeExe)
{
         std::cout << "AForm: Copy constructor called\n";
}

AForm &AForm::operator=(const AForm &assign)
{
    if (this != &assign)
    {
        this->sign = assign.sign;
    }
    std::cout << "AForm: Copy assignment operator called\n";
    return *this;
}

AForm::~AForm() {}


const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade too low";
}
//Getters
const std::string &AForm::getName() const 
    { return name; }
bool AForm::isSigned() const 
    { return sign;}
int AForm::getGradeToSign() const 
    { return gradeSign; }
int AForm::getGradeToExecute() const 
    { return gradeExe; }

void AForm::beSigned(Bureaucrat const &b)
 {
     // Bureaucrat::getGrade() returns an int where 1 is highest
     if (b.getGrade() > gradeSign)// numeric greater -> worse grade -> too low
        throw AForm::GradeTooLowException();
    sign = true;
 }

std::ostream& operator<<(std::ostream &os, AForm const &f)
{
    os << "AForm \"" <<f.getName() << "\" , signed: "
     << (f.isSigned() ? "yes" : "no")
     << ", grade to sign: " << f.getGradeToSign()
     << ", grade to execute: " << f.getGradeToExecute();
    return os;
}

 class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Form is not signed!";
                }
};

void AForm::execute(const Bureaucrat &executor) const {
    if (!sign)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > gradeExe)
        throw AForm::GradeTooLowException();
    executeAction();
}