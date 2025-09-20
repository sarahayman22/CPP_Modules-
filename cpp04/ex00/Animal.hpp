/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:26:22 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/20 18:41:57 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal
{
    protected:
        std::string type;
        
    public:
        Animal();
        Animal(const Animal& copy);
        Animal &operator=(const Animal &assign);
        ~Animal();
        
       virtual void makeSound();
        

};

#endif