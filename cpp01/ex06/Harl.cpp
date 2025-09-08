/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:36:04 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/04 12:57:42 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}

void Harl::debug() {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;        
}   
                                        
void Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;        
}  
 

void Harl::complain(std::string level) {
    
    typedef void (Harl::*Action)();
    const std::string names[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    Action actions[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    for (int i = 0; i < 4; ++i) {
        if (names[i] == level) {
            (this->*actions[i])();   
            return;
        }
    }

    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
