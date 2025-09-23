/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:03:24 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/23 16:15:49 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

// How this applies to your Dog and Cat with Brain

// Dog and Cat have a Brain* (allocated with new Brain()).

// If you don’t implement deep copy, copying a Dog means both dogs share the same brain → shallow copy.

// If one deletes the brain, the other is left with a dangling pointer → ❌ memory errors.

// So you write a copy constructor and assignment operator that:

// Allocates a new Brain.

// Copies the contents of the old Brain into it.

// That way, each animal has its own independent brain.

int main()
{
	int N = 4;
	const Animal* animals[N];
	
	for(int i = 0; i < N; i++)
	{
		if (i < (N / 2))
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
		std::cout << std::endl;
	}
	
	/****************************************/
	Cat	a;

	a.getBrain()->setIdea(0,"any thing");
	std::cout << std::endl;
	std::cout << a.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
	/*************************************** */

	
	for (int i = 0; i < N; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	
	/***************************************/

	Dog	b;
	Dog c = b;
	(void)c;

	/***************************************/
	return 0;
}