/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:03:46 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/08 13:27:33 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream> // For std::cerr, std::endl

int main(int argc, char **argv) {
	// Must have exactly one argument
	if (argc != 2) {
		std::cerr << "Error: Wrong number of arguments." << std::endl;
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}

	// Pass the first argument (argv[1]) to the static convert method
	ScalarConverter::convert(argv[1]);
	return 0;
}