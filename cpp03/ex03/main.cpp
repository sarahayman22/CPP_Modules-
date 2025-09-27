/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:24:36 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/23 17:17:58 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== Creating default DiamondTrap ===\n";
    DiamondTrap d1;                       
    d1.whoAmI();

    std::cout << "\n=== Creating named DiamondTrap ===\n";
    DiamondTrap d2("Spark");             

    std::cout << "\n=== Testing attack ===\n";
    d2.attack("an enemy");                
    d2.takeDamage(20);                   
    d2.beRepaired(15);                    

    std::cout << "\n=== Testing copy constructor ===\n";
    DiamondTrap d3(d2);                 
    d3.whoAmI();

    std::cout << "\n=== Testing assignment operator ===\n";
    d1 = d3;                             
    d1.whoAmI();
    
    return 0;
}

