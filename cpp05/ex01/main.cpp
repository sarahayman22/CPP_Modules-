/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:22:01 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/01 18:55:51 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// main.cpp
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat alice("Alice", 3);
        Form formA("FormA", 5, 10);

        std::cout << formA << std::endl;          // not signed
        alice.signForm(formA);                    // should succeed because 3 <= 5
        std::cout << formA << std::endl;          // signed

        Bureaucrat bob("Bob", 10);
        Form formB("TopSecret", 5, 1);
        bob.signForm(formB);                      // should fail: 10 > 5

        // boundary: exact grade allowed
        Bureaucrat carol("Carol", 5);
        Form formC("Boundary", 5, 5);
        carol.signForm(formC);                    // should succeed (equal)

    } catch (std::exception &e) {
        std::cerr << "Caught exception in main: " << e.what() << std::endl;
    }

    // test constructor exceptions
    try {
        Form bad("BadForm", 0, 10); // grade 0 -> GradeTooHighException
    } catch (std::exception &e) {
        std::cerr << "Expected constructor error: " << e.what() << std::endl;
    }

    try {
        Form bad2("BadForm2", 151, 10); // grade 151 -> GradeTooLowException
    } catch (std::exception &e) {
        std::cerr << "Expected constructor error: " << e.what() << std::endl;
    }

    return 0;
}
