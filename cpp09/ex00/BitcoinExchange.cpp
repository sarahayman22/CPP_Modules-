/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:57:35 by saabo-sh          #+#    #+#             */
/*   Updated: 2026/01/11 14:46:05 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

static void trim(std::string &s)
{
    while (!s.empty() && isspace(s[0]))
        s.erase(0, 1);

    while (!s.empty() && isspace(s[s.size() - 1]))
        s.erase(s.size() - 1, 1);
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    std::string y = date.substr(0, 4);
    std::string m = date.substr(5, 2);
    std::string d = date.substr(8, 2);

    for (size_t i = 0; i < y.size(); i++)
        if (!isdigit(y[i])) return false;

    for (size_t i = 0; i < m.size(); i++)
        if (!isdigit(m[i])) return false;

    for (size_t i = 0; i < d.size(); i++)
        if (!isdigit(d[i])) return false;
    
    int year  = atoi(y.c_str());
    int month = atoi(m.c_str());
    int day = atoi(d.c_str());
    
    if (month < 1 || month > 12)
        return false;
    int daysInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (leapYear) 
        daysInMonth[1] = 29;
    if (day < 1 || day > daysInMonth[month - 1])
        return false;
        
    return true;
}

bool BitcoinExchange::isValidNumber(const std::string &s) const
{
    if (s.empty())
        return false;

    size_t i = 0;
    bool dot = false;

    if (s[0] == '-')
        i = 1;

    if (i == s.size())
        return false;

    for (; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            if (dot) return false;
            dot = true;
        }
        else if (!isdigit(s[i]))
            return false;
    }
    return true;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;
    
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;

        std::string date = line.substr(0, pos);
        std::string priceStr = line.substr(pos + 1);

        float price = std::strtof(priceStr.c_str(), NULL);
        _db[date] = price;
    }
}

void BitcoinExchange::processInputFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pos);
        std::string valueStr = line.substr(pos + 1);

        trim(date);
        trim(valueStr);

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidNumber(valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float value = std::strtof(valueStr.c_str(), NULL);

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator it = _db.lower_bound(date);

        if (it == _db.end())
            --it;
        else if (it->first != date)
        {
            if (it == _db.begin())
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            --it;
        }

        float rate = it->second;
        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }
}
