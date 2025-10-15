/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:27:12 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/13 18:15:21 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

// forward declaration is enough here because we only return pointers
class AForm;

class Intern {
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    // returns a pointer to a newly allocated AForm (caller must delete)
    AForm* makeForm(const std::string &formName, const std::string &target) const;
};

#endif // INTERN_HPP

