/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:39:01 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/21 17:41:45 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>

bool read_data(const std::string& path, std::string& out);

std::string replace_all(const std::string& input,
                        const std::string& s1,
                        const std::string& s2);
                        
bool write_data(const std::string& path, const std::string& data);

int copy_data(const std::string& src,
              const std::string& s1,
              const std::string& s2);


#endif
