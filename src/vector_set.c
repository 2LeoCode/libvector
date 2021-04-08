/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:28:35 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/08 23:25:55 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <stdio.h>
int	vector_set(t_vector *vector, int index, void *data, t_size size)
{
	t_size	element_size;

	if ((t_size)index >= vector->size)
		return (1);
	element_size = size * vector->type;
	free(vector->array[index].data);
	vector->array[index].size = size;
	vector->array[index].data = _ft_calloc(size, vector->type, false);
	if (!vector->array[index].data)
		return ((int)vector_failure(vector) - 1);
	_ft_memcpy(vector->array[index].data, data, element_size);
	return (0);
}
