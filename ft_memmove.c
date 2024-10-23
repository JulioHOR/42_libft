/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:46:29 by juhenriq          #+#    #+#             */
/*   Updated: 2024/10/23 20:43:22 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src == 0 && dest == 0)
		return (dest);
	if (dest > src)
	{
		i = n - 1;
		while (i < n)
		{
			((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char dst1[240];
// 	char dst2[240];
// 	char *data = "vamos simplificar essa string";
// 	int size = 240 - 15;

// 	memset(dst1, 'A', sizeof(dst1));
// 	memset(dst2, 'A', sizeof(dst2));
// 	memcpy(dst1, data, strlen(data));
// 	memcpy(dst2, data, strlen(data));
// 	memmove(dst1, dst1 + 3, size);
// 	ft_memmove(dst2, dst2 + 3, size);
// 	if (!memcmp(dst1, dst2, size))
// 		printf("PASSOU!");
// 	else
// 	{
// 		printf("tem algo errado\n\n");
// 		printf("dst1 é: %s\n\n", dst1);
// 		printf("dst2 é: %s\n\n", dst2);
// 	}
// 	return (0);
// }