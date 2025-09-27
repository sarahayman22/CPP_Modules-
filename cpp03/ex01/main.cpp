/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:06:18 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/25 18:08:36 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("AAA");
    ScavTrap b("BBB");
    ClapTrap *c = new ScavTrap("loay");
    a.setAttackDamage(4);
    b.setAttackDamage(2);

   
    a.attack("a training dummy");
    b.takeDamage(3);


    b.beRepaired(5);
    
    for (int i = 0; i < 11; ++i) 
    {
        a.attack("target");
    }

    a.takeDamage(100);


    a.attack("something");
    a.beRepaired(5);

 
    ScavTrap c = b; 
    ScavTrap d;
    d = b; 

    return 0;
}
