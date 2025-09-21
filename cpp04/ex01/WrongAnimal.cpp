/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:44:23 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/21 14:19:50 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "WrongAnimal";
    std::cout << "[WrongAnimal] default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "[WrongAnimal] copy constructor called" << std::endl;
    this->type = copy.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
    std :: cout << "[WrongAnimal] Assignment Operator Called" << std :: endl;
    this->type = obj.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimal] destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong animal sound " << std::endl;
}