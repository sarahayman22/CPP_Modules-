/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:03:24 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/21 14:27:22 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
     Animal* j = new Dog();
     Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // Meow
    j->makeSound(); // Woof
    meta->makeSound(); // generic Animal sound

    delete meta;
    delete j;
    delete i;
    std::cout<< "------------WrongAnimal test-----------------------------"<< std::endl;
    // WrongAnimal test
    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    wa->makeSound(); // WrongAnimal sound
    wc->makeSound(); // Still WrongAnimal sound (no virtual)

    delete wa;
    delete wc;

    return 0;
}