/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:35:55 by juhenriq          #+#    #+#             */
/*   Updated: 2024/11/20 21:11:18 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr_to_copied_lst;
	t_list	*iter_copied_lst_ptr;
	t_list	*iter_lst_ptr;

	if (!(lst))
		return (NULL);
	ptr_to_copied_lst = NULL;
	iter_lst_ptr = lst;
	while (iter_lst_ptr)
	{
		iter_copied_lst_ptr = ft_lstnew(f(iter_lst_ptr->content));
		if (!(iter_copied_lst_ptr))
		{
			if (!(ptr_to_copied_lst))
				return (NULL);
			ft_lstclear(&ptr_to_copied_lst, del);
		}
		if (!(ptr_to_copied_lst) && (iter_copied_lst_ptr))
			ptr_to_copied_lst = iter_copied_lst_ptr;
		iter_lst_ptr = iter_lst_ptr->next;
	}
	return (ptr_to_copied_lst);
}

#include <stdio.h>

void	main_prints_contents(void *ptr_to_content)
{
	printf("\n- %s", (char *) ptr_to_content);
}

void	*main_second_prints_contents(void *ptr_to_content)
{
	printf("\n%s", (char *) ptr_to_content);
	return (NULL);
}

void	something_to_free(void *ptr_to_free)
{
	free(ptr_to_free);
}

void	do_nothing(void *ptr_to_free)
{
	(void) ptr_to_free;
}

void	*do_nothing_and_returns_nothing(void *ptr_to_free)
{
	(void) ptr_to_free;
	return (NULL);
}

int	main(void)
{
	t_list	*original_lst;
	t_list	*iter_original_lst_ptr;
	t_list	*ptr_to_copied_lst;
	char	*strings_to_create[] = {"abacate", "beterraba", "cenoura", NULL};
	int		i;

	printf("\n\n--- Iniciando ---\n\n");

	// initializes three nodes in a list
	original_lst = NULL;
	i = -1;
	while (strings_to_create[++i])
	{
		iter_original_lst_ptr = ft_lstnew(ft_strdup(strings_to_create[i]));
		if (!(iter_original_lst_ptr))
		{
			// we failed to malloc even the first node, so we enter this if
			if (!(original_lst))
				return (1);
			ft_lstclear(&original_lst, &do_nothing);
			return (1);
		}
		// if the pointer to the original list is still a NULL pointer, and we
		// have already been capable of creating at least one new node, then we
		// must point iter_original_lst_ptr to this newly created node.
		if (!(original_lst) && (iter_original_lst_ptr))
			original_lst = iter_original_lst_ptr;
		if (original_lst != iter_original_lst_ptr)
			ft_lstadd_back(&original_lst, iter_original_lst_ptr);
	}

	// prints the original nodes content's
	printf("Conteúdo dos nodes originais (%d): \n", ft_lstsize(original_lst));
	ft_lstiter(original_lst, &main_prints_contents);

	// creates the new nodes
	ptr_to_copied_lst = ft_lstmap(original_lst, \
		&do_nothing_and_returns_nothing, &do_nothing);

	// prints the contents of the recently created nodes
	printf("\n\nConteúdo dos nodes copiados (%d): \n", \
		ft_lstsize(ptr_to_copied_lst));
	ft_lstiter(ptr_to_copied_lst, &main_prints_contents);

	// frees the lists
	ft_lstclear(&original_lst, &do_nothing);
	ft_lstclear(&ptr_to_copied_lst, &do_nothing);

	printf("\n\n--- Encerrando ---\n\n");
	return (0);
}