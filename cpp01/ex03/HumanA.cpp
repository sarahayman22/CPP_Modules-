/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:03:27 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/13 16:29:56 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weaponRef) : name(name), weapon(weaponRef){}

void HumanA::attack() const{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}