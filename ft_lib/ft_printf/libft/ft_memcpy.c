/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:17:37 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/15 10:37:50 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				cnt;
	unsigned char		*dst_char;
	unsigned const char	*src_char;

	if (dst == src)
		return (dst);
	cnt = 0;
	dst_char = (unsigned char *)dst;
	src_char = (unsigned const char *)src;
	while (cnt < n)
	{
		dst_char[cnt] = src_char[cnt];
		cnt++;
	}
	return (dst);
}
