/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:16:52 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/13 13:20:09 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret_add;
	size_t	cal_size;

	cal_size = count * size;
	if (count && size != cal_size / count)
		return (NULL);
	ret_add = (void *)malloc(cal_size);
	if (ret_add == NULL)
		return (NULL);
	ft_memset(ret_add, 0, cal_size);
	return (ret_add);
}
