/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:54:30 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/16 17:21:47 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <cstddef>

/*
 * @brief Applies a function to every element of an array.
 *
 * @tparam T The type of the elements in the array. This can be const or non-const.
 * @tparam Func The type of the function/callable to apply.
 *
 * @param array Pointer to the first element of the array.
 * @param length The number of elements in the array.
 * @param f The function to apply to each element.
 */
template <typename T, typename Func>
void iter(T* array, const size_t length, Func f)
{
	for (size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}
#endif