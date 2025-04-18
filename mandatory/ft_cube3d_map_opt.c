/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_map_opt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:16:23 by geuyoon           #+#    #+#             */
/*   Updated: 2025/04/18 09:11:42 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

void	map_optimizer(t_map *map, int **round_checker);
void    map_player_checker(t_map *map, int **round_checker, size_t x, size_t y);

void	map_optimizer(t_map *map, int **round_checker)
{
	size_t	h_cnt;
	size_t	w_cnt;

	h_cnt = 0;
	while (h_cnt < map->map_height)
	{
		w_cnt = 0;
		while (map->map_data[h_cnt][w_cnt])
        {
            map_player_checker(map, round_checker, w_cnt, h_cnt);
            w_cnt++;
        }
		h_cnt++;
	}
}

void    map_player_checker(t_map *map, int **round_checker, size_t x, size_t y)
{
    if (map->map_data[y][x] == NEWLINE)
        return ;
    if (x)
    {
        if (round_checker[y][x - 1] == 2)
            return ;
    }
    if (x < map->map_width - 1)
    {
        if (round_checker[y][x + 1] == 2)
            return ;
    }
    if (y)
    {
        if (round_checker[y - 1][x] == 2)
            return ;
    }
    if (y < map->map_height - 1)
    {
        if (round_checker[y + 1][x] == 2)
            return ;
    }
    map->map_data[y][x] = ' ';
}
