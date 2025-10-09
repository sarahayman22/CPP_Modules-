/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:06:59 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/06 18:55:59 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"
#include "AForm.hpp"

 Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name(name),grade(grade)
 {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowExcption();
 }

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade)
{
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &assign)
{
    if (this != &assign)
        this->grade = assign.grade;
    return *this;   
}

Bureaucrat::~Bureaucrat()
{
}
//getters
const std::string &Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const 
{
     return grade;
}

void Bureaucrat::incrementGrade()
{
    if(grade <= 1)
        throw GradeTooHighException();
    --grade; 
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowExcption();
    ++grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowExcption::what() const throw()
{
    return "Bureaucrat grade is too low";
}

void Bureaucrat::signForm(AForm &form) const 
{
    try
    {
        form.beSigned(*this);
        std::cout<< name  << " signed " << form.getName() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << name << "couldn't sign " << form.getName()
            << "because " << e.what() << std::endl;      
    }
}

void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ",Bureaucrat grade " << b.getGrade() << ".";
    return os;
}