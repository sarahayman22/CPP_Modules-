/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 10:43:55 by saabo-sh          #+#    #+#             */
/*   Updated: 2026/01/03 10:45:08 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    // Constructors & Destructor
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& copy);
    ScavTrap& operator=(const ScavTrap& assign);
    ~ScavTrap();

    // Member functions
    void attack(const std::string& target);
    void guardGate();
};

#endif
