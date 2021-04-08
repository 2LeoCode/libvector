/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:05:16 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/08 23:38:12 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

int	vector_push_back(t_vector *vector, void *data, t_size size)
{
	t_size	element_size;

	if (vector->capacity <= vector->size)
		return (vector_insert_realloc(vector, vector->end, data, size));
	vector->end->size = size;
	vector->end->data = _ft_calloc(size, vector->type, (vector->type == CHAR));
	if (!vector->end->data)
		return ((int)vector_failure(vector) - 1);
	element_size = vector->type * size;
	_ft_memcpy(vector->end->data, data, element_size);
	vector->end++;
	vector->rbegin++;
	vector->size++;
	vector->empty = false;
	return (0);
}
