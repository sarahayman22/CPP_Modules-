/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:12:21 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/18 18:07:20 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ScavTrap_HPP
#define ScavTrap_HPP
#include <iostream>
#include "ClapTrap.hpp" 

class ScavTrap : public ClapTrap
{
    public:
         ScavTrap();
         ScavTrap(const std::string& name);
         ScavTrap(const ScavTrap& copy);
         ScavTrap &operator=(const ScavTrap &assign);
         ~ScavTrap();

         void attack(const std::string& target);
         void guardGate();
};

#endif
