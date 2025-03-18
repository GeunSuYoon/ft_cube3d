/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:03:16 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/15 10:38:45 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	idx;
	size_t	s_len;
	char	*ret_char;

	idx = 0;
	s_len = ft_strlen(s);
	ret_char = (char *)ft_calloc((s_len + 1), sizeof(char));
	if (ret_char == NULL)
		return (NULL);
	while (s[idx] != '\0')
	{
		ret_char[idx] = f((unsigned int)idx, s[idx]);
		idx++;
	}
	return (ret_char);
}
