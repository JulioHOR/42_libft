/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:13:18 by juhenriq          #+#    #+#             */
/*   Updated: 2024/11/11 20:01:47 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		string_len;
	char	*malloc_return;

	string_len = ft_strlen(s);
	malloc_return = (char *) malloc(string_len + 1);
	if (!malloc_return)
		return (NULL);
	i = 0;
	while (i < (string_len + 1))
	{
		malloc_return[i] = s[i];
		i++;
	}
	return (malloc_return);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*string = "string básica";
// 	char	*recibo;

// 	recibo = ft_strdup(string);
// 	printf("%s", recibo);
// 	free(recibo);
// 	return (0);
// }