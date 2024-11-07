/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:39:51 by juhenriq          #+#    #+#             */
/*   Updated: 2024/11/06 20:56:38 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
// REMOVA ABAIXO
#include <stdio.h>

int	return_number()
{
	
}

int	get_number_size_as_str(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] != '\0')
		i++;
	return (i);
}

// 2.147.483.647 - são 10 caracteres
int	ft_atoi(const char *nptr)
{
	int		nb_str_size;
	int		i;
	int		pos;
	int		converted_number;
	char	valid_chars[12];
	int		number_must_start;
	
	number_must_start = 0;
	i = 0;
	pos = 0;
	while ((((nptr[i] >= '\t') && (nptr[i] <= '\r')) || (nptr[i] == ' ')) || \
		((nptr[i] >= '+') && (nptr[i] <= '-')) || \
		((nptr[i] >= '0') && (nptr[i] <= '9')) && nptr[i] != '\0')
	{
		if (nptr[i] == '+' || nptr[i] == '-')
		{
			valid_chars[pos++] = nptr[i];
			number_must_start = 1;
		}
		if (((nptr[i] >= '0') && (nptr[i] <= '9')) || (number_must_start))
		{
			valid_chars[pos++] = nptr[i];
			number_must_start = 1;
		} else 
		{
			
		}
		i++;
	}
	nb_str_size = get_number_size_as_str(nptr);
	if (nb_str_size > 10)
		return (0);
	while (nptr[i] )
	return (0);
}

int	main(void)
{
	const char	*nptr = "2147483647";
	
	ft_atoi(nptr);
	return (0);
}