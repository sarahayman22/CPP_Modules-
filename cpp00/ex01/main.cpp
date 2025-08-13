/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:26:33 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/07/31 16:32:52 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook book;
    std::string userInput;
    
    while(42)
    {
        std::cout <<"Enter one of these  (ADD, SEARCH and EXIT) : " << std::endl;
        if (!std::getline(std::cin, userInput)) 
        {
            std::cout << "Exiting program.\n";
            break;
        }
          if (userInput == "ADD")
            book.addContact();
        else if (userInput == "SEARCH")
            book.search();
        else if (userInput == "EXIT")
            break;
        else
         std::cerr << "Enter valid command!" << std::endl;
    }
    
    return 0;
}
