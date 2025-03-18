/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:57:28 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/15 10:39:00 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set);
size_t	beg_set_cnt(char const *s1, char const *set);
size_t	end_set_cnt(char const *s1, char const *set, size_t s1_len, size_t cnt);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	beg_set_len;
	size_t	end_set_len;
	size_t	ret_size;
	char	*ret_char;

	s1_len = ft_strlen(s1);
	beg_set_len = 0;
	end_set_len = 0;
	if (s1_len != 0)
	{
		beg_set_len += beg_set_cnt(s1, set);
		if (beg_set_len != s1_len)
			end_set_len += end_set_cnt(s1, set, s1_len, beg_set_len);
	}
	ret_size = s1_len - beg_set_len - end_set_len;
	ret_char = (char *)ft_calloc(ret_size + 1, sizeof(char));
	if (ret_char == NULL)
		return (NULL);
	ft_memmove(ret_char, s1 + beg_set_len, ret_size);
	return (ret_char);
}

size_t	beg_set_cnt(char const *s1, char const *set)
{
	size_t	beg_set_cnt;

	beg_set_cnt = 0;
	while (*s1 != '\0')
	{
		if (ft_strchr(set, (int)(*s1)) == NULL)
			return (beg_set_cnt);
		s1++;
		beg_set_cnt++;
	}
	return (beg_set_cnt);
}

size_t	end_set_cnt(char const *s1, char const *set, size_t s1_len, size_t cnt)
{
	size_t	end_set_cnt;
	size_t	s1_cnt;

	end_set_cnt = 0;
	s1_cnt = 0;
	while (cnt < s1_len - s1_cnt - 1)
	{
		if (ft_strchr(set, (int)(s1[s1_len - s1_cnt - 1])) == NULL)
			return (end_set_cnt);
		s1_cnt++;
		end_set_cnt++;
	}
	return (end_set_cnt);
}
