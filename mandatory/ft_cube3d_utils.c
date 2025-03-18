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

void	print_err(t_data *data, char *str, int errsig);

void	print_err(t_data *data, char *str, int errsig)
{
	perror("Error\n");
	if (str)
		perror(str);
	else
		perror(strerror(errno));
	write(STDERR_FILENO, "\n", 1);
	if (errsig)
		exit(errsig);
	exit(errno);
}
