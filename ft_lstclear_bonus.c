/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:36:31 by juhenriq          #+#    #+#             */
/*   Updated: 2025/06/02 23:44:14 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!(*lst) || !(del))
		return ;
	ft_lstclear(&((*lst)->next), del);
	if ((*lst)->content)
		del((*lst)->content);
	gc_free(*lst);
	*lst = NULL;
}
