/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:18:14 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/08 22:39:29 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

int	vector_resize(t_vector *vector, t_size new_size)
{
	t_iterator	it;

	if ((new_size > vector->capacity) && vector_reserve(vector, new_size))
		return (-1);
	it = &vector->array[new_size - 2];
	while (++it < vector->end)
	{
		free(it->data);
		it->data = NULL;
		it->size = 0;
	}
	while (it > vector->rbegin)
	{
		it->data = ft_calloc(vector->type * (vector->type == CHAR),
			sizeof(char));
		if (!it->data)
			return ((int)vector_failure(vector));
		it->size = 1;
		it--;
	}
	vector->size = new_size;
	vector_iterator_update(vector);
	return (0);
}
