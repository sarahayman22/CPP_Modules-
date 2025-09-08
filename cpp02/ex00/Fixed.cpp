/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:54:37 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/08 18:18:17 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

fixidPoint::fixidPoint()
{
      this->fixid = 0;
      std::cout << "Default constructor called" << std::endl;
}

fixidPoint::fixidPoint(const fixidPoint &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

fixidPoint &fixidPoint::operator=(const fixidPoint &assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &assign)
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
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixid);
}

void fixidPoint::setRawBits( int const raw )
{
    this->fixid = raw;
    return ;
}   

