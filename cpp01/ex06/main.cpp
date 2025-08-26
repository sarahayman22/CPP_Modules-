/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:35:53 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/26 17:47:26 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }
    std::string level = argv[1];
    Harl h;
    // Map level string to index
    int index = -1;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            index = i;
            break;
        }
    }

    switch (index) {
    case 0:
        std::cout << "[ DEBUG ]" << std::endl;
        h.complain("DEBUG");
        std::cout << std::endl;
    case 1: 
        std::cout << "[ INFO ]" << std::endl;
        h.complain("INFO");
        std::cout << std::endl;
    case 2: 
        std::cout << "[ WARNING ]" << std::endl;
        h.complain("WARNING");
        std::cout << std::endl;
    case 3:
        std::cout << "[ ERROR ]" << std::endl;
        h.complain("ERROR");
        std::cout << std::endl;
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }

    return 0;
}
