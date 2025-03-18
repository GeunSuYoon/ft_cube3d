/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:55:11 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/15 10:39:03 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	ret_size;
	size_t	str_cnt;
	char	*ret_char;

	s_len = ft_strlen(s);
	if (start < s_len)
	{
		if (s_len - start < len)
			ret_size = s_len - start;
		else
			ret_size = len;
	}
	else
		ret_size = 0;
	ret_char = (char *)ft_calloc(ret_size + 1, sizeof(char));
	if (ret_char == NULL)
		return (NULL);
	str_cnt = 0;
	while (str_cnt < ret_size)
	{
		ret_char[str_cnt] = s[start + str_cnt];
		str_cnt++;
	}
	return (ret_char);
}
