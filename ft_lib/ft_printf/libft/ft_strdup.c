/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:26:12 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/15 10:38:30 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1);

char	*ft_strdup(const char *s1)
{
	char	*ret_char;
	size_t	s1_len;
	size_t	dup_cnt;

	s1_len = ft_strlen(s1);
	ret_char = (char *)ft_calloc(s1_len + 1, sizeof(char));
	if (ret_char == NULL)
		return (NULL);
	dup_cnt = 0;
	while (dup_cnt < s1_len)
	{
		ret_char[dup_cnt] = s1[dup_cnt];
		dup_cnt++;
	}
	return (ret_char);
}
