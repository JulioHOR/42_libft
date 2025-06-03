/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 06:33:22 by juhenriq          #+#    #+#             */
/*   Updated: 2025/06/02 22:31:03 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	to_string_char(t_fmt_spec *tfmt_spec, char c)
{
	char	*str;

	str = (char *) gc_malloc(sizeof(c) + 1);
	if (!(str))
	{
		tfmt_spec->out_cont = NULL;
		return ;
	}
	str[0] = c;
	str[1] = '\0';
	tfmt_spec->out_cont = str;
}
