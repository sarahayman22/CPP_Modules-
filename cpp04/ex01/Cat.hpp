/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:26:17 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/23 12:24:01 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
    Brain *brain;
    
    public:
        Cat();
        Cat(const std::string &type);
        Cat(const Cat &copy);
        Cat &operator=(const Cat &other);
        ~Cat();
        
        void makeSound() const;
        Brain *getBrain();
        const Brain *getBrain() const;
        
};

#endif