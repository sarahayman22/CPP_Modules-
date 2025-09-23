/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:26:08 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/23 16:19:04 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat() : Animal(), brain(new Brain())
{
    this->type = "Cat";
    std::cout << "[Cat] Default Constructor Called" << std::endl;
}

Cat::Cat(const std::string &type) : Animal(), brain(new Brain())
{
    this->type = type;
    std::cout << "[Cat] Parameterized Constructor Called" << std::endl;
}

// Deep copy: allocate a new Brain copying other's Brain
Cat::Cat(const Cat &copy) : Animal(), brain(NULL)
{
    std::cout << "[Cat] Copy Constructor Called" << std::endl;
    this->type = copy.type;
    if (copy.brain)
        brain = new Brain(*copy.brain);
    else
        brain = new Brain();
}

// Assignment operator with self-assignment guard and deep copy
Cat &Cat::operator=(const Cat &obj)
{
    std::cout << "[Cat] Assignment Operator Called" << std::endl;
    if (this == &obj)
        return *this;

    // copy base fields we rely on (type is usually in Animal)
    this->type = obj.type;

    // Replace brain safely: delete old, copy new
    delete brain;
    if (obj.brain)
        brain = new Brain(*obj.brain);
    else
        brain = new Brain();

    return *this;
}

void Cat::makeSound() const
{
    std::cout << "[Cat] Meow Meow ..." << std::endl;
}

Cat::~Cat()
{
    std::cout << "[Cat] Destructor Called" << std::endl;
    delete brain;
}

Brain *Cat::getBrain()
{
    return brain;
}

const Brain *Cat::getBrain() const
{
    return brain;
}
