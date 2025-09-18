/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:24:36 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/18 15:58:22 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    // Create two FragTraps
    FragTrap AAA("AAA");
    FragTrap BBB("BBB");

    // AAA attacks BBB
    AAA.setAttackDamage(5);
    AAA.attack("BBB");
    BBB.takeDamage(5);

    // BBB repairs itself
    BBB.beRepaired(3);

    // AAA depletes energy with multiple attacks
    for (int i = 0; i < 5; ++i)
        AAA.attack("target");

    // Destroy BBB
    BBB.takeDamage(50);
    BBB.attack("someone");  // should fail
    BBB.beRepaired(10);     // should fail

    // Test copy and assignment
    FragTrap copy = AAA;    // copy constructor
    FragTrap assign;
    assign = AAA;           // assignment operator

    // High five demonstration
    copy.highFivesGuys();

    return 0;
}
