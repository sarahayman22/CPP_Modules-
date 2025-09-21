/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:26:08 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/21 18:53:32 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "[Cat] Constructor Called" << std :: endl;
}

Cat::Cat(std::string type) : Animal()
{
    this->type = type;
    this->brain = new Brain(type.brain);
    std :: cout << "[Cat] parameterized Constructor Called" << std :: endl;
}

Cat::Cat(const Cat &copy) : Animal()
{
    std :: cout << "[Cat] Copy Constructor Called" << std :: endl;
    this->type = copy.type;
}

Cat &Cat::operator=(const Cat &obj)
{
    std :: cout << "[Cat] Assignment Operator Called" << std :: endl;
    this->type = obj.type;
    return (*this);
}

void Cat::makeSound() const
{
    std :: cout << "Sound of Cat : " << "Meow Meow ..." << std :: endl;
}

Cat::~Cat()
{
    std :: cout << "[Cat] Destructor Called" << std :: endl;
}


Brain *Cat::getBrain()
{
    return this->brain;
}