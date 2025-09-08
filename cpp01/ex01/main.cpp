/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:02:18 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/30 18:20:05 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    int N = 5;
    Zombie* horde = zombieHorde(N,"Zombi");
    
    if (!horde)
        return 1;

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
    
}