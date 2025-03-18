/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:52:51 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/15 10:38:48 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char	*s1_1;
	unsigned const char	*s2_1;
	size_t				cmp_cnt;

	s1_1 = (unsigned const char *)s1;
	s2_1 = (unsigned const char *)s2;
	cmp_cnt = 0;
	while (cmp_cnt < n && s1_1[cmp_cnt] && s2_1[cmp_cnt])
	{
		if (s1_1[cmp_cnt] != s2_1[cmp_cnt])
			return (s1_1[cmp_cnt] - s2_1[cmp_cnt]);
		cmp_cnt++;
	}
	if (cmp_cnt == n)
		return (0);
	return (s1_1[cmp_cnt] - s2_1[cmp_cnt]);
}
