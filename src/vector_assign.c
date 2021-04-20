/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_assign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:40:35 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/08 22:27:50 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

int	vector_assign(t_vector *dst, t_vector *src)
{
	t_iterator	d_it;
	t_iterator	s_it;

	vector_clear(dst);
	dst->array = ft_calloc(src->capacity, sizeof(t_element));
	if (!dst->array)
		return ((int)vector_failure(src) - 1);
	dst->type = src->type;
	dst->capacity = src->capacity;
	dst->size = src->size;
	dst->empty = src->empty;
	vector_iterator_update(dst);
	d_it = dst->begin;
	s_it = src->rend;
	while (++s_it < src->end)
	{
		d_it->size = s_it->size;
		d_it->data = ft_calloc(s_it->size * src->type + (src->type == CHAR),
			sizeof(char));
		if (!d_it->data)
			return ((int)vector_failure(dst) + (int)vector_failure(src) - 1);
		ft_memcpy(d_it->data, s_it->data, s_it->size * src->type);
		d_it++;
	}
	return (0);
}
