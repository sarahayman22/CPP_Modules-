/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:31 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/20 18:42:43 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include"Animal.hpp"

class Dog : public Animal
{
    Dog();
    Dog(const Dog& copy);
    Dog &operator=(const Dog &assign);
    ~Dog();
    
    void makeSound();
    

};

#endif 

