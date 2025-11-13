/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:24:23 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/12 15:17:21 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>    
#include <cstdlib>   
#include <cerrno>   
#include <cmath>       
#include <iomanip> 

void ScalarConverter::convertFromChar(const std::string& literal) {
    char c = literal[1];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    printChar(c, true);
    printInt(i, true);
    printFloat(f, true);
    printDouble(d, true);
}

void ScalarConverter::convertFromInt(const std::string& literal) {
    char* endptr;
    long l = std::strtol(literal.c_str(), &endptr, 10);
    
    if (errno == ERANGE || l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min()) {
        printChar(0, false);
        printInt(0, false);
        double d_overflow = std::strtod(literal.c_str(), NULL);
        printFloat(static_cast<float>(d_overflow), true);
        printDouble(d_overflow, true);
        return;
    }
    int i = static_cast<int>(l);
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    printChar(c, true);
    printInt(l, true);
    printFloat(f, true);
    printDouble(d, true);
}

void ScalarConverter::convertFromFloat(const std::string& literal) {
    char* endptr;
    float f = std::strtof(literal.c_str(), &endptr);
    if (errno == ERANGE) {
        printChar(0, false);
        printInt(0, false);
        printFloat(f, true);
        printDouble(static_cast<double>(f), true);
        return;
    }
    char c = static_cast<char>(f);
    int i = static_cast<int>(f);
    double d = static_cast<double>(f);
    float integral_f;
    float fractional_f = std::modf(f, &integral_f);
    bool possibleInt = (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
                       && !std::isinf(f) && !std::isnan(f);
    bool possibleChar = (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max())
                        && !std::isinf(f) && !std::isnan(f) && (fractional_f == 0.0f);
    printChar(c, possibleChar);
    printInt(i, possibleInt);
    printFloat(f, true);
    printDouble(d, true);
}

void ScalarConverter::convertFromDouble(const std::string& literal) {
    char* endptr;
    double d = std::strtod(literal.c_str(), &endptr);

    if (errno == ERANGE) {
        printChar(0, false);
        printInt(0, false);
        printFloat(static_cast<float>(d), true);
        printDouble(d, true);
        return;
    }
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);
    double integral_d;
    double fractional_d = std::modf(d, &integral_d);

    bool possibleInt = (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
                       && !std::isinf(d) && !std::isnan(d);
    bool possibleChar = (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
                        && !std::isinf(d) && !std::isnan(d) && (fractional_d == 0.0);

    printChar(c, possibleChar);
    printInt(i, possibleInt);
    printFloat(f, true);
    printDouble(d, true);
}

void ScalarConverter::convertFromSpecial(const std::string& literal) {
    float f;
    double d;

    if (literal == "nan" || literal == "nanf") {
        f = std::numeric_limits<float>::quiet_NaN();
        d = std::numeric_limits<double>::quiet_NaN();
    } else if (literal == "+inf" || literal == "+inff") {
        f = std::numeric_limits<float>::infinity();
        d = std::numeric_limits<double>::infinity();
    } else { 
        f = -std::numeric_limits<float>::infinity();
        d = -std::numeric_limits<double>::infinity();
    }
    printChar(0, false);
    printInt(0, false);
    printFloat(f, true);
    printDouble(d, true);
}

