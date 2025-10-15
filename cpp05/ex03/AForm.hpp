/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:49:55 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/13 18:42:19 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define  AFORM_HPP
#include<iostream>
#include <string>

class Bureaucrat; // forward declaration to avoid circular include

class AForm
{
    const std::string name;
    bool sign;
    const int gradeSign; 
    const int gradeExe;

    protected:
        virtual void executeAction() const = 0;

    public:
        AForm();
        AForm(const std::string& name, const int gradeSign, const int gradeExe);
        AForm(const AForm &copy);
        AForm& operator=(const AForm &assign);
        virtual ~AForm();

        // Exceptions
        class GradeTooHighException : public std::exception {
             const char* what() const throw();
         };
        class GradeTooLowException : public std::exception {
            const char* what() const throw();
        };
        
        class FormNotSignedException : public std::exception {
             const char* what() const throw();
        };

        
        // Getters
        const std::string& getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        // Actions
        void beSigned(Bureaucrat const &b); // throws GradeTooLowException if b's grade too low
        void execute(Bureaucrat const & executor) const;
};
std::ostream &operator<<(std::ostream &os, AForm const &f);


#endif 