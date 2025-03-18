/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:17:42 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/15 10:37:55 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				cnt;
	unsigned char		*dst_char;
	unsigned const char	*src_char;

	if (dst == src)
		return (dst);
	cnt = 0;
	dst_char = (unsigned char *)dst;
	src_char = (unsigned const char *)src;
	if (dst_char < src_char)
	{
		while (cnt < len)
		{
			dst_char[cnt] = src_char[cnt];
			cnt++;
		}
		return (dst);
	}
	while (cnt < len)
	{
		dst_char[len - cnt - 1] = src_char[len - cnt - 1];
		cnt++;
	}
	return (dst);
}
