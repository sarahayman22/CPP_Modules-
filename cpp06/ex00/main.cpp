/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:03:46 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/15 15:53:09 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: Wrong number of arguments." << std::endl;
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	//ScalarConverter myConverter; // COMPILE ERROR!
	
	ScalarConverter::convert(argv[1]);
	return 0;
}