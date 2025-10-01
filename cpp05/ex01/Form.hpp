/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:49:55 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/01 18:56:13 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define  FORM_HPP
#include<iostream>
#include <string>

class Bureaucrat; // forward declaration to avoid circular include

class Form
{
    const std::string name;
    bool sign;
    const int gradeSign; 
    const int gradeExe;

    public:
    //    Form();
        Form(const std::string& name, const int gradeSign, const int gradeExe);
        Form(const Form &copy);
        Form& operator=(const Form &assign);
        ~Form();

        // Exceptions
        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
         };
        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
        
        // Getters
        const std::string &getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        // Actions
        void beSigned(Bureaucrat const &b); // throws GradeTooLowException if b's grade too low
};
std::ostream &operator<<(std::ostream &os, Form const &f);


#endif 