/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:25:22 by juhenriq          #+#    #+#             */
/*   Updated: 2025/06/02 22:31:03 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem_addr;

	if ((nmemb == 0) && (size == 0))
		return (gc_malloc(0));
	if (((nmemb != 0) && (size > (((-1) * size) / nmemb))))
		return ((void *) 0);
	mem_addr = gc_malloc(size * nmemb);
	if (!(mem_addr))
		return ((void *) 0);
	ft_memset(mem_addr, '\0', (size * nmemb));
	return (mem_addr);
}
