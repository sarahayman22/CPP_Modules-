/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:26:22 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/21 13:06:18 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include<iostream>

class Animal
{
    protected:
        std::string type;
        
    public:
        Animal();
        Animal(const Animal& copy);
        Animal &operator=(const Animal &assign);
        virtual ~Animal();
        
       virtual void makeSound() const;
       std::string getType() const;
       
};

#endif


