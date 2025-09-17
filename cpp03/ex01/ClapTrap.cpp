/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:06:52 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/17 16:51:10 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("")
    , hitPoints(10)
    , energyPoints(10)
    , attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
    std::cout<<"Constructor called of ClapTrap"<<std::endl;
    this->name = name;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& copy)
    : name(copy.name),
      hitPoints(copy.hitPoints),
      energyPoints(copy.energyPoints),
      attackDamage(copy.attackDamage)
{
    std::cout << "ClapTrap Copy constructor called for: " << name << std::endl;
}

// Assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& assign)
{
    if (this != &assign)
    {
        name = assign.name;
        hitPoints = assign.hitPoints;
        energyPoints = assign.energyPoints;
        attackDamage = assign.attackDamage;
    }
    std::cout << "ClapTrap Assignation operator called for: " << name << std::endl;
    return *this;
}

// Destructor
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called for: " << name << std::endl;
}

//----------------Actions-------------------------------------------------------------
void ClapTrap::attack(const std::string& target)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot attack because it has no hit points (dead)." << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot attack because it has no energy left." << std::endl;
        return;
    }

    --energyPoints;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is already at 0 hit points." << std::endl;
        return;
    }

    if (amount >= hitPoints)
    {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and is now destroyed (0 HP)." << std::endl;
    }
    else
    {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage, remaining HP: " << hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot be repaired because it has no hit points (considered destroyed)." << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot repair because it has no energy left." << std::endl;
        return;
    }

    --energyPoints;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired by " << amount
              << " points, current HP: " << hitPoints << std::endl;
}

//----------------------getter-------------------------------------------------
std::string ClapTrap::getName() const
 {return name; }
int ClapTrap::getHitPoints() const
 {return hitPoints;}
int ClapTrap::getEnergyPoints() const 
 {return energyPoints; }
int ClapTrap::getAttackDamage() const
 {return attackDamage; }

//---------------------------------------- Setters----------------------------------
void ClapTrap::setName(const std::string& n) 
{ name = n; }
void ClapTrap::setHitPoints(unsigned int hp) 
{ hitPoints = hp; }
void ClapTrap::setEnergyPoints(unsigned int ep) 
{ energyPoints = ep; }
void ClapTrap::setAttackDamage(unsigned int ad) 
{ attackDamage = ad; }


