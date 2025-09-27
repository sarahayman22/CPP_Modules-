/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:03:24 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/27 13:44:22 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	//  const Animal* aa = new Animal();
	//  Animal	a;
	const Animal* i = new Dog();
	const Animal* j = new Cat();
	const WrongAnimal* wrong = new WrongCat();
	
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	wrong->makeSound();
	delete	i;
	delete	j;
	delete	wrong;
}