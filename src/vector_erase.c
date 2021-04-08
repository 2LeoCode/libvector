/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_erase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:56:35 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/09 00:01:38 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

int	vector_erase(t_vector *vector, t_iterator pos)
{
	pos->size = 0;
	free(pos->data);
	(pos--)->data = NULL;
	while (++pos < vector->rbegin)
	{
		pos->data = (pos + 1)->data;
		pos->size = (pos + 1)->size;
	}
	vector->end = pos;
	vector->rbegin--;
	vector->size--;
	return (1);
}

int	vector_erase_range(t_vector *vector, t_iterator begin, t_iterator end)
{
	t_iterator	it;
	int			rm_count;

	rm_count = 0;
	it = begin - 1;
	while ((++it < vector->end) && (it < end))
	{
		free(it->data);
		it->data = NULL;
		it->size = 0;
		rm_count++;
	}
	while (it < vector->end)
	{
		begin->data = it->data;
		(begin++)->size = (it++)->size;
	}
	vector->size -= rm_count;
	vector->empty = !vector->size;
	vector->end -= rm_count;
	vector->rbegin = vector->end - 1;
	return (rm_count);
}
