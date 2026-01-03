/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:52:41 by saabo-sh          #+#    #+#             */
/*   Updated: 2026/01/03 17:52:16 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <climits>

static bool isValid(const char *s)
{
    if (!s || s[0] == '\0')
        return 0;
    for (int i = 0; s[i]; i++)
    {
        if(s[i] < '0' || s[i] > '9')
            return false;
    }
    long value = std::strtol(s,NULL,10);
    
    if(value <= 0 || value > INT_MAX)
        return false;
    
    return true;
}

int main(int argc,char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::vector<int> v;
    std::deque<int> d;
    
    for (int i = 1; i < argc ; i++)
    {
        if (!isValid(argv[i]))
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        int value = std::atoi(argv[i]);

        v.push_back(value);
        d.push_back(value);
    }

     // Temporary output to verify input (will be replaced later)
    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
    
    
}

/////////////////////

// ❌ Invalid inputs:

// Negative numbers (-1)

// Non-numeric strings ("abc")

// Empty input

// If any error happens, you must print:

// Error

//////////////////

// What is Ford–Johnson (conceptually)

// High-level idea (no implementation details):

// Split the sequence into pairs

// Inside each pair, sort the two elements

// Take the larger elements and recursively sort them

// Insert the smaller elements into the sorted sequence

// Using a specific order (Jacobsthal sequence) to minimize comparisons

// 👉 The point:

// It minimizes the number of comparisons

// It’s complex on purpose (that’s why it’s chosen)

// 📚 Reference given:

// The Art of Computer Programming, Vol. 3, Page 184

// They expect you to study and understand the algorithm, not improvise.
/////////////////

// main.cpp

// Argument parsing

// Error handling

// Calls sorting logic