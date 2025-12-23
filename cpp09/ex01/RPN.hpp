/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:18:12 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/12/23 16:23:57 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        void solution(std::string input);
    
    private:
        std::stack<int> numbers;
        void add();
        void sub();
        void divide();
        void multiply();
        bool isValidOperator(char c);
        bool isValidOperand();
    
    
};


#endif
