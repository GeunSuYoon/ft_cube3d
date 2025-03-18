/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:18:14 by geuyoon           #+#    #+#             */
/*   Updated: 2023/11/05 16:19:35 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	cat_cnt;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst == NULL)
		return (src_len + dstsize);
	if (dst == NULL || dst_len >= dstsize)
		return (src_len + dstsize);
	cat_cnt = 0;
	while (dst_len + cat_cnt < dstsize - 1 && src[cat_cnt] != '\0')
	{
		dst[dst_len + cat_cnt] = src[cat_cnt];
		cat_cnt++;
	}
	dst[dst_len + cat_cnt] = '\0';
	return (src_len + dst_len);
}
