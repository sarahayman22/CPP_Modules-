/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 14:52:23 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/07 16:48:21 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(const std::string& zombieName) : name(zombieName) {}

void Zombie::announce( void )
{
    std::cout << name <<  "BraiiiiiiinnnzzzZ...";
    std::cout<<"\n";
    
}

Zombie::~Zombie()
{
    std::cout<<name <<" is destroyed."<< std::endl;
    
}
