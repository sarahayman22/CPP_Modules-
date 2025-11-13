/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:28:20 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/09 16:20:43 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter {

public:
    static void convert(const std::string& literal);

private:
    // --- Enforce Static Class ---
    // Making constructors and destructor private prevents instantiation.
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    // --- Type Detection ---
    // Enum to store the detected type
    enum e_type { CHAR, INT, FLOAT, DOUBLE, SPECIAL, INVALID };
    static e_type   detectType(const std::string& literal);

    // --- Conversion Handlers ---
    // These functions are called *after* the type is detected.
    static void convertFromChar(const std::string& literal);
    static void convertFromInt(const std::string& literal);
    static void convertFromFloat(const std::string& literal);
    static void convertFromDouble(const std::string& literal);
    static void convertFromSpecial(const std::string& literal);

    // --- Printing Helpers ---
    // These helpers manage the output logic for each type.
    static void printChar(char c, bool possible);
    static void printInt(long l, bool possible);
    static void printFloat(float f, bool possible);
    static void printDouble(double d, bool possible);
};

#endif