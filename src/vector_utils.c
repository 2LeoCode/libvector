/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:57:36 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/08 23:42:34 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

void	_ft_bzero(void *s, t_size size)
{
	long	*qword;
	int		*dword;
	short	*word;
	char	*byte;

	qword = (long *)s;
	while (size > sizeof(long))
	{
		*(qword++) = 0;
		size -= sizeof(long);
	}
	dword = (int *)qword;
	while (size > sizeof(int))
	{
		*(dword++) = 0;
		size -= sizeof(int);
	}
	word = (short *)dword;
	while (size > sizeof(short))
	{
		*(word++) = 0;
		size -= sizeof(short);
	}
	byte = (char *)word;
	while (size--)
		*(byte++) = 0;
}

static void	*_ft_memcpy_bis(void *dst,
				const void *src,
				t_size n,
				void *begin)
{
	short	*d_word;
	short	*s_word;
	char	*d_byte;
	char	*s_byte;

	d_word = (short *)dst;
	s_word = (short *)src;
	while (n > sizeof(short))
	{
		*(d_word++) = *(s_word++);
		n -= sizeof(short);
	}
	d_byte = (char *)d_word;
	s_byte = (char *)s_word;
	while (n--)
		*(d_byte++) = *(s_byte++);
	return (begin);
}

void	*_ft_memcpy(void *dst, const void *src, t_size n)
{
	long	*d_qword;
	long	*s_qword;
	int		*d_dword;
	int		*s_dword;

	d_qword = (long *)dst;
	s_qword = (long *)src;
	while (n > sizeof(long))
	{
		*(d_qword++) = *(s_qword++);
		n -= sizeof(long);
	}
	d_dword = (int *)d_qword;
	s_dword = (int *)s_qword;
	while (n > sizeof(int))
	{
		*(d_dword++) = *(s_dword++);
		n -= sizeof(int);
	}
	return (_ft_memcpy_bis((void *)d_dword, (void *)s_dword, n, dst));
}

void	*_ft_calloc(t_size count, t_size size, t_bool nul_end_byte)
{
	char	*data;
	t_size	element_size;

	element_size = count * size + nul_end_byte;
	data = (char*)malloc(element_size);
	if (data) 
		_ft_bzero(data, element_size);
	return (data);
}

void	*_destroy(void **data)
{
	free(*data);
	*data = NULL;
	return (NULL);
}
