/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:02:08 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/15 10:38:21 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *s, char c);
size_t		find_col_len(char const *s, char c);
char const	*set_word(char const *s, char c, char **ret_char);
char const	*find_next_word(char const *s, char c);
void		free_ret_char(char **ret_char, size_t col_len);

char	**ft_split(char const *s, char c)
{
	size_t	col_len;
	size_t	col_cnt;
	char	**ret_char;

	col_len = find_col_len(s, c);
	ret_char = (char **)ft_calloc(col_len + 1, sizeof(char *));
	if (ret_char == NULL)
		return (NULL);
	col_cnt = 0;
	while (col_cnt < col_len)
	{
		s = set_word(s, c, &(ret_char[col_cnt]));
		if (ret_char[col_cnt] == NULL)
		{
			free_ret_char(ret_char, col_cnt);
			return (NULL);
		}
		col_cnt++;
	}
	return (ret_char);
}

size_t	find_col_len(char const *s, char c)
{
	int		cflag;
	size_t	col_len;

	cflag = 1;
	col_len = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (cflag == 1)
				col_len++;
			cflag = 0;
		}
		else
			cflag = 1;
		s++;
	}
	return (col_len);
}

char const	*set_word(char const *s, char c, char **ret_char)
{
	size_t	row_len;

	s = find_next_word(s, c);
	row_len = 0;
	while (s[row_len] != '\0' && s[row_len] != c)
		row_len++;
	*ret_char = (char *)ft_calloc(row_len + 1, sizeof(char));
	if (*ret_char == NULL)
		return (NULL);
	*ret_char = ft_memmove(*ret_char, s, row_len);
	s += row_len;
	return (s);
}

char const	*find_next_word(char const *s, char c)
{
	while (*s == c && *s != '\0')
		s++;
	return (s);
}

void	free_ret_char(char **ret_char, size_t col_len)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < col_len)
	{
		free(ret_char[cnt]);
		ret_char[cnt] = NULL;
		cnt++;
	}
	free(ret_char);
	ret_char = NULL;
}
