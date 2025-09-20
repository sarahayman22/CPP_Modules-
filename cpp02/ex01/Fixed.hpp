/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:18:53 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/14 13:31:25 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
    
class Fixed
{
    private:
        int                 fixid;
        static const int    fractionalBits = 8;
    public:
        Fixed();
        Fixed(const int intvalue);
        Fixed(const float floatvalue);
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &assign);
         ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
        
};
std::ostream& operator<<(std::ostream& os, const Fixed& fp);
#endif
