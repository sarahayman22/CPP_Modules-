/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:03:24 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/27 13:26:50 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* A = new Animal();
     Animal* j = new Dog();
     Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound(); 
    A->makeSound();
    
    delete A;
    delete j;
    delete i;
    
    std::cout<< "------------WrongAnimal test-----------------------------"<< std::endl;
    
    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    wa->makeSound(); 
    wc->makeSound(); 

    delete wa;
    delete wc;

    return 0;
}