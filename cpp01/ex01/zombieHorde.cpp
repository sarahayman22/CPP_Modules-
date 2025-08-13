/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:03:31 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/07 17:22:54 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"
#include<sstream>

Zombie* zombieHorde( int N, std::string name )
{
    if(N <= 0)
        return NULL;
    Zombie* horde = new Zombie[N];

    for(int i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }
    return horde;
    
}

