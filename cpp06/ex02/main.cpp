/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 09:56:22 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/15 16:21:44 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <exception>

Base* generate(void) {
    int r = rand() % 3;

    if (r == 0) {
        std::cout << "Generated: A" << std::endl;
        return new A();
    } else if (r == 1) {
        std::cout << "Generated: B" << std::endl;
        return new B();
    } else {
        std::cout << "Generated: C" << std::endl;
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "Identified (pointer): A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Identified (pointer): B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Identified (pointer): C" << std::endl;
    } else {
        std::cout << "Identified (pointer): Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identified (reference): A" << std::endl;
        return;
    }
    catch (const std::exception& e) {}
    try {
        (void)dynamic_cast<B&>(p); 
        std::cout << "Identified (reference): B" << std::endl;
        return; 
    }
    catch (const std::exception& e) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Identified (reference): C" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Identified (reference): Unknown type" << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    std::cout << "--- Test 1 ---" << std::endl;
    Base* obj1 = generate();
    identify(obj1);
    identify(*obj1);
    delete obj1;

    std::cout << "\n--- Test 2 ---" << std::endl;
    Base* obj2 = generate();
    identify(obj2);
    identify(*obj2);
    delete obj2;

    std::cout << "\n--- Test 3 ---" << std::endl;
    Base* obj3 = generate();
    identify(obj3);
    identify(*obj3);
    delete obj3;

    return 0;
}
