/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:31:41 by geuyoon           #+#    #+#             */
/*   Updated: 2025/04/18 09:31:14 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

void	exit_err(t_data *data, char *str, int errsig);
void	print_err(char *str);
void	ft_writeerr(char *str);

void	exit_err(t_data *data, char *str, int errsig)
{
	print_err(str);
	data_free(data);
	if (errsig)
		exit(errsig);
	exit(errno);
}

void	print_err(char *str)
{
	ft_writeerr("Error\n");
	if (str)
	ft_writeerr(str);
	else
		perror(strerror(errno));
	write(STDERR_FILENO, "\n", 1);
}

void	ft_writeerr(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
}
