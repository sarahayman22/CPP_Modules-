/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:49:55 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/29 18:53:41 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define  FORM_HPP
#include<iostream>
#include <string>

class Form
{
    const std::string name;
    bool sign;
    const int gradeSign; 
    const int gradeExe;

    public:
    Form();
    Form(const std::string& name, const int gradeSign, const int gradeExe);
    Form& operator=(const Form &assign);
    ~Form();
    
};
        

#endif 