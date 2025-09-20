/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:26:08 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/20 16:58:36 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include"Animal.hpp"

Animal::Animal(): type("")
{
    std::cout << "Default constructor called" << std::endl;
}

Animal::Animal(const Animal& copy) :type(copy.type)
{
    std::cout << "Animal Copy constructor called for: " << type << std::endl;
}

Animal& Animal::operator=(const Animal& assign)
{
    if (this != &assign)
    {
        type = assign.type;
    }
    std::cout << "Animal Assignation operator called for: " << type << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called for: " << type << std::endl;
    
}