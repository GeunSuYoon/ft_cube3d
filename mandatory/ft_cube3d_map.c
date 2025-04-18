/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:58:01 by geuyoon           #+#    #+#             */
/*   Updated: 2025/04/18 09:07:31 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

t_map	*init_map(t_data *data, int map_fd);
char	**read_map(t_data *data, t_map *map, int map_fd);
char	**realloc_map(t_data *data, t_map *map, char **map_data, char *tmp_map);
char	*read_line(int map_fd);

t_map	*init_map(t_data *data, int map_fd)
{
	t_map	*new_map;

	new_map = ft_calloc(1, sizeof(t_map));
	if (!new_map)
		exit_err(data, 0, 0);
	data->map = new_map;
	new_map->p_pos = ft_calloc(1, sizeof(t_pos));
	if (!new_map->p_pos)
		exit_err(data, 0, 0);
	new_map->map_height = 0;
	new_map->map_width = 0;
	new_map->map_data = read_map(data, new_map, map_fd);
	test_print_mapdata(new_map);
	map_checker(data, new_map);
	return (new_map);
}

char	**read_map(t_data *data, t_map *map, int map_fd)
{
	char	**total_map;
	char	*tmp_map;

	total_map = ft_calloc(1, sizeof(char *));
	if (total_map == 0)
		exit_err(data, 0, 0);
	tmp_map = read_line(map_fd);
	while (tmp_map && !ft_strlen(tmp_map))
	{
		free(tmp_map);
		tmp_map = read_line(map_fd);
	}
	while (tmp_map)
	{
		if (tmp_map[ft_strlen(tmp_map) - 1] != WALL)
		    exit_err(data, "unexpected map shape", 1);
		map->map_height++;
		if (map->map_width < ft_strlen(tmp_map))
			map->map_width = ft_strlen(tmp_map);
		total_map = realloc_map(data, map, total_map, tmp_map);
		free(tmp_map);
		tmp_map = read_line(map_fd);
	}
	close(map_fd);
	return (total_map);
}

char	**realloc_map(t_data *data, t_map *map, char **map_data, char *tmp_map)
{
	char	**new_map_data;
	size_t	height_cnt;

	if (tmp_map[0] == '\n')
		return (map_data);
	new_map_data = ft_calloc(map->map_height + 1, sizeof(char *));
	if (!new_map_data)
		exit_err(data, 0, 0);
	height_cnt = 0;
	while (height_cnt < map->map_height - 1)
	{
		new_map_data[height_cnt] = ft_strdup(map_data[height_cnt]);
		if (!new_map_data[height_cnt])
		{
			free_td_str(new_map_data, height_cnt - 1);
			free_td_str(map_data, map->map_height - 1);
			exit_err(data, 0, 0);
		}
		height_cnt++;
	}
	new_map_data[height_cnt] = ft_strdup(tmp_map);
	free_td_str(map_data, height_cnt);
	map_data = 0;
	return (new_map_data);
}

char	*read_line(int map_fd)
{
	char	*gnl;
	char	*ret_str;

	gnl = get_next_line(map_fd);
	if (!gnl)
		return (0);
	ret_str = ft_strtrim(gnl, "\n");
	free(gnl);
	return (ret_str);
}
