/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:43:26 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/21 14:20:29 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "[WrongCat] default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << "[WrongCat] copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    std :: cout << "[WrongCat] Assignment Operator Called" << std :: endl;
    this->type = obj.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow meow!" << std::endl;
}