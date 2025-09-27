/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:24:36 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/23 18:13:29 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap AAA("AAA");
    FragTrap BBB("BBB");

    AAA.setAttackDamage(5);
    AAA.attack("BBB");
    BBB.takeDamage(5);


    BBB.beRepaired(3);


    for (int i = 0; i < 5; ++i)
        AAA.attack("target");


    BBB.takeDamage(50);
    BBB.attack("someone");  // should fail
    BBB.beRepaired(10);     // should fail

    FragTrap copy = AAA;    
    FragTrap assign;
    assign = AAA;         

    copy.highFivesGuys();

    return 0;
}
