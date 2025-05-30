/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:04:12 by jhualves          #+#    #+#             */
/*   Updated: 2025/05/29 23:48:26 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_gc_malloc(t_gc_malloc *gc_malloc)
{
	int	i;

	if (!gc_malloc)
		gc_malloc = _get_gc_malloc();
	if (!gc_malloc->array)
		return ;
	i = 0;
	while (i < gc_malloc->ptr_spaces)
	{
		if (gc_malloc->array[i] != NULL)
		{
			free(gc_malloc->array[i]);
			gc_malloc->array[i] = NULL;
		}
		i++;
	}
	free(gc_malloc->array);
	gc_malloc->array = NULL;
}

t_gc_malloc	*_get_gc_malloc(void)
{
	static t_gc_malloc	gc_malloc;

	if (gc_malloc.ptr_spaces == 0)
	{
		_init_gc_malloc(&gc_malloc);
		if (!gc_malloc.array)
			return (NULL);
	}
	return (&gc_malloc);
}

void	gc_free(void *ptr)
{
	t_gc_malloc	*gc_malloc;
	int			i;

	if (!ptr)
		return ;
	gc_malloc = _get_gc_malloc();
	i = 0;
	while (i < gc_malloc->ptr_spaces)
	{
		if (gc_malloc->array[i] == ptr)
		{
			free(gc_malloc->array[i]);
			gc_malloc->array[i] = NULL;
			gc_malloc->ptr_used_spaces--;
			break ;
		}
		i++;
	}
}

void	*gc_malloc(size_t size)
{
	t_gc_malloc	*gc_malloc;
	void		*ptr;

	if (size == 0)
		return (NULL);
	gc_malloc = _get_gc_malloc();
	if (!gc_malloc)
	{
		ft_printf_error("Failed to malloc managed malloc.\n");
		exit(1);
	}
	ptr = (void *) malloc(size);
	if (!ptr)
		free_gc_malloc(gc_malloc);
	if (gc_malloc->ptr_spaces == gc_malloc->ptr_used_spaces)
		_double_gc_malloc(gc_malloc);
	_gc_malloc_insert_ptr(gc_malloc, ptr);
	return (ptr);
}
