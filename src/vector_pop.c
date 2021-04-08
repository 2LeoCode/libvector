/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:05:17 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/07 22:45:05 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

void	vector_pop_back(t_vector *vector)
{
	vector->end--;
	vector->rbegin--;
	if (!--vector->size)
		vector->empty = true;
	free(vector->end->data);
	vector->end->data = NULL;
	vector->end->size = 0;
}
