/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:17:37 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/15 11:33:26 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			chr_cnt;
	unsigned char	*s_char;
	unsigned char	target;

	chr_cnt = 0;
	s_char = (unsigned char *)s;
	target = (unsigned char)c;
	while (chr_cnt < n)
	{
		if (s_char[chr_cnt] == target)
			return ((void *)(s_char + chr_cnt));
		chr_cnt++;
	}
	return (NULL);
}
