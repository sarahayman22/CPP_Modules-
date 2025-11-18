/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:54:30 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/18 17:15:26 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <cstddef>
template <typename T, typename Func>
void iter(T* array, const size_t length, Func f)
{
	for (size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}
#endif