/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:50:59 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/16 16:50:32 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WHATEVER_HPP
#ifdef  WHATEVER_HPP

template <typename T> void swap (T &x, T &y)
{
    T z = x;
    x = y ;
    y = z ;
}

template <typename T> T min (T x, T y)
{
    return (x < y) ? x : y;
}

template <typename T> T max (T x, T y)
{

    return (x > y) ? x : y;
}


#endif 
