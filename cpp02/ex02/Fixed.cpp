/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:49:36 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/11 18:13:50 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cmath>
#include "Fixed.hpp"

fixidPoint::fixidPoint() : fixid(0)
{
      std::cout << "Default constructor called" << std::endl;
}

fixidPoint::fixidPoint(const int intvalue)
{
    std::cout << "Int constructor called" << std::endl;
    fixid = intvalue << fractionalBits; //shift the int left by 8 bits == *2^8
}

fixidPoint::fixidPoint(const float floatvalue)
{
    std::cout << "Float constructor called" << std::endl;
    fixid = roundf(floatvalue *(1 << fractionalBits));
    
}

float   fixidPoint::toFloat( void ) const 
{
    return ((float)fixid / (1 << fractionalBits));
}

 int fixidPoint::toInt() const 
{    
    return (fixid >> fractionalBits); // shift right by 8 bits
}
 

fixidPoint::fixidPoint(const fixidPoint &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy; // Reuses the assignment operator
}

fixidPoint &fixidPoint::operator=(const fixidPoint &assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &assign) // Prevent self-assignment
        this->fixid = assign.getRawBits();
    return (*this);
}

fixidPoint::~fixidPoint()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int fixidPoint::getRawBits( void ) const
{
    return (this->fixid);
}

void fixidPoint::setRawBits( int const raw )
{
    this->fixid = raw;
}   

std::ostream& operator<<(std::ostream& os, const fixidPoint& fp)
{
    os << fp.toFloat();
    return os;
}


//02 start


// operators 

//const means we cannot modify value inside the function.
//const at the end → means this function does not modify the current object (*this).
bool Fixed::operator>(const Fixed& value) const 
{ 
    return this->raw > value.raw; 
}
bool Fixed::operator<(const Fixed& value) const 
{ 
    return this->raw < value.raw; 
}
bool Fixed::operator>=(const Fixed& value) const 
{
     return this->raw >= value.raw; 
}
bool Fixed::operator<=(const Fixed& value) const 
{ 
    return this->raw <= value.raw;
}
bool Fixed::operator==(const Fixed& value) const 
{ 
    return this->raw == value.raw; 
}
bool Fixed::operator!=(const Fixed& value) const 
{ 
    return this->raw != value.raw;
}



static  fixidPoint& min (fixidPoint& a, fixidPoint &b)
 {
     return (a < b) ? a : b;
 }

static const fixidPoint& min (const fixidPoint& a, const fixidPoint &b)
{
     return (a < b) ? a : b;
}  


static  fixidPoint& max (fixidPoint& a, fixidPoint &b)
 {
     return (a > b) ? a : b;
 }

static const fixidPoint& max (const fixidPoint& a, const fixidPoint &b)
{
     return (a > b) ? a : b;
}  