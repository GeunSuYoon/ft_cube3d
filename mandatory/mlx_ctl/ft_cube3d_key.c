/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_cube3d_key.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: geuyoon <geuyoon@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/18 10:32:24 by geuyoon		   #+#	#+#			 */
/*   Updated: 2025/04/20 08:22:09 by geuyoon		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../ft_cube3d.h"

void		key_ctl(t_game *game);
static int	key_press(int keycode, t_game *game);
static void	key_player(int keycode, t_game *game, t_rcast *rcast);
static void	key_rot(int keycode, t_player *player, t_rcast *rcast);
static void	key_move(int keycode, t_player *player, t_map *map, t_rcast *rcast);

void	key_ctl(t_game *game)
{
	mlx_key_hook(game->mlx_ctl->win, &key_press, game);
	mlx_hook(game->mlx_ctl->win, 17, 0, &close_window, game);
}

static int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_window(game);
	if (keycode == XK_Left || keycode == XK_Right || \
		keycode == XK_W || keycode == XK_A || \
		keycode == XK_S || keycode == XK_D || \
		keycode == XK_w || keycode == XK_a || \
		keycode == XK_s || keycode == XK_d)
		key_player(keycode, game, game->rcast);
	return (0);
}

static void	key_player(int keycode, t_game *game, t_rcast *rcast)
{
	get_frame_time(rcast);
	if (keycode == XK_Left || keycode == XK_Right)
		key_rot(keycode, game->player, rcast);
	else if (keycode == XK_W || keycode == XK_A || \
		keycode == XK_S || keycode == XK_D || \
		keycode == XK_w || keycode == XK_a || \
		keycode == XK_s || keycode == XK_d)
		key_move(keycode, game->player, game->map, rcast);
	cast_window(game);
}

static void	key_rot(int keycode, t_player *player, t_rcast *rcast)
{
	double	rot_speed;

	rot_speed = rcast->fram_time * (double)ROTSPEED;
	if (keycode == XK_Left)
		set_player_dir(player, -1, rot_speed);
	else if (keycode == XK_Right)
		set_player_dir(player, 1, rot_speed);
}

static void	key_move(int keycode, t_player *player, t_map *map, t_rcast *rcast)
{
	double	move_speed;

	// move_speed = rcast->fram_time * (double)MOVESPEED;
	(void)rcast;
	move_speed = (double)MOVESPEED;
	if (keycode == XK_W || keycode == XK_w)
		set_player_pos(player, map->map_data, player->dir_x * move_speed, \
			player->dir_y * move_speed);
	else if (keycode == XK_A || keycode == XK_a)
		set_player_pos(player, map->map_data, player->dir_y * move_speed, \
			player->dir_x * move_speed);
	else if (keycode == XK_S || keycode == XK_s)
		set_player_pos(player, map->map_data, -player->dir_x * move_speed, \
			-player->dir_y * move_speed);
	else if (keycode == XK_D || keycode == XK_d)
		set_player_pos(player, map->map_data, -player->dir_y * move_speed, \
			-player->dir_x * move_speed);
}
