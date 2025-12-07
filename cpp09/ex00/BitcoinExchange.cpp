/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:57:35 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/12/07 17:48:12 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>


BitcoinExchange::BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if(!file.is_open())
    {
        std::cerr<<"Error : could't open database file."<<std::endl;
        return;
    }
    std::string line;
    getline(file,line);//skip the header 
    while (std::getline(file,line))
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos) //std::string::npos means:
              continue;                //❌ “I did NOT find the comma.”
        std::string date = line.substr(0,pos);
        std::string priceStr = line.substr(pos + 1);
        
        float price = std::strtof(priceStr.c_str(), NULL);
         _db[date]= price;
        
    }
    
    for (std::map<std::string, float>::iterator it = _db.begin(); it != _db.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }

    
}