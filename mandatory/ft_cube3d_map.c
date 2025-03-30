/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:58:01 by geuyoon           #+#    #+#             */
/*   Updated: 2025/03/30 16:06:11 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

t_map	*init_map(t_data *data, int map_fd);
char	**read_map(t_data *data, t_map *map, int map_fd);
char	**realloc_map(t_data *data, t_map *map, char **map_data, char *tmp_map);
void	map_checker(t_data *data, t_map *map);

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
	map_checker(data, new_map);
}

char	**read_map(t_data *data, t_map *map, int map_fd)
{
	char	**total_map;
	char	*tmp_map;

	total_map = ft_calloc(1, sizeof(char *));
	if (total_map == 0)
		exit_err(data, 0, 0);
	tmp_map = get_next_line(map_fd);
	while (!ft_strlen(tmp_map))
	{
		free(tmp_map);
		tmp_map = get_next_line(map_fd);
	}
	while (tmp_map && ft_strlen(tmp_map))
	{
		if (tmp_map == 0)
		break ;
		if (map->map_width < ft_strlen(tmp_map))
		map->map_width = ft_strlen(tmp_map);
		total_map = realloc_map(data, map, total_map, tmp_map);
		tmp_map = get_next_line(map_fd);
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
	map->map_height++;
	new_map_data = ft_calloc(map->map_height, sizeof(char *));
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
	new_map_data[map->map_height - 1] = tmp_map;
	free_td_str(map_data, height_cnt - 1);
	map_data = 0;
	return (new_map_data);
}

void	map_checker(t_data *data, t_map *map)
{
	int	**round_checker;

	round_checker = init_round_checker(data, map);
	wall_copier(data, map, round_checker);
	if (!map->p_pos->x && !map->p_pos->y)
		map_check_exit(data, round_checker, "no player info", 1);
	else if (!map->p_pos->x || !map->p_pos->y)
		map_check_exit(data, round_checker, "unexpected player pos", 1);
	map_dp(data, round_checker, (int)map->p_pos->x, (int)map->p_pos->y);
}
