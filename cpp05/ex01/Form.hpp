/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:49:55 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/21 13:27:10 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define  FORM_HPP
#include<iostream>
#include <string>

class Bureaucrat;

class Form
{
    const std::string name;
    bool sign;
    const int gradeSign; 
    const int gradeExe;

    public:
        Form(const std::string& name, const int gradeSign, const int gradeExe);
        Form(const Form &copy);
        Form& operator=(const Form &assign);
        ~Form();

        class GradeTooHighException : public std::exception {
             const char* what() const throw();
         };
        class GradeTooLowException : public std::exception {
            const char* what() const throw();
        };
        
        const std::string &getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        // Actions
        void beSigned(Bureaucrat const &b);
};
std::ostream &operator<<(std::ostream &os, Form const &f);


#endif 