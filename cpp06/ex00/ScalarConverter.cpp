/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:51:42 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/08 17:48:35 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>    // Required for std::modf and std::fabs
#include <limits>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { (void)rhs; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        char c = literal[0];
        double d = static_cast<double>(c);
        printChar(d);
        printInt(d);
        printFloat(d);
        printDouble(d);
        return;
    }

    char* end = NULL;
    double d = std::strtod(literal.c_str(), &end);

    if (end == literal.c_str() ||
        (*end != '\0' && (*end != 'f' || end[1] != '\0')))
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void ScalarConverter::printChar(double d)
{
    std::cout << "char: ";

    if (std::isnan(d) || std::isinf(d) ||
        d < std::numeric_limits<char>::min() ||
        d > std::numeric_limits<char>::max())
    {
        std::cout << "impossible\n";
        return;
    }

    char c = static_cast<char>(d);

    if (!std::isprint(c))
    {
        std::cout << "Non displayable\n";
        return;
    }

    std::cout << "'" << c << "'\n";
}

void ScalarConverter::printInt(double d)
{
    std::cout << "int: ";

    if (std::isnan(d) || std::isinf(d) ||
        d < std::numeric_limits<int>::min() ||
        d > std::numeric_limits<int>::max())
    {
        std::cout << "impossible\n";
        return;
    }

    std::cout << static_cast<int>(d) << "\n";
}

void ScalarConverter::printFloat(double d)
{
    std::cout << "float: ";

    if (std::isnan(d)) {
        std::cout << "nanf" << std::endl;
        return;
    }
    if (std::isinf(d)) {
        if (d > 0)
            std::cout << "inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
        return;
    }

    float f = static_cast<float>(d);
    double int_part;
    
    // Check for "huge" or "tiny" numbers FIRST
    // We define "huge" as >= 1,000,000 (1e6) or "tiny" as < 0.001.
    // These numbers should use default/scientific notation.
    if (std::fabs(f) >= 1e6f || (std::fabs(f) < 0.001f && f != 0.0f))
    {
        std::cout << std::setprecision(6) << f << "f" << std::endl;
    }
    // THEN: Check for "normal" whole numbers
    // If it's not huge/tiny, check if it's a whole number.
    else if (std::modf(f, &int_part) == 0.0f)
    {
        // Use std::fixed to print "42.0f", "0.0f", etc.
        std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout.unsetf(std::ios::fixed);
        std::cout.precision(6);
    }
    // ELSE: It's a "normal" fractional number
    else
    {
        // Use default notation for "4.2f"
        std::cout << std::setprecision(6) << f << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double d)
{
    std::cout << "double: ";

    if (std::isnan(d))
    {
        std::cout << "nan\n";
        return;
    }
    if (std::isinf(d))
    {
        if (d > 0) std::cout << "inf\n";
        else std::cout << "-inf\n";
        return;
    }

    double int_part;

    // Apply the same logic as printFloat
    // Check for "huge" or "tiny" numbers FIRST.
    if (std::fabs(d) >= 1e6 || (std::fabs(d) < 0.001 && d != 0.0))
    {
        std::cout << std::setprecision(6) << d << std::endl;
    }
    // THEN: Check for "normal" whole numbers.
    else if (std::modf(d, &int_part) == 0.0)
    {
        // Use std::fixed to print "42.0"
        std::cout << std::fixed << std::setprecision(1) << d << std::endl;
        std::cout.unsetf(std::ios::fixed);
        std::cout.precision(6);
    }
    // ELSE: It's a "normal" fractional number.
    else
    {
        // Use default notation for "4.2"
        std::cout << std::setprecision(6) << d << std::endl;
    }
}
