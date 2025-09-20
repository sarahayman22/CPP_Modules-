/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:09:49 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/20 14:26:24 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP


#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap 
{
    std::string name;
    
    public:
        DiamondTrap();
        DiamondTrap(const std::string& name);
        DiamondTrap(const DiamondTrap& copy);
        DiamondTrap& operator=(const DiamondTrap& copy);
        ~DiamondTrap();

        void attack(const std::string& target);
        void whoAmI() const;    

};

#endif