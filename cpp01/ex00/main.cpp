/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 14:51:42 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/07 16:51:19 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 🧠 Objective Summary
// You're building a Zombie class in C++ and learning the difference between:

// Heap allocation (new): manual memory management (requires delete)

// Stack allocation: automatic, destroyed when it goes out of scope

#include "Zombie.hpp"

#include <iostream>

int main() {
    std::cout << "=== Heap Zombie ===" << std::endl;
    Zombie* heapZombie = newZombie("Heapie\n");
    std::cout<<"\n";
    heapZombie->announce();
     std::cout<<"\n";
    delete heapZombie;
    std::cout << "\n=== Stack Zombie ===" << std::endl;
    randomChump("Stackie\n");
    return 0;
}

