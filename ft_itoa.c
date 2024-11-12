/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:26:31 by juhenriq          #+#    #+#             */
/*   Updated: 2024/11/12 16:04:53 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	determine_n_len(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

void	fill_arr(char *array, int array_pos, int n, int is_negative)
{
	array[array_pos + 1] = '\0';
	if (is_negative)
		array[0] = '-';
	while (array_pos >= is_negative)
	{
		array[array_pos--] = ((n % 10) + '0');
		n = (n / 10);
	}
}

char	*ft_itoa(int n)
{
	int		n_len;
	int		is_negative;
	int		that_number;
	char	*array;

	n_len = determine_n_len(n);
	is_negative = (n < 0);
	that_number = 0;
	if (is_negative)
	{
		if (n == -2147483648)
		{
			that_number = 1;
			n = 2147483647;
		}
		else
			n *= -1;
	}
	array = malloc(((n_len + is_negative) + 1) * sizeof(char));
	if (!(array))
		return (NULL);
	fill_arr(array, ((n_len + is_negative) - 1), n, is_negative);
	if (that_number)
		array[(n_len + is_negative - 1)] = '8';
	return (array);
}
