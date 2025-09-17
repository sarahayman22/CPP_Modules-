/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:06:18 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/17 15:28:30 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("AAA");
    ClapTrap b("BBB");

    a.setAttackDamage(4);
    b.setAttackDamage(2);

    // Normal attack
    a.attack("a training dummy");
    // Bravo takes damage (we're just simulating, not interacting ClapTrap instances directly as per spec)
    b.takeDamage(3);

    // Repair
    b.beRepaired(5);

    // Deplete Alpha's energy by attacking until energy gone
    for (int i = 0; i < 11; ++i) // 10 energy points initially
    {
        a.attack("target");
    }

    // Damage Alpha until destroyed
    a.takeDamage(100);

    // Attempt to attack & repair when dead
    a.attack("something");
    a.beRepaired(5);

    // Test copy and assign
    ClapTrap c = b; // copy constructor
    ClapTrap d;
    d = b; // assignment

    return 0;
}
