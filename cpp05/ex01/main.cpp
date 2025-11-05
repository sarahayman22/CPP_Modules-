/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:22:01 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/03 17:32:09 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat A("A", 3);
        Form formA("FormA", 5, 10);

        std::cout << formA << std::endl; 
        A.signForm(formA);                   
        std::cout << formA << std::endl;         

        Bureaucrat B("B ", 10);
        Form formB("FormB", 5, 1);
        B.signForm(formB);  

        
        Bureaucrat C("C", 5);
        Form formC("FormC", 5, 5);
        C.signForm(formC);       

    } catch (std::exception &e) {
        std::cerr << "Caught exception in main: " << e.what() << std::endl;
    }
    
///////////////////////////////////////////////////////////////////////////////////////////////

    try {
        Form bad("BadForm", 0, 10);
    } catch (std::exception &e) {
        std::cerr << "Expected constructor error: " << e.what() << std::endl;
    }

    try {
        Form bad2("BadForm2", 151, 10);
    } catch (std::exception &e) {
        std::cerr << "Expected constructor error: " << e.what() << std::endl;
    }

    return 0;
}
