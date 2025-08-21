/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:29:31 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/21 17:39:31 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "replacer.hpp"

int main (int argc, char **argv)
{
    if(argc == 4)
        return copy_data(argv[1], argv[2], argv[3]);
    
    std::cerr <<"Invalid number of arguments.\n";
    std::cerr << "Usage: ./program <filename> <string_to_replace> <replacement_string>\n";
    return 1;
    
}