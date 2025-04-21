/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_cube3d_map_resizer.c							:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: geuyoon <geuyoon@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/18 08:02:25 by geuyoon		   #+#	#+#			 */
/*   Updated: 2025/04/18 13:54:37 by geuyoon		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../ft_cube3d.h"

void	map_resizer(t_data *data, t_map *map);
void	init_cutter(t_map *map, t_cutter *cutter);
void	cutter_h(t_cutter *cutter, size_t h_cnt);
char	**init_new_map(t_data *data, t_map *map, t_cutter *cut);
void	map_resizer_err(t_data *data, char **new_map, size_t h_cnt);

void	map_resizer(t_data *data, t_map *map)
{
	t_cutter	new_cutter;
	char		**new_map;

	new_cutter.h_s = 0;
	new_cutter.new_height = 0;
	new_cutter.w_s = 0;
	init_cutter(map, &new_cutter);
	new_map = init_new_map(data, map, &new_cutter);
	free_td_str(map->map_data, map->map_height);
	map->map_height = new_cutter.new_height;
	map->map_data = new_map;
	data->player->pos_x -= (float)new_cutter.w_s;
	data->player->pos_y -= (float)new_cutter.h_s;
}

void	init_cutter(t_map *map, t_cutter *cutter)
{
	size_t	h_cnt;
	size_t	is_map;
	size_t	w_cnt;

	h_cnt = 0;
	while (h_cnt < map->map_height)
	{
		is_map = 0;
		w_cnt = 0;
		while (map->map_data[h_cnt][w_cnt])
		{
			if (map->map_data[h_cnt][w_cnt] != EMPTY)
			{
				if (!cutter->w_s || w_cnt < cutter->w_s)
					cutter->w_s = w_cnt;
				is_map++;
			}
			w_cnt++;
		}
		if (is_map)
			cutter_h(cutter, h_cnt);
		else if (cutter->new_height)
			return ;
		h_cnt++;
	}
}

void	cutter_h(t_cutter *cutter, size_t h_cnt)
{
	if (!h_cnt)
		cutter->h_s = h_cnt;
	else if (!cutter->h_s)
		cutter->h_s = h_cnt;
	cutter->new_height++;
}

char	**init_new_map(t_data *data, t_map *map, t_cutter *cut)
{
	char	**new_map;
	size_t	h;
	size_t	w;
	size_t	empty_flag;

	new_map = ft_calloc(cut->new_height + 1, sizeof(char *));
	if (!new_map)
		exit_err(data, 0, 0);
	h = 0;
	while (h < cut->new_height)
	{
		empty_flag = 0;
		w = 0;
		while (map->map_data[cut->h_s + h][cut->w_s + w])
		{
			if (empty_flag && !map->map_data[cut->h_s + h][cut->w_s + w])
				break ;
			w++;
		}
		new_map[h] = ft_strndup(map->map_data[cut->h_s + h] + cut->w_s, w);
		if (!new_map)
			map_resizer_err(data, new_map, h);
		h++;
	}
	return (new_map);
}

void	map_resizer_err(t_data *data, char **new_map, size_t h_cnt)
{
	free_td_str(new_map, h_cnt);
	exit_err(data, 0, 0);
}
