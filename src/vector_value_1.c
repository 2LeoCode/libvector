/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_value_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 23:31:27 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/08 23:36:51 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

void	*value_ldouble(long double value)
{
	return ((void *)(long double[]){value});
}

void	*value_double(double value)
{
	return ((void *)(double[]){value});
}

void	*value_float(float value)
{
	return ((void *)(float[]){value});
}
