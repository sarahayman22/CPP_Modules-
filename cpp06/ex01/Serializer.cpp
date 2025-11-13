/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:08:46 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/13 16:57:21 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& src) {}
Serializer& Serializer::operator=(const Serializer& rhs) { return *this; }
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
    // Re-interpret the bits of the pointer 'ptr' as an unsigned integer
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    // Re-interpret the bits of the integer 'raw' as a pointer to Data
    return reinterpret_cast<Data*>(raw);
}