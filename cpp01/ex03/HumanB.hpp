/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:20:09 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/13 16:31:59 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
    std::string name;
    Weapon* weapon;

    public:
    HumanB(std::string name);
    void setWeapon(Weapon& newWeapon);
    void attack() const;
};
#endif


// Reference = “You must give me this object when I’m created, and I’ll keep it forever.”

// Pointer = “I might have an object, I might not. You can change it later.”

