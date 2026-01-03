/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:06:18 by saabo-sh          #+#    #+#             */
/*   Updated: 2026/01/03 10:48:08 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("AAA");
    ScavTrap b("BBB");

    ClapTrap *ptr = new ScavTrap("loay");

    a.setAttackDamage(4);
    b.setAttackDamage(2);

    a.attack("a training dummy");
    b.takeDamage(3);

    b.beRepaired(5);

    for (int i = 0; i < 11; ++i)
        a.attack("target");

    a.takeDamage(100);
    a.attack("something");
    a.beRepaired(5);

    ScavTrap c = b;   // copy constructor
    ScavTrap d;
    d = b;            // assignment operator

    delete ptr;
    return 0;
}

