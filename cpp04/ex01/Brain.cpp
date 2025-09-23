/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:07:15 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/23 12:25:53 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "[Brain] Default constructor\n";
    for (int i = 0; i < N; ++i)
        ideas[i] = std::string();
}

Brain::Brain(const Brain &other)
{
    std::cout << "[Brain] Copy constructor\n";
    for (int i = 0; i < N; ++i)
        ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "[Brain] Assignment operator\n";
    if (this == &other)
        return *this;
    for (int i = 0; i < N; ++i)
        ideas[i] = other.ideas[i];
    return *this;
}

Brain::~Brain()
{
    std::cout << "[Brain] Destructor\n";
}

void Brain::setIdea(int idx, const std::string &idea)
{
    if (idx < 0 || idx >= N)
        return;
    ideas[idx] = idea;
}

std::string Brain::getIdea(int idx) const
{
    if (idx < 0 || idx >= N)
        return std::string();
    return ideas[idx];
}
