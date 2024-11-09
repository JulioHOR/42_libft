/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:04:02 by juhenriq          #+#    #+#             */
/*   Updated: 2024/11/09 01:53:23 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

// continue daqui
void	fill_pointer_array(char **pointer_array, char const *s, char c)
{
	int	pointer_array_pos;
	int	start;
	int	i;

	pointer_array_pos = 0;
	start = -1;
	i = 0;
	while(s[i])
	{
		if ((start == -1) && (s[i] != c))
			start = i;
		if (s[i] == c)
		{
			if (start != -1)
			{
				pointer_array[pointer_array_pos++] = \
					ft_substr(s, start, (i + 1));
				start = -1;
			}
			if ((start == -1) && (s[i + 1] == '\0'))
				pointer_array[pointer_array_pos++] = calloc(1, 1);
		}
		i++;
	}
}

unsigned int	determine_pointer_array_len(char const *s, char c)
{
	int				i;
	unsigned int	pointer_array_len;
	
	pointer_array_len = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c))
			pointer_array_len++;
		if ((s[i] == c) && (i == 0))
			pointer_array_len++;
		if ((s[i] == c) && (s[i + 1] == '\0'))
			pointer_array_len++;
		i++;
	}
	return (++pointer_array_len);
}

char	**ft_split(char const *s, char c)
{
	int				i;
	char			**pointer_array;
	unsigned int	pointer_array_len;

	pointer_array_len = determine_pointer_array_len(s, c);
	pointer_array = (char **) malloc(pointer_array_len * sizeof(char *));
	pointer_array[pointer_array_len - 1] = ((void *) 0);
	fill_pointer_array(pointer_array, s, c);
	printf("\napenas para debug:\n- pointer_array_len foi: %d", pointer_array_len);
	return (pointer_array);
}

int	main(void)
{
	// quantidade de 'c's = 8
	char	*string = "cccabd";
	char	delimiter = 'c';

	char **pointer_array = ft_split(string, delimiter);
	write(1, "\n", 1);
	while(pointer_array)
	{
		printf("\n%s", *pointer_array);
		pointer_array++;
	}
	write(1, "\n", 1);
	return (0);
}
