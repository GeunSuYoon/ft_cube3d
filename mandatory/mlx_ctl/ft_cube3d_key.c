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

void		key_ctl(t_data *data);
static int	key_press(int keycode, t_data *data);
static void	key_player(int keycode, t_data *data, t_rcast *rcast);
static void	key_rot(int keycode, t_player *player, t_rcast *rcast);
static void	key_move(int keycode, t_player *player, t_map *map, t_rcast *rcast);

void	key_ctl(t_data *data)
{
	mlx_key_hook(data->mlx_ctl->win, &key_press, data);
	mlx_hook(data->mlx_ctl->win, 17, 0, &close_window, data);
}

static int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	if (keycode == XK_Left || keycode == XK_Right || \
		keycode == XK_W || keycode == XK_A || \
		keycode == XK_S || keycode == XK_D || \
		keycode == XK_w || keycode == XK_a || \
		keycode == XK_s || keycode == XK_d)
		key_player(keycode, data, data->rcast);
	return (0);
}

static void	key_player(int keycode, t_data *data, t_rcast *rcast)
{
	get_frame_time(rcast);
	if (keycode == XK_Left || keycode == XK_Right)
		key_rot(keycode, data->player, rcast);
	else if (keycode == XK_W || keycode == XK_A || \
		keycode == XK_S || keycode == XK_D || \
		keycode == XK_w || keycode == XK_a || \
		keycode == XK_s || keycode == XK_d)
		key_move(keycode, data->player, data->map, rcast);
	cast_window(data);
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

	move_speed = rcast->fram_time * (double)MOVESPEED;
	if (keycode == XK_W || keycode == XK_w)
		set_player_pos(player, map->map_data, player->dir_x * move_speed, \
			player->dir_y * move_speed);
	else if (keycode == XK_A || keycode == XK_a)
		set_player_pos(player, map->map_data, -player->dir_x * move_speed, \
			player->dir_y * move_speed);
	else if (keycode == XK_S || keycode == XK_s)
		set_player_pos(player, map->map_data, -player->dir_x * move_speed, \
			-player->dir_y * move_speed);
	else if (keycode == XK_D || keycode == XK_d)
		set_player_pos(player, map->map_data, player->dir_x * move_speed, \
			-player->dir_y * move_speed);
}
