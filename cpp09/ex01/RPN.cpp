/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:18:00 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/12/21 17:58:00 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

RPN::RPN() {}

RPN::~RPN() {}


RPN::RPN(const RPN& other) : numbers(other.numbers) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		numbers = other.numbers;
	}
	return *this;
}
