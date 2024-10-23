/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:10:14 by juhenriq          #+#    #+#             */
/*   Updated: 2024/10/22 20:43:02 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_substring;
	size_t	i;

	new_substring = (char *) malloc((len + 1) * sizeof(char));
	i = 0;
	while ((i < len) && (s[start] != '\0'))
	{
		new_substring[i] = s[start];
		start++;
		i++;
	}
	new_substring[i] = '\0';
	return (new_substring);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*string_original = "malloc protection !";
// 	char	*answer;
// 	// answer = ft_substr(string_original, 6, 4);
// 	answer = ft_substr(string_original, 0, 5);
// 	printf("%s", answer);
// 	return (0);
// }