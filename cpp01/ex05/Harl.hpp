/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:43:51 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/26 16:12:43 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
    
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );     
   
     public:
        Harl();
        void complain( std::string level );
};          


#endif 
