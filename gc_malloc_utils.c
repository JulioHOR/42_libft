/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:04:12 by jhualves          #+#    #+#             */
/*   Updated: 2025/06/08 04:00:29 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	_init_gc_malloc(t_gc_malloc	*gc_malloc)
{
	gc_malloc->ptr_spaces = 1;
	gc_malloc->ptr_used_spaces = 0;
	gc_malloc->array = (void **)
		malloc(gc_malloc->ptr_spaces * sizeof(void *));
	gc_malloc->array[gc_malloc->ptr_spaces - 1] = NULL;
}

void	_double_gc_malloc(t_gc_malloc *gc_malloc)
{
	int		doubled_len;
	void	**new_array;
	int		i;

	if (gc_malloc->ptr_spaces <= 0)
		return ;
	doubled_len = gc_malloc->ptr_spaces * 2;
	new_array = (void **) malloc(doubled_len * sizeof(void *));
	if (!new_array)
	{
		ft_printf("Failed to double the managed malloc size .\n");
		free_gc_malloc(gc_malloc, 0);
		exit(1);
	}
	ft_memcpy(new_array, gc_malloc->array,
		gc_malloc->ptr_spaces * sizeof(void *));
	i = gc_malloc->ptr_spaces;
	while (i < doubled_len)
		new_array[i++] = NULL;
	free(gc_malloc->array);
	gc_malloc->array = new_array;
	gc_malloc->ptr_spaces = doubled_len;
}

void	_gc_malloc_insert_ptr(t_gc_malloc *gc_malloc, void *ptr)
{
	int	i;

	if (gc_malloc == NULL || gc_malloc->array == NULL)
		return ;
	i = 0;
	while (i < gc_malloc->ptr_spaces)
	{
		if (gc_malloc->array[i] == NULL)
		{
			gc_malloc->array[i] = ptr;
			gc_malloc->ptr_used_spaces++;
			break ;
		}
		i++;
	}
}
