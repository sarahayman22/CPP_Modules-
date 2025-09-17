/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:12:21 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/17 18:57:05 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ScavTrap_HPP
#define ScavTrap_HPP
#include <iostream>

class ScavTrap : public ClapTrap
{
    public:
         ScavTrap();
         ScavTrap(const std::string& name);
         ScavTrap(const ScavTrap& copy);
         ScavTrap &operator=(const ScavTrap &assign);
         ~ScavTrap();

           // override attack to print ScavTrap-specific message
         void attack(const std::string& target);

          // ScavTrap special ability
         void guardGate() const;
};

#endif
