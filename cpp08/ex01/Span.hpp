/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:24:32 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/27 16:40:41 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

class Span{
    unsigned int n;
    std::vector<int> v;

    public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    /*Why two addNumber functions?

One adds a single number: convenient for small cases.

One adds many numbers at once using iterators: convenient for filling thousands of numbers.

This is function overloading: same function name, different parameters.*/
    void addNumber(int num);
    
    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end)
    {
        unsigned int distance = std::distance(begin, end);
        if (v.size() + distance > n)
            throw std::runtime_error("span is full");
        
        v.insert(v.end(), begin, end);
    }

    int shortestSpan();
    int longestSpan();    
};

#endif