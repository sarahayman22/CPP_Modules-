/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:26:08 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/23 12:56:40 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include"Animal.hpp"

Animal::Animal(): type("Animal")
{
    std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(const Animal& copy) :type(copy.type)
{
    std::cout << "[Animal] Copy constructor called for: " << type << std::endl;
}

Animal& Animal::operator=(const Animal& assign)
{
    std::cout << "[Animal] Assignation operator called for: " << type << std::endl;
    if (this != &assign)
        type = assign.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "[Animal] Destructor called for: " << type << std::endl;
    
}


void Animal::makeSound() const
{
    std::cout << "[Animal] sound*\n";
}

std::string Animal::getType() const
{ 
    return type; 
}

