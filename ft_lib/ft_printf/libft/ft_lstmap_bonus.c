/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:06:59 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/13 16:01:09 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	*free_lst(t_list *ret_lst, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret_lst;
	t_list	*nxt_lst;
	void	*nxt_mal;

	if (lst == NULL)
		return (NULL);
	ret_lst = NULL;
	while (lst != NULL)
	{
		nxt_mal = f(lst->content);
		if (nxt_mal == NULL)
			return (free_lst(ret_lst, del));
		nxt_lst = ft_lstnew(nxt_mal);
		if (nxt_lst == NULL)
		{
			del(nxt_mal);
			return (free_lst(ret_lst, del));
		}
		ft_lstadd_back(&ret_lst, nxt_lst);
		lst = lst->next;
	}
	return (ret_lst);
}

void	*free_lst(t_list *ret_lst, void (*del)(void *))
{
	if (ret_lst != NULL)
		ft_lstclear(&ret_lst, del);
	return (NULL);
}
