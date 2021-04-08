/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:57:46 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/08 23:46:06 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

void	vector_clear(t_vector *vector)
{
	t_iterator	it;

	it = vector->begin - 1;
	while (++it < vector->end)
	{
		free(it->data);
		it->data = NULL;
		it->size = 0;
	}
	free(vector->array);
	vector->array = NULL;
	vector->begin = NULL;
	vector->end = NULL;
	vector->rbegin = NULL;
	vector->rend = NULL;
	vector->capacity = 0;
	vector->size = 0;
	vector->type = 0;
	vector->empty = false;
}
