/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:24:45 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/27 16:38:01 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : n(N) {}

Span::Span(const Span& other) {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        n = other.n;
        v = other.v;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
{
    if (v.size() >= n)
        throw std::runtime_error("span is full");
    v.push_back(num);
}

int Span::shortestSpan()
{
    if(v.size() < 2)
        throw std::runtime_error("not enough numbers");
    
    std::vector<int> temp = v;
    std::sort(temp.begin(), temp.end());
    
    int min = temp[1] - temp[0];

    for (size_t i = 1; i < temp.size() - 1; i++)
    {
        int span = temp[i + 1] - temp[i];
        if (span < min)
            min = span;
    }
    return min;
}

int Span::longestSpan()
{
    if (v.size() < 2)
        throw std::runtime_error("Not enough numbers");
    
    int minVal = *std::min_element(v.begin(), v.end());
    int maxVal = *std::max_element(v.begin(), v.end());
    
    return maxVal - minVal;
}