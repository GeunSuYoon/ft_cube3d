/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:56:20 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/13 13:32:29 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s1_char;
	char	*s2_char;
	char	*ret_char;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s1_char = (char *)s1;
	s2_char = (char *)s2;
	ret_char = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (ret_char == NULL)
		return (NULL);
	ret_char = ft_memmove(ret_char, s1_char, s1_len);
	ret_char = ft_memmove((ret_char + s1_len), s2_char, s2_len);
	return (ret_char - s1_len);
}
