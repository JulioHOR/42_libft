/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_str_to_long_long.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:50:36 by juhenriq          #+#    #+#             */
/*   Updated: 2025/03/14 19:54:21 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex_get_char_nb(int c)
{
	char	*hex_characters;
	int		i;

	hex_characters = "abcdef";
	i = 0;
	while (hex_characters[i])
	{
		if (c == hex_characters[i] || c == (hex_characters[i] - 32))
			return (i + 10);
		i++;
	}
	return (-1);
}

static long long	int_pow(int nb, int exp)
{
	long long	nb_to_the_pwr;
	int			i;

	if (exp == 0)
		return (1);
	if (exp == 1)
		return (nb);
	nb_to_the_pwr = nb;
	i = 1;
	while (i < exp)
	{
		nb_to_the_pwr *= nb;
		i++;
	}
	return (nb_to_the_pwr);
}

int	hex_str_to_long_long(char *str, long long *nb)
{
	long long	new_nb;
	int			nb_to_add;
	int			i;
	int			j;

	if (!(str) || !(is_hex(str)))
		return (-1);
	new_nb = 0;
	i = ft_strlen(str) - 1;
	j = 0;
	while (i >= 0)
	{
		if (ft_isdigit(str[i]))
			nb_to_add = str[i] - '0';
		else
			nb_to_add = hex_get_char_nb(str[i]);
		if (nb_to_add == -1)
			return (-1);
		new_nb += nb_to_add * int_pow(16, j++);
		i--;
	}
	*nb = new_nb;
	return (0);
}
