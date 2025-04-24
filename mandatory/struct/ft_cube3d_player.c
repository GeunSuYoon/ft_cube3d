/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_cube3d_player.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: geuyoon <geuyoon@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/18 11:09:26 by geuyoon		   #+#	#+#			 */
/*   Updated: 2025/04/18 11:15:32 by geuyoon		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../ft_cube3d.h"

t_player	*init_player(t_data *data);
void		set_player_pos(t_player *player, size_t x, size_t y);
void		set_player_dir(t_player *player, char dir);
void		move_player(t_player *player, t_map *map, double x, double y);
void		rot_player(t_player *player, double dir, double rot_speed);

t_player	*init_player(t_data *data)
{
	t_player	*new_player;

	new_player = ft_calloc(1, sizeof(t_player));
	if (!new_player)
		exit_err(data, 0, 0);
	data->player = new_player;
	return (new_player);
}

void	set_player_pos(t_player *player, size_t x, size_t y)
{
	player->pos_x = (double)x;
	player->pos_y = (double)y;
}

void	set_player_dir(t_player *player, char dir)
{
	if (dir == PNORTH)
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (dir == PSOUTH)
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (dir == PEAST)
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (dir == PWEST)
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	player->plane_x = -1 * player->dir_y * FOV;
	player->plane_y = player->dir_x * FOV;
}

void	move_player(t_player *player, t_map *map, double x, double y)
{
	if (x < 0)
	{
		if (map->map_data[(size_t)player->pos_y][(size_t)(player->pos_x + x - PSIZE)] \
			!= WALL)
			player->pos_x += x;
	}
	else if (map->map_data[(size_t)player->pos_y][(size_t)(player->pos_x + x + PSIZE) + 1] != WALL)
			player->pos_x += x;
	if (y < 0)
	{
		if (map->map_data[(size_t)(player->pos_y + y - PSIZE)][(size_t)player->pos_x] \
			!= WALL)
			player->pos_y += y;
	}
	else if (map->map_data[(size_t)(player->pos_y + y + PSIZE) + 1][(size_t)player->pos_x] != WALL)
		player->pos_y += y;
}

void	rot_player(t_player *player, double dir, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_val;
	double	sin_val;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	cos_val = cos(dir * rot_speed);
	sin_val = sin(dir * rot_speed);
	player->dir_x = player->dir_x * cos_val - player->dir_y * sin_val;
	player->dir_y = old_dir_x * sin_val + player->dir_y * cos_val;
	player->plane_x = player->plane_x * cos_val - player->plane_y * sin_val;
	player->plane_y = old_plane_x * sin_val + player->plane_y * cos_val;
}
