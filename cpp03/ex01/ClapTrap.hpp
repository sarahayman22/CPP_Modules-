/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:06:35 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/17 12:01:51 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;

    public:
         ClapTrap();
         ClapTrap(const std::string& name);
         ClapTrap(const ClapTrap& copy);
         ClapTrap &operator=(const ClapTrap &assign);
         ~ClapTrap();
        
         void attack(const std::string& target);
         void takeDamage(unsigned int amount);
         void beRepaired(unsigned int amount);

         int getHitPoints() const;
         int getEnergyPoints() const;
         int getAttackDamage() const;
         std::string getName() const;

         void setName(const std::string& n);
         void setHitPoints(unsigned int hp);
         void setEnergyPoints(unsigned int ep);
         void setAttackDamage(unsigned int ad);
        
};

#endif
