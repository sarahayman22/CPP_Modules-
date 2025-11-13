/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:08:16 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/13 17:19:19 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    // 1. Create a non-empty Data object on the stack
    Data myData;
    myData.s1 = "Hello";
    myData.n = 42;
    myData.s2 = "World!";

    // 2. Get the original pointer (address) of the object
    // create a pointer
    Data* originalPtr = &myData;

    std::cout << "--- Original ---" << std::endl;
    std::cout << "Address (ptr):   " << originalPtr << std::endl;
    std::cout << "Content (s1):    " << originalPtr->s1 << std::endl;
    std::cout << "Content (n):     " << originalPtr->n << std::endl;
    std::cout << "Content (s2):    " << originalPtr->s2 << std::endl;
    std::cout << std::endl;
/*
2. The "Serialized" Block
C++

// 3. Serialize the pointer to an integer
uintptr_t raw = Serializer::serialize(originalPtr);
Serializer::serialize(originalPtr): This function takes the pointer originalPtr (which holds the value 0x7fff447ef7f0).

Inside the function, it performs a reinterpret_cast. This cast tells the computer: "Stop thinking of this value as a memory address. Start thinking of it as a simple unsigned integer."

uintptr_t raw = ...: The function returns this new integer, and you store it in a variable named raw.

Output:

Raw integer (uintptr_t): 140734342559728
Raw integer (hex):       0x7fff447ef7f0
This is the most important part! It shows that the memory address and the integer are the exact same number, just represented in different ways:

Hexadecimal (base 16): 0x7fff447ef7f0

Decimal (base 10): 140734342559728

You have successfully stored a memory address in a plain integer variable. The data in myData ("Hello", 42, etc.) has not been touched or moved.*/
    // 3. Serialize the pointer to an integer
    uintptr_t raw = Serializer::serialize(originalPtr);

    std::cout << "--- Serialized ---" << std::endl;
    std::cout << "Raw integer (uintptr_t): " << raw << std::endl;
    std::cout << "Raw integer (hex):       0x" << std::hex << raw << std::dec << std::endl;
    std::cout << std::endl;

    /*
    3. The "Deserialized" Block
C++

// 4. Deserialize the integer back into a pointer
Data* deserializedPtr = Serializer::deserialize(raw);
Serializer::deserialize(raw): This function takes the integer raw (which holds the value 140734342559728).

Inside the function, it performs the opposite reinterpret_cast. This cast tells the computer: "Stop thinking of this number as an integer. Start thinking of it as a memory address that points to a Data object."

Data* deserializedPtr = ...: The function returns this new pointer, and you store it in a variable named deserializedPtr.

Output:

Address (ptr):   0x7fff447ef7f0
As you can see, the value of deserializedPtr is 0x7fff447ef7f0—exactly the same as the originalPtr. When the code then prints deserializedPtr->s1, it goes to that same memory address, finds the myData object, and correctly prints its contents ("Hello", 42, "World!").
*/
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