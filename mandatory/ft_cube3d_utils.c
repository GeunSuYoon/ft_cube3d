/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:34:34 by geuyoon           #+#    #+#             */
/*   Updated: 2025/03/19 01:08:42 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

void	free_td_str(char **str, size_t str_height);
size_t	ft_strtdlen(char **tdstr);
void	exit_err(t_data *data, char *str, int errsig);
void	print_err(char *str);

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

void	exit_err(t_data *data, char *str, int errsig)
{
	print_err(str);
	if (errsig)
		exit(errsig);
	exit(errno);
}

void	print_err(char *str)
{
	perror("Error\n");
	if (str)
		perror(str);
	else
		perror(strerror(errno));
	write(STDERR_FILENO, "\n", 1);
}
