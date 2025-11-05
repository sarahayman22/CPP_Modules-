/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:49:43 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/21 13:24:53 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Form.hpp"
#include "Bureaucrat.hpp"
#include <sstream>

Form::Form(const std::string &name, int gradeSign, int gradeExe)
    :name(name),sign(false),gradeSign(gradeSign),gradeExe(gradeExe)
{
    if (gradeSign < 1 || gradeExe < 1)
        throw GradeTooHighException();
    if(gradeSign > 150 || gradeExe > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &copy) 
    : name(copy.name), sign(copy.sign), gradeSign(copy.gradeSign), gradeExe(copy.gradeExe)
{
        
}

Form &Form::operator=(const Form &assign)
{
    if (this != &assign)
    {
        sign = assign.sign;
    }
    return *this;
}

Form::~Form() {}


const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low";
}
//Getters
const std::string &Form::getName() const 
    { return name; }
bool Form::isSigned() const 
    { return sign;}
int Form::getGradeToSign() const 
    { return gradeSign; }
int Form::getGradeToExecute() const 
    { return gradeExe; }

void Form::beSigned(Bureaucrat const &b)
 {
     if (b.getGrade() > gradeSign)
        throw GradeTooLowException();
    sign = true;
 }

std::ostream &operator<<(std::ostream &os, Form const &f)
{
    os << "Form \"" <<f.getName() << "\" , signed: "
     << (f.isSigned() ? "yes" : "no")
     << ", grade to sign: " << f.getGradeToSign()
     << ", grade to execute: " << f.getGradeToExecute();
    return os;
}

