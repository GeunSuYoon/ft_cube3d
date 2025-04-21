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
static void	key_player(int keycode, t_data *data);
static void	key_rot(int keycode, t_player *player);
static void	key_move(int keycode, t_player *player, t_map *map);

void	key_ctl(t_data *data)
{
	mlx_key_hook(data->mlx_ctl->win, &key_press, data);
}
 
static int	key_press(int keycode, t_data *data)
{
	if (keycode == KESC)
		close_window(data);
	if (keycode == KLEFT || keycode == KRIGHT ||\
		keycode == KW || keycode == KA || keycode == KS || keycode == KD)
		key_player(keycode, data);
	return (0);
}

static void	key_player(int keycode, t_data *data)
{
	if (keycode == KLEFT || keycode == KRIGHT)
		key_rot(keycode, data->player);
	else if (keycode == KW || keycode == KA || keycode == KS || keycode == KD)
		key_move(keycode, data->player, data->map);
	if (mlx_clear_window(data->mlx_ctl->mlx, data->mlx_ctl->win) < 0)
		exit_err(data, 0, 0);
}

static void	key_rot(int keycode, t_player *player)
{
	if (keycode == KLEFT)
	{
		if (0 <= player->dir_y)
			player->dir_x += ROTSPEED;
		else
			player->dir_x -= ROTSPEED;
		if (0 <= player->dir_x)
			player->dir_y -= ROTSPEED;
		else
			player->dir_y += ROTSPEED;
	}
	else if (keycode == KRIGHT)
	{
		if (0 <= player->dir_y)
			player->dir_x -= ROTSPEED;
		else
			player->dir_x += ROTSPEED;
		if (0 <= player->dir_x)
			player->dir_y += ROTSPEED;
		else
			player->dir_y -= ROTSPEED;
	}
}

static void	key_move(int keycode, t_player *player, t_map *map)
{
	if (keycode == KW)
		move_player(player, map, player->dir_x * MOVESPEED, player->dir_y * MOVESPEED);
	else if (keycode == KA)
		move_player(player, map, -player->dir_x * MOVESPEED, player->dir_y * MOVESPEED);
	else if (keycode == KS)
		move_player(player, map, -player->dir_x * MOVESPEED, -player->dir_y * MOVESPEED);
	else if (keycode == KD)
		move_player(player, map, player->dir_x * MOVESPEED, -player->dir_y * MOVESPEED);
}
