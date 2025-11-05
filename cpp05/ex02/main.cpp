/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:22:01 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/21 18:14:21 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
    std::srand(std::time(0));
 
    Bureaucrat A("A", 1);

    ShrubberyCreationForm tree("garden");
    RobotomyRequestForm robo("Alice");
    PresidentialPardonForm pardon("Marvin");
    std::cout<<"////////////////////////////////////////////////////////////"<<std::endl;
    try {
        A.signForm(tree);
        A.signForm(robo);
        A.signForm(pardon);

        A.executeForm(tree);
        std::cout<<"////////////////////////////////////////////////////////////"<<std::endl;
        A.executeForm(robo);
        std::cout<<"////////////////////////////////////////////////////////////"<<std::endl;
        A.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}