/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:24:59 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/23 17:10:35 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try {
        std::list<int>::iterator it = easyfind(lst, 5);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}