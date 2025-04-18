/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_map_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:12:31 by geuyoon           #+#    #+#             */
/*   Updated: 2025/04/18 11:18:04 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

void	map_checker(t_data *data, t_map *map);
int		**init_round_checker(t_data *data, t_map *map);
int		map_ele_checker(char ele);
void	map_check_exit(t_data *data, int **round_checker, char *str, int errsig);
void	map_dp(t_data *data, int **round_checker, size_t x, size_t y);

void	map_checker(t_data *data, t_map *map)
{
	int		**round_checker;
	size_t	h_cnt;

	round_checker = init_round_checker(data, map);
	h_cnt = 0;
	while (h_cnt < map->map_height)
	{
		wall_middle_copier(data, map, round_checker, h_cnt);
		h_cnt++;
	}
	test_print_round_checker(round_checker, map);
	if (!data->player->pos_x && !data->player->pos_y)
		map_check_exit(data, round_checker, "no player info", 1);
	else if (!data->player->pos_x || !data->player->pos_y)
		map_check_exit(data, round_checker, "unexpected player pos", 1);
	map_dp(data, round_checker, (size_t)data->player->pos_x, (size_t)data->player->pos_y);
	test_print_round_checker(round_checker, map);
	map_optimizer(map, round_checker);
	test_print_mapdata(map);
	free_td_int(round_checker, map->map_height);
	map_resizer(data, map);
	test_print_mapdata(map);
}

int	**init_round_checker(t_data *data, t_map *map)
{
	int 	**ret_checker;
	size_t	cnt;

	ret_checker = ft_calloc(map->map_height, sizeof(int *));
	if (!ret_checker)
		exit_err(data, 0, 0);
	cnt = 0;
	while (cnt < map->map_height)
	{
		ret_checker[cnt] = ft_calloc(map->map_width, sizeof(int));
		if (!ret_checker[cnt])
		{
			free_td_int(ret_checker, cnt);
			exit_err(data, 0, 0);
		}
		cnt++;
	}
	return (ret_checker);
}

int	map_ele_checker(char ele)
{
	if (ele == EMPTY)
		return (1);
	if (ele == SPACE)
		return (2);
	if (ele == WALL)
		return (3);
	if (ele == PNORTH)
		return (4);
	if (ele == PSOUTH)
		return (4);
	if (ele == PEAST)
		return (4);
	if (ele == PWEST)
		return (4);
	if (ele == NEWLINE)
		return (5);
	return (0);
}

void	map_check_exit(t_data *data, int **round_checker, char *str, int errsig)
{
	free_td_int(round_checker, data->map->map_height);
	exit_err(data, str, errsig);
}

void	map_dp(t_data *data, int **round_checker, size_t x, size_t y)
{
	if (round_checker[y][x])
		return ;
	if (!x || !y || x == data->map->map_width - 1 || y == data->map->map_height - 1)
		map_check_exit(data, round_checker, "unexpected map shape", 1);
	round_checker[y][x] = 2;
	map_dp(data, round_checker, x, y + 1);
	map_dp(data, round_checker, x, y - 1);
	map_dp(data, round_checker, x + 1, y);
	map_dp(data, round_checker, x - 1, y);
}
