/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:08:12 by juhenriq          #+#    #+#             */
/*   Updated: 2025/04/01 03:07:39 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	only_digits(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (i == 1 && str[1] == '\0')
		return (0);
	while (str[i])
		if (!(ft_isdigit(str[i++])))
			return (0);
	return (1);
}

static int	has_int_len(char *str, int *str_len, int *min_len, int *max_len)
{
	const char	*int_min = "-2147483648";
	const char	*int_max = "2147483647";

	*min_len = ft_strlen(int_min);
	*max_len = ft_strlen(int_max);
	*str_len = ft_strlen(str);
	if (*str_len <= *min_len || *str_len <= *max_len)
		return (1);
	return (0);
}

static int	final_decision(char *str, const char *int_min_or_max, int str_len)
{
	if (ft_strncmp(str, int_min_or_max, str_len) <= 0)
		return (1);
	else
		return (0);
}

int	ft_is_int(char *str)
{
	const char	*int_min = "-2147483648";
	const char	*int_max = "2147483647";
	int			min_len;
	int			max_len;
	int			str_len;

	if (str == NULL)
		return (0);
	if (str[0] == '\0')
		return (0);
	if (!(has_int_len(str, &str_len, &min_len, &max_len)))
		return (0);
	if (!(only_digits(str)))
		return (0);
	if (str_len < min_len && str_len < max_len)
		return (1);
	if (str_len == min_len)
		return (final_decision(str, int_min, str_len));
	if (str_len == max_len)
		return (final_decision(str, int_max, str_len));
	return (0);
}
