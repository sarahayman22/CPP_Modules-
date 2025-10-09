/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:21:49 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/06 18:46:43 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include<iostream>
#include <string>
//#include "AForm.hpp"

class AForm;
class Bureaucrat
{
    const std::string name;
    int grade;
    
 public:
     Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &assign);
    ~Bureaucrat();
    
    const std::string &getName() const;
    int getGrade() const;
   
    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception 
    {
            const char *what() const throw();      
    };
    
    class GradeTooLowExcption : public std::exception
    {
            const char *what () const throw();
    };

     void signForm(AForm &form) const;
     void executeForm(AForm const &form) const;

};
    std::ostream& operator<<(std::ostream& os, const Bureaucrat& fp);
   

#endif