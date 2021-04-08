/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:22:52 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/08 22:31:15 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_element	*vector_at(const t_vector *vector, int index)
{
	if ((t_size)index >= vector->size)
		return (NULL);
	return (&vector->array[index]);
}
