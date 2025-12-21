/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:18:28 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/12/21 17:59:09 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
         std::cerr << "Error" << std::endl;
            return 1;
    }
    RPN rpn;
    rpn.cal(argv[1]);
    return 0;
}