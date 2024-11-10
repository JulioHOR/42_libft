/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:04:02 by juhenriq          #+#    #+#             */
/*   Updated: 2024/11/10 01:32:28 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

// free seja o q deus quiser
void	fill_pointer_array(char **ptr_arr, char const *s, char c)
{
	int	ptr_arr_pos;
	int	start;
	int	i;

	ptr_arr_pos = 0;
	start = -1;
	i = -1;
	while(s[++i])
	{
		if ((start == -1) && (s[i] != c))
			start = i;
		if ((start != -1) && (s[i + 1] == '\0'))
		{
			if (s[i] == c)
			ptr_arr[ptr_arr_pos++] = ft_substr(s, start, ((i) - start));
			else
				ptr_arr[ptr_arr_pos++] = ft_substr(s, start, ((i + 1) - start));
			start = -1;
		}
		if ((start != -1) && (s[i] == c))
		{
			ptr_arr[ptr_arr_pos++] = ft_substr(s, start, (i - start));
			start = -1;
		}
	}
}

unsigned int	determine_pointer_array_len(char const *s, char c)
{
	int				i;
	int				start;
	unsigned int	pointer_array_len;

	start = -1;
	pointer_array_len = 1;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c))
			start = -1;
		if ((s[i] != c) && (start == -1))
		{
			pointer_array_len++;
			start = i;
		}
		i++;
	}
	return (pointer_array_len);
}

char	**ft_split(char const *s, char c)
{
	char			**pointer_array;
	unsigned int	pointer_array_len;

	pointer_array_len = determine_pointer_array_len(s, c);
	pointer_array = (char **) malloc(pointer_array_len * sizeof(char *));
	if (!pointer_array)
		return ((void *) 0);
	pointer_array[pointer_array_len - 1] = ((void *) 0);
	fill_pointer_array(pointer_array, s, c);
	// printf("\napenas para debug:\n- pointer_array_len foi: %d", pointer_array_len);
	return (pointer_array);
}

// int	main(void)
// {
// 	// quantidade de 'c's = 8
// 	char	*string = "split  ||this|for|me|||||!|";
// 	char	delimiter = '|';
// 	int		i;

// 	char **pointer_array = ft_split(string, delimiter);
// 	write(1, "\n", 1);
// 	i = 0;
// 	while (*pointer_array)
// 	{
// 		write(1, "\n", 1);
// 		i = 0;
// 		while((*pointer_array)[i])
// 		{
// 			write(1, &((*pointer_array)[i]), 1);
// 			i++;
// 		}
// 		pointer_array++;
// 	}
// 	write(1, "fim\n\n---\n\n", 14);
// 	return (0);
// }
