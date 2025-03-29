/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:34:34 by geuyoon           #+#    #+#             */
/*   Updated: 2025/03/29 16:32:11 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

void	free_td_str(char **str, size_t str_height);
size_t	ft_strtdlen(char **tdstr);
int		ft_strcmp(char *s1, char *s2);

size_t	ft_strtdlen(char **tdstr)
{
	size_t	cnt;

	cnt = 0;
	while (tdstr[cnt])
		cnt++;
	return (cnt);
}

void	free_td_str(char **str, size_t str_height)
{
	size_t	height_cnt;

	height_cnt = 0;
	while (height_cnt < str_height)
	{
		free(str[height_cnt]);
		str[height_cnt] = 0;
		height_cnt++;
	}
	free(str);
	str = 0;
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	cnt;

	cnt = 0;
	while (s1[cnt] && s2[cnt])
	{
		if (s1[cnt] != s2[cnt])
			return (s1[cnt] - s2[cnt]);
		cnt++;
	}
	return (s1[cnt] - s2[cnt]);
}
