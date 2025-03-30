/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:34:34 by geuyoon           #+#    #+#             */
/*   Updated: 2025/03/29 16:37:35 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

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
