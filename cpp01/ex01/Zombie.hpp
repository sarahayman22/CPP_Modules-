/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:03:03 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/07 17:26:03 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
    std::string name;
    
    public:
    Zombie();
    ~Zombie();
    void setName(const std::string& newName);
    void announce ( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif