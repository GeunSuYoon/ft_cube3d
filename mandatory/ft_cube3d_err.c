/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:31:41 by geuyoon           #+#    #+#             */
/*   Updated: 2025/03/30 13:31:29 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

void	exit_err(t_data *data, char *str, int errsig);
void	print_err(char *str);

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
	perror("Error\n");
	if (str)
		perror(str);
	else
		perror(strerror(errno));
	write(STDERR_FILENO, "\n", 1);
}
