/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:51:42 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/15 15:53:31 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.cpp"
#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

bool isInt(const std::string& literal) {
    char* endptr;
    errno = 0;
    long l = std::strtol(literal.c_str(), &endptr, 10);
    if (*endptr != '\0') {
        return false;
    }
    if (errno == ERANGE || l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min()) {
        return false;
    }
    return true;
}

bool isFloat(const std::string& literal) {
    if (literal[literal.length() - 1] != 'f' || literal.length() == 1) {
        return false;
    }
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        return false;
    }

    char* endptr;
    errno = 0;
    std::strtof(literal.c_str(), &endptr);
    
    return (*endptr == 'f' && *(endptr + 1) == '\0' && errno != ERANGE);
}

bool isDouble(const std::string& literal) {
    if (literal.find('.') == std::string::npos) {
        return false;
    }
    if (literal[literal.length() - 1] == 'f') {
        return false;
    }
    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        return false;
    }
    char* endptr;
    errno = 0;
    std::strtod(literal.c_str(), &endptr);
    return (*endptr == '\0' && errno != ERANGE);
}

ScalarConverter::e_type ScalarConverter::detectType(const std::string& literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf" ||
        literal == "nanf" || literal == "+inff" || literal == "-inff") {
        return SPECIAL;
    }
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        return CHAR;
    }
    if (isInt(literal)) {
        return INT;
    }
    if (isFloat(literal)) {
        return FLOAT;
    }
    if (isDouble(literal)) {
        return DOUBLE;
    }
    return INVALID;
}

void ScalarConverter::convert(const std::string& literal) {
    e_type type = detectType(literal);

    switch (type) {
        case CHAR:
            convertFromChar(literal);
            break;
        case INT:
            convertFromInt(literal);
            break;
        case FLOAT:
            convertFromFloat(literal);
            break;
        case DOUBLE:
            convertFromDouble(literal);
            break;
        case SPECIAL:
            convertFromSpecial(literal);
            break;
        case INVALID:
        default:
            std::cout << "Invalid input literal." << std::endl;
            break;
    }
}

void ScalarConverter::printChar(char c, bool possible) {
    std::cout << "char: ";
    if (!possible) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(c)) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << c << "'" << std::endl;
    }
}

void ScalarConverter::printInt(long l, bool possible) {
    std::cout << "int: ";
    if (!possible || l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(l) << std::endl;
    }
}

void ScalarConverter::printFloat(float f, bool possible) {
    std::cout << "float: ";
    if (!possible) {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (std::isnan(f)) {
        std::cout << "nanf" << std::endl;
    } else if (std::isinf(f)) { 
        std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
    } else {
        float integral;
        float fractional = std::modf(f, &integral);
        if (fractional == 0.0f && std::fabs(f) < 1000000.0f) {
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        } else {
            std::cout << std::noshowpoint << f << "f" << std::endl;
        }
    }
}

void ScalarConverter::printDouble(double d, bool possible) {
    std::cout << "double: ";
    if (!possible) {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (std::isnan(d)) {
        std::cout << "nan" << std::endl;
    } else if (std::isinf(d)) {
        std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
    } else {
        double integral;
        double fractional = std::modf(d, &integral);
        if (fractional == 0.0 && std::fabs(d) < 1000000.0) {
            std::cout << std::fixed << std::setprecision(1) << d << std::endl;
        } else {
            std::cout << std::noshowpoint << d << std::endl;
        }
    }
}