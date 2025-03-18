/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:17:58 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/15 10:37:42 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			cmp_cnt;
	unsigned char	*s1_char;
	unsigned char	*s2_char;

	cmp_cnt = 0;
	s1_char = (unsigned char *)s1;
	s2_char = (unsigned char *)s2;
	while (cmp_cnt < n)
	{
		if (s1_char[cmp_cnt] != s2_char[cmp_cnt])
			return (s1_char[cmp_cnt] - s2_char[cmp_cnt]);
		cmp_cnt++;
	}
	return (0);
}
