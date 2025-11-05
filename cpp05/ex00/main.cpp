/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:22:01 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/18 17:36:12 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat sara("sara", 42);
        std::cout<< sara << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "exception: "<< e.what()<< std::endl;
        
    }
    std::cout <<"**********************************************"<<std::endl;
    try
    {
        Bureaucrat a("high",0);
        std::cout<< a <<std::endl;
    }
    catch (std::exception &e)
    {
        std::cout<< "caught: " <<e.what()<<std::endl;
    }
    std::cout <<"**********************************************"<<std::endl;
    try 
    {
        Bureaucrat b("low", 151);
        std::cout<< b<< std::endl;
    }
    catch (std::exception &e)
    {
        std::cout<< "caught: " << e.what() << std::endl;
    }
    std::cout <<"**********************************************"<<std::endl;
     try {
        Bureaucrat d("NearTop", 2);
        std::cout << d << std::endl;
        d.incrementGrade(); 
        std::cout << "after increment: " << d << std::endl;
        d.incrementGrade();
        std::cout << "after increment2: " << d << std::endl;
    } catch (std::exception &e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    std::cout <<"**********************************************"<<std::endl;
     try {
        Bureaucrat e("NearBottom", 149);
        std::cout << e << std::endl;
        e.decrementGrade();
        std::cout << "after decrement: " << e << std::endl;
        e.decrementGrade();
        std::cout << "after decrement2: " << e << std::endl;
    } catch (std::exception &ex) {
        std::cout << "Caught: " << ex.what() << std::endl;
    }
std::cout <<"**********************************************"<<std::endl;
       try {
        Bureaucrat orig("Orignal", 10);
        Bureaucrat copy = orig;
        std::cout << "orig: " << orig << "\ncopy: " << copy << std::endl;

        Bureaucrat target("TargetName", 50);
        std::cout << "before assign target: " << target << std::endl;
        target = orig;
        std::cout << "after assign target: " << target << std::endl;

        copy.decrementGrade(); 
        std::cout << "after modifying copy: orig: " << orig << ", copy: " << copy << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}