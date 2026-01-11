/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:52:41 by saabo-sh          #+#    #+#             */
/*   Updated: 2026/01/11 14:39:31 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <climits>

static bool isValid(const char *s)
{
    if (!s || s[0] == '\0')
        return false;

    for (int i = 0; s[i]; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }

    long value = std::strtol(s, NULL, 10);
    if (value <= 0 || value > INT_MAX)
        return false;

    return true;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> v;
    std::deque<int>  q;

    for (int i = 1; i < argc; i++)
    {
        if (!isValid(argv[i]))
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }

        int value = std::atoi(argv[i]);
        v.push_back(value);
        q.push_back(value);
    }

    std::cout << "Before: ";
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;

    PmergeMe pm(v, q);
    double timeVec = pm.sortVectorWithTime();
    double timeDeq = pm.sortDequeWithTime();

    pm.printAfter();

    std::cout << "Time to process a range of "
              << v.size()
              << " elements with std::vector : "
              << timeVec
              << " us" << std::endl;

    std::cout << "Time to process a range of "
              << v.size()
              << " elements with std::deque  : "
              << timeDeq
              << " us" << std::endl;

    return 0;
}



