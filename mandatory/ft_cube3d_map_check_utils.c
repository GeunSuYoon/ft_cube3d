/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_map_check_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:34:50 by geuyoon           #+#    #+#             */
/*   Updated: 2025/04/07 13:07:59 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

void    wall_topbot_copier(t_data *data, t_map *map, int **round_checker, size_t h_cnt);
void    wall_middle_copier(t_data *data, t_map *map, int **round_checker, size_t h_cnt);

void    wall_topbot_copier(t_data *data, t_map *map, int **round_checker, size_t h_cnt)
{
	size_t	w_cnt;

    w_cnt = 0;
    while (map->map_data[h_cnt][w_cnt])
    {
        if (map->map_data[h_cnt][w_cnt] != EMPTY && map->map_data[h_cnt][w_cnt] != WALL && map->map_data[h_cnt][w_cnt] != NEWLINE)
            map_check_exit(data, round_checker, "unexpected map info", 1);
        if (map->map_data[h_cnt][w_cnt] == WALL)
            round_checker[h_cnt][w_cnt] = 1;
        w_cnt++;
    }
}

void    wall_middle_copier(t_data *data, t_map *map, int **round_checker, size_t h_cnt)
{
	int		ele_check;
	size_t	w_cnt;
    int     space_checker;

    w_cnt = 0;
    space_checker = 1;
    while (map->map_data[h_cnt][w_cnt])
    {
        ele_check = map_ele_checker(map->map_data[h_cnt][w_cnt]);
        if (!ele_check)
            map_check_exit(data, round_checker, "unexpected map info", 1);
        else if (ele_check == 1)
            space_checker = 1;
        else
        {
            if (space_checker && ele_check != 3)
		        map_check_exit(data, round_checker, "unexpected map shape", 1);
            if (ele_check == 3)
                round_checker[h_cnt][w_cnt] = 1;
            else if (ele_check == 4)
                map_p_pos_setter(data, round_checker, w_cnt, h_cnt);
            space_checker = 0;
        }
        w_cnt++;
    }
}
