/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:55:42 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/12 19:46:45 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include<string>

class Weapon {
    std::string type;

public:
    Weapon(std::string type);
    void setType(const std::string& newType);
    const std::string& getType() const;
};


#endif 



// +----------------+
// |    Weapon      |
// +----------------+
// | - type: string |
// +----------------+
// | + Weapon(t: string)         |
// | + getType(): const string&  |
// | + setType(t: string): void  |
// +----------------+

//         ▲
//         |
//         |  (Reference in HumanA)
//         |
// +----------------+
// |    HumanA      |
// +----------------+
// | - name: string |
// | - weapon: Weapon& |
// +----------------+
// | + HumanA(name: string, weapon: Weapon&) |
// | + attack(): void                        |
// +----------------+

//         ▲
//         |
//         |  (Pointer in HumanB)
//         |
// +----------------+
// |    HumanB      |
// +----------------+
// | - name: string |
// | - weapon: Weapon* |
// +----------------+
// | + HumanB(name: string)           |
// | + setWeapon(w: Weapon&): void    |
// | + attack(): void                 |
// +----------------+
