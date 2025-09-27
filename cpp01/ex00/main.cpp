/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 14:51:42 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/04 09:30:29 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

int main() {
    std::cout << "=== Heap Zombie ===" << std::endl;
    Zombie* heapZombie = newZombie("");
    std::cout<<"\n";
    heapZombie->announce();
     std::cout<<"\n";
    delete heapZombie;
    std::cout << "\n=== Stack Zombie ===" << std::endl;
    randomChump("Stackie\n");
    return 0;
}

