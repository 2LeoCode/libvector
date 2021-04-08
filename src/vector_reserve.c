/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:35:52 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/08 22:20:34 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

int	vector_reserve(t_vector *vector, t_size new_capacity)
{
	t_element	*new_array;
	t_size		old_size;

	if (new_capacity <= vector->capacity)
		return (0);
	new_array = _ft_calloc(new_capacity, sizeof(t_element), false);
	if (!new_array)
		return ((int)vector_failure(vector) - 1);
	old_size = sizeof(t_element) * vector->capacity;
	_ft_memcpy((void *)new_array, (void *)vector->array, old_size);
	free(vector->array);
	vector->array = new_array;
	vector->capacity = new_capacity;
	vector_iterator_update(vector);
	return (0);
}
