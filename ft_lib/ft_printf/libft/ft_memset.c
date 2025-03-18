/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:17:47 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/15 10:37:59 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len);

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cnt;
	unsigned char	*b_char;
	unsigned char	c_char;

	cnt = 0;
	b_char = (unsigned char *)b;
	c_char = (unsigned char)c;
	while (cnt < len)
	{
		b_char[cnt] = c_char;
		cnt++;
	}
	return (b);
}
