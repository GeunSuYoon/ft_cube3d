/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:28:05 by geuyoon           #+#    #+#             */
/*   Updated: 2025/03/30 16:39:49 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

int	init_map_fd(char *name);

int	main(int argc, char **argv)
{
	t_data	*data;
	int		map_fd;

	if (argc != 2)
		exit_err(0, "unexpected program argument", ERR);
	map_fd = init_map_fd(argv[1]);
	data = init_data(map_fd);
	data_free(data);
	exit(EXIT_SUCCESS);
}

int	init_map_fd(char *name)
{
	int		fd;
	size_t	name_len;

	name_len = ft_strlen(name);
	if (name_len < 4)
		exit_err(0, "unexpected map name", ERR);
	if (ft_strcmp(name + name_len - 4, ".cub"))
		exit_err(0, "unexpected map extention", ERR);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		exit_err(0, 0, 0);
	return (fd);
}
