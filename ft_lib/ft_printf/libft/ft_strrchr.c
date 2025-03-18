/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:24:12 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/15 10:38:52 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	char	target;
	char	*ret_char;

	target = (char)c;
	ret_char = NULL;
	while (*s != '\0')
	{
		if (*s == target)
			ret_char = (char *)s;
		s++;
	}
	if (*s == target)
		ret_char = (char *)s;
	return (ret_char);
}
