/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 14:53:42 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/07 16:25:43 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie{
  private:
    std::string name;

    public:
        Zombie(); 
        Zombie(const std::string& name);  
        ~Zombie();
        void announce( void ); 
};

void    randomChump(std::string name);
Zombie* newZombie(std::string name);


#endif