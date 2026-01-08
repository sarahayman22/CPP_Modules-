/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:52:41 by saabo-sh          #+#    #+#             */
/*   Updated: 2026/01/08 18:02:41 by saabo-sh         ###   ########.fr       */
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
        return 0;
    for (int i = 0; s[i]; i++)
    {
        if(s[i] < '0' || s[i] > '9')
            return false;
    }
    long value = strtol(s, NULL, 10);
    if(value <= 0 || value > INT_MAX)
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
    std::deque<int> q;

    for (int i = 1; i < argc; i++)
    {
        if (!isValid(argv[i]))
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        int valueInt = atoi(argv[i]);
        v.push_back(valueInt);
        q.push_back(valueInt);
    }

    PmergeMe pm(v, q);

    pm.printBefore();
    pm.debugPrintPairs();
    pm.debugPrintMainChain();

    pm.printAfter();  // vector result

    // ---------------- Deque test ----------------
    pm.makePairsDequePublic(q);
    pm.sortPairsDequePublic();
    pm.buildMainChainDequePublic();
    pm.insertPendingDequePublic();

    pm.printAfterDeque();

    return 0;
}
