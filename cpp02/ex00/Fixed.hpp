/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:54:57 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/08 18:00:22 by saabo-sh         ###   ########.fr       */
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
        fixidPoint(const fixidPoint &copy);
        fixidPoint &operator=(const fixidPoint &assign);
         ~fixidPoint();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};

#endif
