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

#include "../ft_cube3d_struct.h"

t_player	*init_player(t_game *game);
void		init_player_pos(t_player *player, size_t x, size_t y);
void		init_player_dir(t_player *player, char dir);
void		set_player_pos(t_player *p, char **map_data, double x, double y);
void		set_player_dir(t_player *player, double dir, double rot_speed);

t_player	*init_player(t_game *game)
{
	t_player	*new_player;

	new_player = ft_calloc(1, sizeof(t_player));
	if (!new_player)
		exit_err(game, 0, 0);
	game->player = new_player;
	return (new_player);
}

void	init_player_pos(t_player *player, size_t x, size_t y)
{
	player->pos_x = (double)x + 0.5;
	player->pos_y = (double)y + 0.5;
}

void	init_player_dir(t_player *player, char dir)
{
	if (dir == PNORTH)
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (dir == PSOUTH)
	{
		player->dir_x = 0;
		player->dir_y = 1;
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

void	set_player_pos(t_player *p, char **map_data, double x, double y)
{
	double	new_x;
	double	new_y;

	new_x = p->pos_x + x;
	new_y = p->pos_y + y;
	if (is_move_safe(new_x, p->pos_y, map_data))
		p->pos_x = new_x;
	if (is_move_safe(p->pos_x, new_y, map_data))
		p->pos_y = new_y;
	// printf("TEST: player pos [%f, %f]\n", p->pos_x, p->pos_y);
	// printf("TEST: player dir [%f, %f]\n", p->dir_x, p->dir_y);
}

void	set_player_dir(t_player *player, double dir, double rot_speed)
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
