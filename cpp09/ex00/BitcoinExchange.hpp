/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:54:39 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/12/09 14:48:33 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, float> _db;
    bool isValidDate(const std::string &date) const;
    bool isValidNumber(const std::string &s) const;   

public:
    BitcoinExchange();
    void loadDatabase(const std::string &filename);
    void processInputFile(const std::string &filename);
};

#endif