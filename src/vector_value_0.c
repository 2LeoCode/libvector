/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_value_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:44:15 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/08 23:32:34 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

void	*value_llong(long long value)
{
	return ((void *)(long long []){value});
}

void	*value_long(long value)
{
	return ((void *)(long []){value});
}

void	*value(int value)
{
	return ((void *)(int []){value});
}

void	*value_short(short value)
{
	return ((void *)(short []){value});
}

void	*value_char(char value)
{
	return ((void *)(char []){value});
}
