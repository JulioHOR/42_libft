/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:40:02 by juhenriq          #+#    #+#             */
/*   Updated: 2024/11/18 19:47:15 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!(new))
		return ;
	new->next = *lst;
	*lst = new;
}

int	main(void)
{
	t_list	*head;
	t_list	*new;
	t_list	nossa_lista;

	ft_lstadd_front(&head, new);
	return (0);
}
