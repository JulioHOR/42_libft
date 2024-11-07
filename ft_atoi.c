/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:39:51 by juhenriq          #+#    #+#             */
/*   Updated: 2024/11/07 16:53:32 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <limits.h>
// REMOVA ABAIXO
#include <stdio.h>

int	get_number_size_as_str(const char *nptr)
{
	int	i;

	i = 1;
	while (nptr[i] != '\0')
		i++;
	return (--i);
}

int	return_number(char *valid_chars)
{
	int	number;
	int	number_size_as_str;
	int	multiplier;
	int	i;

	number = 0;
	multiplier = 1;
	number_size_as_str = get_number_size_as_str(valid_chars);
	i = number_size_as_str;
	while (i > 0)
	{
		number += (valid_chars[i--] - '0') * multiplier;
		multiplier *= 10;
	}
	if (valid_chars[0] == '-')
	{
		if (number == 2147483647)
			return (-2147483648);
		return (number * -1);
	}
	return (number);
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
		((nptr[i] >= '0') && (nptr[i] <= '9')) && nptr[i] != '\0' && pos <= 11)
	{
		if (nptr[i] == '+' || nptr[i] == '-')
		{
			valid_chars[pos++] = nptr[i];
			number_must_start = 1;
		}
		if (((nptr[i] >= '0') && (nptr[i] <= '9')))
		{
			if (!(number_must_start))
				valid_chars[pos++] = '+';
			valid_chars[pos++] = nptr[i];
			number_must_start = 1;
		} else 
			if (!(number_must_start))
				break;
		i++;
	}
	valid_chars[pos] = '\0';
	nb_str_size = get_number_size_as_str(nptr);
	return (return_number(valid_chars));
}

int	main(void)
{
	const char	*nptr = "9999999999";
	
	ft_atoi(nptr);
	return (0);
}
