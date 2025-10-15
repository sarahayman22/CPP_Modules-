/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:22:01 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/13 18:40:33 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp (C++98)
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL))); // for robotomy randomness

    std::cout << "=== ex03: Intern tests ===\n\n";

    Intern someRandomIntern;

    // Create a few forms via the intern
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    AForm* unknown = someRandomIntern.makeForm("coffee maker", "Kitchen"); // expected to fail (nullptr)

    std::cout << "\n-- Check returned pointers --\n";
    if (!rrf) std::cout << "robotomy request: creation failed\n";
    if (!scf) std::cout << "shrubbery creation: creation failed\n";
    if (!ppf) std::cout << "presidential pardon: creation failed\n";
    if (!unknown) std::cout << "unknown form returned nullptr as expected\n";

    std::cout << "\n-- Prepare bureaucrats for signing/executing --\n";
    // using high-grade bureaucrats to avoid grade issues in this test
    Bureaucrat signer("TopSigner", 1);   // can sign & execute any form
    Bureaucrat execLow("ExecLow", 50);   // show some privilege differences (for robotomy exec 45)
    Bureaucrat execRobot("ExecRobot", 45);// exact exec grade for RobotomyRequestForm

    // sign and execute each form if it exists
    if (rrf) {
        std::cout << "\n[RobotomyRequestForm test]\n";
        signer.signForm(*rrf);
        // try executing with an insufficient executor first (should print error)
        execLow.executeForm(*rrf);
        // now execute with sufficient executor
        execRobot.executeForm(*rrf);
    }

    if (scf) {
        std::cout << "\n[ShrubberyCreationForm test]\n";
        signer.signForm(*scf);
        // Shrubbery exec required grade is 137, so execLow (50) can execute
        execLow.executeForm(*scf);
    }

    if (ppf) {
        std::cout << "\n[PresidentialPardonForm test]\n";
        signer.signForm(*ppf);
        // Presidential exec required grade is 5; execLow cannot, signer (grade 1) can
        execLow.executeForm(*ppf); // expected to fail
        signer.executeForm(*ppf);  // expected success
    }

    std::cout << "\n-- Clean up allocated forms --\n";
    if (rrf) delete rrf;
    if (scf) delete scf;
    if (ppf) delete ppf;
    if (unknown) delete unknown; // should be NULL, but safe check above prevents this

    std::cout << "\n=== End of tests ===\n";
    return 0;
}
