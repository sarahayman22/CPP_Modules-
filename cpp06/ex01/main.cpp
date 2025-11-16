/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:08:16 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/15 16:11:25 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data myData;
    myData.s1 = "Hello";
    myData.n = 42;
    myData.s2 = "World!";

    Data* originalPtr = &myData;

    std::cout << "--- Original ---" << std::endl;
    std::cout << "Address (ptr):   " << originalPtr << std::endl;
    std::cout << "Content (s1):    " << originalPtr->s1 << std::endl;
    std::cout << "Content (n):     " << originalPtr->n << std::endl;
    std::cout << "Content (s2):    " << originalPtr->s2 << std::endl;
    std::cout << std::endl;

// 3. Serialize the pointer to an integer
    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout << "--- Serialized ---" << std::endl;
    std::cout << "Raw integer (uintptr_t): " << raw << std::endl;
    std::cout << "Raw integer (hex):       0x" << std::hex << raw << std::dec << std::endl;
    std::cout << std::endl;
    
// 4. Deserialize the integer back into a pointer
    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "--- Deserialized ---" << std::endl;
    std::cout << "Address (ptr):   " << deserializedPtr << std::endl;
    std::cout << "Content (s1):    " << deserializedPtr->s1 << std::endl;
    std::cout << "Content (n):     " << deserializedPtr->n << std::endl;
    std::cout << "Content (s2):    " << deserializedPtr->s2 << std::endl;
    std::cout << std::endl;

    // 5. The final check
    std::cout << "--- Verification ---" << std::endl;
    if (originalPtr == deserializedPtr) {
        std::cout << "✅ SUCCESS: originalPtr and deserializedPtr are the same!" << std::endl;
        std::cout << "They both point to the same data (n = " << deserializedPtr->n << ")" << std::endl;
    } else {
        std::cout << "❌ FAILURE: Pointers do NOT match!" << std::endl;
    }

    return 0;
}