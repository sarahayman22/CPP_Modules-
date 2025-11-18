/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:52:05 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/18 17:06:27 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> arr(5);
        std::cout << "Array size: " << arr.size() << std::endl;

        for (unsigned int i = 0; i < arr.size(); i++)
            arr[i] = i;

        Array<int> copy = arr; 
        copy[0] = 999; 

        std::cout << "Original[0]: " << arr[0] << std::endl;
        std::cout << "Copy[0]:     " << copy[0] << std::endl;

        std::cout << "Accessing index 10..." << std::endl;
        arr[10] = 42; 
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}