/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:18:19 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/15 10:38:39 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	cpy_cnt;

	src_len = ft_strlen(src);
	cpy_cnt = 0;
	if (dstsize != 0)
	{
		while (cpy_cnt < src_len && cpy_cnt < dstsize - 1)
		{
			dst[cpy_cnt] = src[cpy_cnt];
			cpy_cnt++;
		}
		dst[cpy_cnt] = '\0';
	}
	return (src_len);
}
