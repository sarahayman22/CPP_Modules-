/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:25:43 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/25 17:17:58 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
/*easyfind is a template function that tries to find a number inside any container (like vector, list, deque, etc.).

If it finds the number → it returns an iterator pointing to it.
If it does NOT find the number → it throws an error.*/
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    return it;
}

#endif
/*
typename T::iterator
This is the return type: the function returns an iterator type from the container T.
The typename keyword is required here because T::iterator is a dependent name (it depends on the template parameter T).
The compiler must be told that T::iterator is a type. Without typename the code will not compile (you’ll get a parse error).
This means the function returns the iterator to the found element, 
so the caller can dereference it (*it) to get the value or use it to modify the element.*/

