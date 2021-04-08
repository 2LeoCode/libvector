/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:46:59 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/08 23:34:05 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

void	vector_iterator_update(t_vector *vector)
{
	vector->begin = vector->array;
	vector->end = vector->begin + vector->size;
	vector->rbegin = vector->end - 1;
	vector->rend = vector->begin - 1;
}
