/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:54:11 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/16 17:28:25 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void printNumber(int const & num) {
    std::cout << num << " ";
}

void addOne(int & num) {
    num = num + 1;
}

int main(void) 
{
    int numbers[] = {1, 2, 3, 4, 5};
    std::cout << "** Test 1: Non-const array **" << std::endl;

    std::cout << "Original: ";
    iter(numbers, 5, printNumber);
    std::cout << std::endl;

    iter(numbers, 5, addOne);

    std::cout << "Modified: ";
    iter(numbers, 5, printNumber);
    std::cout << std::endl << std::endl;

    const int const_numbers[] = {10, 20, 30};
    std::cout << "** Test 2: Const array **" << std::endl;

    std::cout << "Printing: ";
    iter(const_numbers, 3, printNumber);
    std::cout << std::endl;

    // iter(const_numbers, 3, addOne); 
    
    return 0;
}