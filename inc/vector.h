/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:46:38 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/08 23:36:47 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>
# include <libft.h>

typedef unsigned long		t_size;
typedef char				t_bool;
typedef struct s_element	t_element;
typedef t_element			t_elem;
typedef t_elem *			t_iterator;

enum e_bool
{
	false,
	true	
};

typedef enum e_type
{
	CHAR = sizeof(char),
	SHORT = sizeof(short),
	INT = sizeof(int),
	LONG = sizeof(long),
	LLONG = sizeof(long long),
	FLOAT = sizeof(float),
	DOUBLE = sizeof(double),
	LDOUBLE = sizeof(long double),
	POINTER = sizeof(void *)
}	t_type;

struct s_element
{
	void	*data;
	t_size	size;
};

typedef struct s_vector
{
	t_element	*array;
	t_iterator	begin;
	t_iterator	end;
	t_iterator	rbegin;
	t_iterator	rend;
	t_size		capacity;
	t_size		size;
	t_type		type;
	t_bool		empty;
}	t_vector;

void	vector_init(t_vector *vector,
			t_type size_type);
void	vector_clear(t_vector *vector);
void	*vector_failure(t_vector *vector);
int		vector_reserve(t_vector *vector,
			t_size new_capacity);
int		vector_push_back(t_vector *vector,
			void *data,
			t_size size);
void	vector_pop_back(t_vector *vector);
int		vector_insert(t_vector *vector,
			t_iterator pos,
			void *data,
			t_size size);
int		vector_insert_realloc(t_vector *vector,
			t_iterator pos,
			void *data,
			t_size size);
int		vector_erase(t_vector *vector,
			t_iterator pos);
int		vector_erase_range(t_vector *vector,
			t_iterator begin,
			t_iterator end);
int		vector_assign(t_vector *dst,
			t_vector *src);
int		vector_resize(t_vector *vector,
			t_size new_size);
int		vector_swap(t_vector *vector_a,
			t_vector *vector_b);
t_elem	*vector_at(const t_vector *vector,
			int index);
int		vector_set(t_vector *vector,
			int index,
			void *data,
			t_size size);
void	vector_iterator_update(t_vector *vector);

void	*value(int value);
void	*value_llong(long long value);
void	*value_long(long value);
void	*value_short(short value);
void	*value_char(char value);
void	*value_ldouble(long double value);
void	*value_double(double value);
void	*value_float(float value);

void	*_ft_calloc(t_size count, t_size size, t_bool nul_end_byte);
void	_ft_bzero(void *s, t_size size);
void	*_ft_memcpy(void *dst, const void *src, t_size n);
void	*_destroy(void **data);

#endif
