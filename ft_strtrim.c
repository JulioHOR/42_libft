/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:41:38 by juhenriq          #+#    #+#             */
/*   Updated: 2024/11/08 17:40:16 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	it_matches(char char_to_match, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (char_to_match == set[i])
			break ;
		i++;
	}
	if (set[i])
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	start;
	int	ends;
	int	new_str_len;

	start = -1;
	ends = -1;
	new_str_len = 1;
	i = 0;
	while(s1[i])
	{
		// se for um caractere relevante e start for igual a -1;
		if (!(it_matches(s1[i], set)) && (start == -1))
			start = i;
		if (!(it_matches(s1[i], set)))
			new_str_len++;
		if (it_matches(s1[i], set) && start != -1)
			ends = i;
		i++;
	}
	if (ends == -1)
		ends = i;
	if (start == -1)
		return (((void *) 0));
	return (ft_substr(s1, start, new_str_len));
}

#include <stdio.h>
int	main(void)
{
	char *string = "lixo string lixo";
	char *set = "lixo ";

	printf("\n%s\n", ft_strtrim(string, set));
	return (0);
}
