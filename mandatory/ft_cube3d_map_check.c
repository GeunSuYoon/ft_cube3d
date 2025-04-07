/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_map_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:12:31 by geuyoon           #+#    #+#             */
/*   Updated: 2025/04/07 09:49:58 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

void	wall_copier(t_data *data, t_map *map, int **round_checker);
int		**init_round_checker(t_data *data, t_map *map);
int		map_ele_checker(char ele);
void	map_check_exit(t_data *data, int **round_checker, char *str, int errsig);
void	map_p_pos_setter(t_data *data, int **round_checker, size_t x, size_t y);

void	wall_copier(t_data *data, t_map *map, int **round_checker)
{
	size_t	h_cnt;
	size_t	w_cnt;
	int		ele_check;

	h_cnt = 0;
	while (h_cnt < map->map_height)
	{
		w_cnt = 0;
		while (map->map_data[h_cnt][w_cnt])
		{
			ele_check = map_ele_checker(map->map_data[h_cnt][w_cnt]);
			if (!ele_check)
				map_check_exit(data, round_checker, "unexpected map info", 1);
			else if (ele_check == 3)
				round_checker[h_cnt][w_cnt] = 1;
			else if (ele_check == 4)
				map_p_pos_setter(data, round_checker, w_cnt, h_cnt);
			w_cnt++;
		}
		h_cnt++;
	}
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
		ret_checker[cnt] = ft_calloc(map->map_width - 1, sizeof(int));
		if (!ret_checker[cnt])
		{
			free_td_int(ret_checker, cnt);
			exit_err(data, 0, 0);
		}
		cnt++;
	}
	return (ret_checker);
}

int    map_ele_checker(char ele)
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

void	map_p_pos_setter(t_data *data, int **round_checker, size_t x, size_t y)
{
	if (data->map->p_pos->x || data->map->p_pos->y)
		map_check_exit(data, round_checker, "duplicate player info", 1);
	data->map->p_pos->x = x;
	data->map->p_pos->y = y;
}
