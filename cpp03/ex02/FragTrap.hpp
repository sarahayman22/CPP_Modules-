/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:37 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/18 15:47:17 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include"ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
         FragTrap();
         FragTrap(const std::string& name);
         FragTrap(const FragTrap& copy);
         FragTrap &operator=(const FragTrap &assign);
         ~FragTrap();

           // override attack to print FragTrap-specific message
         void attack(const std::string& target);
         void highFivesGuys(void);
         

        
};

#endif

