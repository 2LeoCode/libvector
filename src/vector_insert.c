/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:12:51 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/08 23:15:49 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

static int	vector_insert_failure(t_element **data)
{
	free(*data);
	*data = NULL;
	return (-1);
}

static void	insert_update_data(t_vector *vector, t_element *new_array)
{
	free(vector->array);
	vector->array = new_array;
	vector->size++;
	vector->capacity++;
	vector_iterator_update(vector);
}

int	vector_insert_realloc(t_vector *vector,
		t_iterator pos,
		void *data,
		t_size size)
{
	t_element	*new_array;
	t_size		old_size;
	t_size		pos_index;
	t_size		element_size;
	t_iterator	it;

	new_array = ft_calloc(vector->capacity + 1, sizeof(t_element));
	if (!new_array)
		return ((int)vector_failure(vector) - 1);
	old_size = sizeof(void *) * vector->capacity;
	pos_index = ((t_size)pos - (t_size)vector->begin) / sizeof(t_element);
	ft_memcpy((void *)new_array, (void *)vector->array,
		pos_index * sizeof(t_element));
	it = new_array + pos_index;
	it->size = size;
	it->data = ft_calloc(size * vector->type + (vector->type == CHAR),
			sizeof(char));
	if (!it->data)
		return (vector_insert_failure(&new_array)
			+ (int)vector_failure(vector));
	element_size = vector->type * size;
	ft_memcpy(it->data, data, element_size);
	ft_memcpy(it + 1, pos, (t_size)vector->end - (t_size)pos);
	insert_update_data(vector, new_array);
	return (0);
}

int	vector_insert(t_vector *vector,
		t_iterator pos,
		void *data,
		t_size size)
{
	t_iterator	it;
	t_size		element_size;

	if (vector->capacity <= vector->size)
		return (vector_insert_realloc(vector, pos, data, size));
	it = ++vector->end;
	while (--it > pos)
	{
		it->data = (it - 1)->data;
		it->size = (it - 1)->size;
	}
	pos->size = size;
	pos->data = ft_calloc(size * vector->type + (vector->type == CHAR),
			sizeof(char));
	if (!pos->data)
		return ((int)vector_failure(vector) - 1);
	element_size = vector->type * size;
	ft_memcpy(pos->data, data, element_size);
	vector->rbegin++;
	vector->size++;
	vector->empty = false;
	return (0);
}
