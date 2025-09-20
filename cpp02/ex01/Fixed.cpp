/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:08:37 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/14 13:34:03 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : fixid(0)
{
      std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intvalue)
{
    std::cout << "Int constructor called" << std::endl;
    fixid = intvalue << fractionalBits;
}

Fixed::Fixed(const float floatvalue)
{
    std::cout << "Float constructor called" << std::endl;
    fixid = static_cast<int>(roundf(floatvalue *(1 << fractionalBits)));
    
}

float   Fixed::toFloat( void ) const 
{
    return ( static_cast<float>(fixid) / (1 << fractionalBits));
}

 int Fixed::toInt() const 
{    
    return (fixid >> fractionalBits); 
}
 

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &assign)
        this->fixid = assign.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int Fixed::getRawBits( void ) const
{
    return (this->fixid);
}

void Fixed::setRawBits( int const raw )
{
    this->fixid = raw;
}   

std::ostream& operator<<(std::ostream& os, const Fixed& fp)
{
    os << fp.toFloat();
    return os;
}

