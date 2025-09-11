/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:18:53 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/11 13:51:49 by saabo-sh         ###   ########.fr       */
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
        
};
std::ostream& operator<<(std::ostream& os, const fixidPoint& fp);
#endif
