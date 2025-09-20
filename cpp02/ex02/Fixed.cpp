/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:49:36 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/14 16:14:28 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixed(0) {}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->fixed = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

// ---------- Converters ----------
Fixed::Fixed(const int intValue) {
    this->fixed = intValue << fractBits;
}

Fixed::Fixed(const float floatValue) {
    this->fixed = static_cast<int>(roundf(floatValue * (1 << fractBits)));
}

float Fixed::toFloat() const {
    return static_cast<float>(fixed) / (1 << fractBits);
}

int Fixed::toInt() const {
    return fixed >> fractBits;
}

// ---------- Raw access ----------
int Fixed::getRawBits() const {
    return fixed;
}

void Fixed::setRawBits(int const raw) {
    fixed = raw;
}

// ---------- Comparison operators ----------
bool Fixed::operator>(const Fixed& other) const 
{ 
    return fixed > other.fixed;
}
bool Fixed::operator<(const Fixed& other) const 
{ 
    return fixed < other.fixed;
}
bool Fixed::operator>=(const Fixed& other) const 
{ 
    return fixed >= other.fixed; 
}
bool Fixed::operator<=(const Fixed& other) const 
{ 
    return fixed <= other.fixed; 
}
bool Fixed::operator==(const Fixed& other) const 
{ 
    return fixed == other.fixed; 
}
bool Fixed::operator!=(const Fixed& other) const 
{ 
    return fixed != other.fixed; 
}

// ---------- Arithmetic operators ----------
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->fixed + other.fixed);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->fixed - other.fixed);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// ---------- Increment / Decrement ----------
Fixed& Fixed::operator++() { 
    ++fixed;
    return *this;
}

Fixed Fixed::operator++(int) { 
    Fixed old(*this);
    fixed++;
    return old;
}

Fixed& Fixed::operator--() {
    --fixed;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed old(*this);
    fixed--;
    return old;
}

// ---------- Min / Max ----------
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// ---------- Stream insertion ----------
std::ostream& operator<<(std::ostream& os, const Fixed& fp) {
    os << fp.toFloat();
    return os;
}
