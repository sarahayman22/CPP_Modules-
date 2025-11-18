/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:55:21 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/18 14:58:35 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T>
class Array {
    private:
        T* elements;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& rhs);
        ~Array();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        unsigned int size() const;

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#include "Array.tpp"

#endif