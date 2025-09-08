/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:05:57 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/04 09:56:02 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string  type) : type(type){}

void Weapon::setType(const std::string& newType) {
    type = newType;
}

const std::string& Weapon::getType() const {
    return type;
}

