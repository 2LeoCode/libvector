/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:45:38 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/08 22:40:04 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

int	vector_swap(t_vector *a, t_vector *b)
{
	t_vector	tmp;
	int			ret;

	ret = 0;
	if (vector_assign(&tmp, a))
		return ((int)vector_failure(b) - 1);
	if (vector_assign(a, b))
		return ((int)vector_failure(&tmp) - 1);
	if (vector_assign(b, &tmp))
		return ((int)vector_failure(a) - 1);
	vector_clear(&tmp);
	return (0);
}
