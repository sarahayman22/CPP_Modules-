/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:49:53 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/11 18:11:13 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
    
class fixidPoint
{
    private:
        int                 fixid;
        static const int    fractionalBits = 8;
    public:
        fixidPoint();
        fixidPoint(const int intvalue);
        fixidPoint(const float floatvalue);
        fixidPoint(const fixidPoint &copy);
        fixidPoint &operator=(const fixidPoint &assign);
         ~fixidPoint();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
        
        
        // Comparison operators
        bool operator>(const fixidPoint& value) const;
        bool operator<(const fixidPoint& value) const;
        bool operator>=(const fixidPoint& value) const;
        bool operator<=(const fixidPoint& value) const;
        bool operator==(const fixidPoint& value) const;
        bool operator!=(const fixidPoint& value) const;

        
        // Arithmetic operators
        Fixed operator+(const Fixed& value) const;
        Fixed operator-(const Fixed& value) const;
        Fixed operator*(const Fixed& value) const;
        Fixed operator/(const Fixed& value) const;

        // 1) non-const references: returns a non-const reference
        //  Use when you want to be able to modify the returned object.
        static fixidPoint& min(fixidPoint& a, fixidPoint &b);
       // 2) const references: returns a const reference
       //  Use when you have const objects or only need read access.
        static const fixidPoint& min(const fixidPoint& a, const fixidPoint &b);
        
        static fixidPoint& max(fixidPoint& a, fixidPoint &b);
        static const fixidPoint& max(const fixidPoint& a, const fixidPoint &b);
        
};

std::ostream& operator<<(std::ostream& os, const fixidPoint& fp);
#endif
