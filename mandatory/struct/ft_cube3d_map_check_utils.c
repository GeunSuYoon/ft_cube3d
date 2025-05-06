/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_cube3d_map_check_utils.c						:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: geuyoon <geuyoon@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/07 12:34:50 by geuyoon		   #+#	#+#			 */
/*   Updated: 2025/04/20 08:32:05 by geuyoon		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../ft_cube3d.h"

void	wall_copier(t_data *data, t_map *map, int **round_checker, \
			size_t h_cnt);
void	map_player_setter(t_data *data, int **round_checker, size_t x, \
			size_t y);

void	wall_copier(t_data *data, t_map *map, int **round_checker, \
			size_t h_cnt)
{
	int		ele_check;
	size_t	w_cnt;

	w_cnt = 0;
	while (map->map_data[h_cnt][w_cnt])
	{
		ele_check = map_ele_checker(map->map_data[h_cnt][w_cnt]);
		if (!ele_check)
			map_check_exit(data, round_checker, ETMAPINFO, 1);
		else if (ele_check == 1)
			round_checker[h_cnt][w_cnt] = -1;
		else if (ele_check == 3)
			round_checker[h_cnt][w_cnt] = 1;
		else if (ele_check == 4)
			map_player_setter(data, round_checker, w_cnt, h_cnt);
		w_cnt++;
	}
}

void	map_player_setter(t_data *data, int **round_checker, size_t x, \
			size_t y)
{
	if (data->player->pos_x || data->player->pos_y)
		map_check_exit(data, round_checker, ETPLAYERDUP, 1);
	init_player_pos(data->player, x, y);
	init_player_dir(data->player, data->map->map_data[y][x]);
}
