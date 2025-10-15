/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:22:01 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/13 14:46:38 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL))); // for robotomy randomness

    std::cout << "=== ex02: AForm concrete classes test ===\n\n";

    // create bureaucrats with different grades
    Bureaucrat low("Low", 150);
    Bureaucrat shrubSigner("ShrubSigner", 145); // can sign Shrubbery (sign 145)
    Bureaucrat shrubExec("ShrubExec", 137);     // can execute Shrubbery (exec 137)
    Bureaucrat robotSigner("RobotSigner", 72);  // can sign Robotomy (sign 72)
    Bureaucrat robotExec("RobotExec", 45);      // can execute Robotomy (exec 45)
    Bureaucrat presSigner("PresSigner", 25);    // can sign Presidential (sign 25)
    Bureaucrat presExec("PresExec", 5);         // can execute Presidential (exec 5)
    Bureaucrat boss("Boss", 1);                 // top-level bureaucrat

    // create forms (each takes target as constructor parameter)
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pres("Ford Prefect");

    std::cout << "\n-- Attempt to execute unsigned form (expected: error) --\n";
    // Should throw because form is not signed
    try {
        boss.executeForm(shrub); // expected to print an explicit error message via executeForm
    } catch (std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << '\n';
    }

    std::cout << "\n-- ShrubberyCreationForm signing & executing --\n";
    // low tries to sign -> should fail
    low.signForm(shrub);

    // correct signer signs
    shrubSigner.signForm(shrub);

    // someone with insufficient exec grade tries to execute directly -> should throw
    try {
        std::cout << "Attempting direct execute by Low (grade 150)\n";
        shrub.execute(low); // should throw AForm::GradeTooLowException or similar
    } catch (std::exception &e) {
        std::cerr << "Direct execute failed: " << e.what() << '\n';
    }

    // correct executor executes (use Bureaucrat::executeForm)
    shrubExec.executeForm(shrub); // expected success -> file "home_shrubbery"

    std::cout << "\n-- RobotomyRequestForm signing & executing (multiple tries show ~50% success) --\n";
    // sign with correct grade
    robotSigner.signForm(robot);

    // execute multiple times to show random success/failure
    for (int i = 0; i < 4; ++i) {
        std::cout << "[trial " << i+1 << "] ";
        robotExec.executeForm(robot);
    }

    std::cout << "\n-- PresidentialPardonForm signing & executing --\n";
    // try to execute without signing
    presExec.executeForm(pres); // expected error: not signed

    // sign with correct grade
    presSigner.signForm(pres);

    // try to execute with insufficient executor (presExec has grade 5, which is required to execute)
    presExec.executeForm(pres); // expected success

    // boss executes everything (already signed forms), should always succeed
    std::cout << "\n-- Boss executing everything for good measure --\n";
    boss.executeForm(shrub);
    boss.executeForm(robot);
    boss.executeForm(pres);

    std::cout << "\n=== End of tests ===\n";
    return 0;
}
