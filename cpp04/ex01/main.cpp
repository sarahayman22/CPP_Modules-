/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:03:24 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/27 13:55:06 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

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
	std::cout << "****************************"<<std::endl;
	Cat	a;

	a.getBrain()->setIdea(0,"any thing");
	std::cout << std::endl;
	std::cout << a.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << "****************************"<<std::endl;

	for (int i = 0; i < N; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	std::cout << "****************************"<<std::endl;
	
	Dog	b;
	Dog c = b;
	(void)c;


	return 0;
}