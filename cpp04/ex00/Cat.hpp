/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:26:17 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/20 18:40:34 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include"Animal.hpp"
// virtual function is a member function in the base class that can be overridden in derived classes.

class Cat : public Animal
{
    Cat();
    Cat(const Cat& copy);
    Cat &operator=(const Cat &assign);
    ~Cat();
    
    void makeSound();
    
    
};
#endif