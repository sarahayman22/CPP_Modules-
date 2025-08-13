/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:19:39 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/07 18:40:58 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";

    // A pointer stores the address of another variable.
    // stringPTR holds the address of brain.
    // To access the value, use *stringPTR
     std::string* stringPTR = &brain;
    //  A reference is like a nickname for an existing variable.
    // stringREF is another way to access brain.
    // It does not store an address separately like a pointer — it's just an alias.
     std::string& stringREF = brain;

         // Print memory addresses
    std::cout << "Address of brain:      " << &brain << std::endl;
    std::cout << "Address held by PTR:   " << stringPTR << std::endl;
    std::cout << "Address held by REF:   " << &stringREF << std::endl;

    std::cout << std::endl;

    // Print values
    std::cout << "Value of brain:        " << brain << std::endl;
    std::cout << "Value pointed by PTR:  " << *stringPTR << std::endl;
    std::cout << "Value accessed by REF: " << stringREF << std::endl;

    return 0;
     
     
    

}