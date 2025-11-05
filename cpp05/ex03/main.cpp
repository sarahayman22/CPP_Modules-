/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:22:01 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/03 14:53:49 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>    
#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    AForm* a = NULL;
    AForm* b = NULL;
    AForm* c = NULL;
    AForm* formInvalid = NULL;

    a = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (a) {
        std::cout << "Created form: " << a->getName() << '\n';
        std::cout << *a << "\n\n";
    }

    b = someRandomIntern.makeForm("robotomy request", "Bender");
    if (b) {
        std::cout << "Created form: " << b->getName() << '\n';
        std::cout << *b << "\n\n";
    }

    c = someRandomIntern.makeForm("presidential pardon", "Marvin");
    if (c) {
        std::cout << "Created form: " << c->getName() << '\n';
        std::cout << *c << "\n\n";
    }

    formInvalid = someRandomIntern.makeForm("invalid form", "Nobody");
    if (!formInvalid)
        std::cout << "Form creation failed for unknown form type.\n\n";

    delete a;
    delete b;
    delete c;
    delete formInvalid;

    return 0;
}
