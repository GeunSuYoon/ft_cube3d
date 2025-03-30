/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:22:45 by geuyoon           #+#    #+#             */
/*   Updated: 2025/03/30 16:44:17 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	char	*ret_char;

	if (haystack == NULL)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	ret_char = ft_strchr(haystack, (int)*needle);
	while (ret_char != NULL)
	{
		if (ret_char - haystack + needle_len > len)
			return (NULL);
		if (ft_strncmp(ret_char, needle, needle_len) == 0)
			return (ret_char);
		ret_char = ft_strchr(ret_char + 1, (int)*needle);
	}
	return (NULL);
}
