/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:21 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/21 18:53:07 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "[Dog] Default constructor called\n";
}

Dog::Dog(const Dog &copy) : Animal(copy) 
{
     std::cout << "[Dog] Copy constructor called\n";
     this->brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog &assign)
{
    std::cout << "[Dog] Copy assignment operator called\n";
    if (this != &assign)
    {
        Animal::operator=(assign);
        delete this->brain;                     // prevent memory leak
        this->brain = new Brain(*assign.brain); // deep copy
    }
    return *this;
}


Dog::~Dog()
{
     std::cout << "[Dog] Destructor called\n"; }

void Dog::makeSound() const 
{
     std::cout << "[Dog] Woof!\n";
}

Brain	*Dog::getBrain()
{
	return brain;
}