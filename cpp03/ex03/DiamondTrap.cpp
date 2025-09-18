/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:09:54 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/18 18:33:38 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"DiamondTrap.hpp"

static const int DIAMOND_HP = 100;  
static const int DIAMOND_EP = 50;  
static const int DIAMOND_AD = 30;

//ClapTrap("default_clap_name")

//Because FragTrap and ScavTrap inherit from ClapTrap virtually, DiamondTrap must decide how to initialize the single shared ClapTrap subobject.

//This calls ClapTrap’s constructor with "default_clap_name" → so inside the hidden ClapTrap object, the name field becomes "default_clap_name".


DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), name("default")
{

    this->hitPoints = DIAMOND_HP;
    this->energyPoints = DIAMOND_EP;
    this->attackDamage = DIAMOND_AD;
    std::cout << "DiamondTrap default constructed\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
:ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
    this->hitPoints = DIAMOND_HP;
    this->energyPoints = DIAMOND_EP;
    this->attackDamage = DIAMOND_AD;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
: ClapTrap(copy.ClapTrap::name), FragTrap(copy), ScavTrap(copy), name(copy.name)
{
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;
    std::cout << "DiamondTrap copy-constructed\n";
}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
    if (this == &copy) return *this;
    // copy ClapTrap named member
    this->ClapTrap::name = copy.ClapTrap::name;
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " destroyed\n";
}

