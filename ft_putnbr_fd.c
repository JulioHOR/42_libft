/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:27:22 by juhenriq          #+#    #+#             */
/*   Updated: 2024/11/12 16:53:01 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*result;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	result = ft_itoa(n);
	if (!(result))
		return ;
	write(fd, result, ft_strlen(result));
	free(result);
}
