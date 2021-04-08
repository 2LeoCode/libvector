/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:59:57 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/08 23:46:29 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

void	vector_init(t_vector *vector, t_type size_type)
{
	if (vector->capacity)
		vector_clear(vector);
	vector->type = size_type;
	vector->array = NULL;
	vector->begin = NULL;
	vector->end = NULL;
	vector->rbegin = NULL;
	vector->rend = NULL;
	vector->size = 0;
	vector->capacity = 0;
	vector->empty = true;
}
