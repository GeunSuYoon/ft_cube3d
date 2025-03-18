/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:05:31 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/13 15:49:33 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*first_lst;

	first_lst = *lst;
	*lst = ft_lstlast(*lst);
	if (*lst == NULL)
		first_lst = new;
	else
		(*lst)->next = new;
	*lst = first_lst;
}
