/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:18:00 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/12/23 17:03:02 by saabo-sh         ###   ########.fr       */
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

void RPN::add(){
	int n1 = numbers.top();
	numbers.pop();
	int n2= numbers.top();
	numbers.pop();
	numbers.push(n1 + n2);
}

void RPN::sub(){
	int n2 = numbers.top();
	numbers.pop();
	int n1= numbers.top();
	numbers.pop();
	numbers.push(n1 - n2);
}

void RPN::divide(){
	int n2 = numbers.top();
	numbers.pop();
	int n1 = numbers.top();
	numbers.pop();
	if (n2 == 0)
	{
		std::cerr << "Error: can't divide by zeroo" << std::endl;
		numbers.push(n1);
		numbers.push(n2);
		return;		
	}
	numbers.push(n1/n2);
}

void RPN::multiply(){
	int n1 = numbers.top();
	numbers.pop();
	int n2= numbers.top();
	numbers.pop();
	numbers.push(n1 * n2);
}

bool RPN::isValidOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::isValidOperand()
{
	return numbers.size() >= 2;
}

void RPN::solution(std::string input)
{
	for (size_t i = 0; i < input.size(); ++i){
		char c = input[i];
		if (c == ' ')
			continue;
		else if ((isdigit(c)))
			numbers.push( c - '0');
		else if (isValidOperand() && isValidOperator(c))
		{
			if (c == '+')
				add();
			else if (c == '-')
                sub();
			else if (c == '*')
                multiply();
			else if (c == '/')
                divide();
		} else {
			std::cout << "Error: Invalid input" << std::endl;
			return;
		}
	}
	if (numbers.size() == 1){
		std::cout << "result: "<<numbers.top()<< std::endl;
		numbers.pop();
	}
	else{
		std::cerr<< "Error:Invalid input"<< std::endl;
	}
	
}