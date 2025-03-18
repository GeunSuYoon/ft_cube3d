/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:58:01 by geuyoon           #+#    #+#             */
/*   Updated: 2025/03/19 05:25:03 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

t_map	*init_map(t_data *data, char *name, int map_fd);
char	**read_map(t_data *data, t_map *map, char *name, int map_fd);

t_map	*init_map(t_data *data, char *name, int map_fd)
{
	t_map	*new_map;

	new_map = ft_calloc(1, sizeof(t_map));
	if (!new_map)
		print_err(data, 0, 0);
}

char	**read_map(t_data *data, t_map *map, char *name, int map_fd)
{
	char	**total_map;
	char	*tmp_map;

	total_map = ft_calloc(1, sizeof(char *));
	if (total_map == 0)
		print_error(data, 0, 0);
	while (1)
	{
		tmp_map = get_next_line(map_fd);
		if (tmp_map == 0)
		{
			map_close_check(data, map, tmp_map, map_fd);
			break ;
		}
		map_size(data, map, tmp_map);
		total_map = realloc_map(map, total_map, tmp_map);
	}
	close(map_fd);
	return (total_map);
}
