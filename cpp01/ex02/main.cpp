/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:19:39 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/30 18:56:21 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";

     std::string* stringPTR = &brain;
     
     std::string& stringREF = brain;

    std::cout << "Address of brain:      " << &brain << std::endl;
    std::cout << "Address held by PTR:   " << stringPTR << std::endl;
    std::cout << "Address held by REF:   " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "Value of brain:        " << brain << std::endl;
    std::cout << "Value pointed by PTR:  " << *stringPTR << std::endl;
    std::cout << "Value accessed by REF: " << stringREF << std::endl;

    return 0;
     
     
    

}