/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_cube3d_window.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: geuyoon <geuyoon@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/18 10:30:54 by geuyoon		   #+#	#+#			 */
/*   Updated: 2025/04/18 10:34:13 by geuyoon		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

int			cast_window(void *arg);
int			close_window(t_game *game);
static void	key_event(t_game *game);
static void	key_rot(t_game *game, t_player *player);
static void	key_move(t_game *game, t_player *player, t_map *map);

int	cast_window(void *arg)
{
	t_game	*game;

	game = (t_game *)arg;
	key_event(game);
	if (!game->window_img || !game->window_img->img_ptr || \
		!game->window_img->img_data)
		exit_err(game, ETWINDOWIMG, 1);
	if (mlx_clear_window(game->mlx_ctl->mlx, game->mlx_ctl->win) < 0)
		exit_err(game, 0, 0);
	casting_loop(game, game->player);
	if (mlx_put_image_to_window(game->mlx_ctl->mlx, game->mlx_ctl->win, \
		game->window_img->img_ptr, 0, 0) < 0)
		exit_err(game, 0, 0);
	return (0);
}

int	close_window(t_game *game)
{
	if (mlx_clear_window(game->mlx_ctl->mlx, game->mlx_ctl->win) < 0)
		exit_err(game, 0, 0);
	game_free(game);
	printf("=========================\n");
	printf("== Player Close Window ==\n");
	printf("=========================\n");
	exit (EXIT_SUCCESS);
}

static void	key_event(t_game *game)
{
	get_frame_time(game);
	key_move(game, game->player, game->map);
	key_rot(game, game->player);
}

static void	key_rot(t_game *game, t_player *player)
{
	double	rot_speed;

	rot_speed = (double)ROTSPEED * game->fram_time;
	if (game->rot[0])
		set_player_dir(player, -1, rot_speed);
	if (game->rot[1])
		set_player_dir(player, 1, rot_speed);
}

static void	key_move(t_game *game, t_player *player, t_map *map)
{
	double	move_speed;

	move_speed = (double)MOVESPEED * game->fram_time;
	if (game->run_flag)
		move_speed *= 1.5;
	if (game->move[0])
		set_player_pos(player, map->map_data, player->dir_x * move_speed, \
			player->dir_y * move_speed);
	if (game->move[1])
		set_player_pos(player, map->map_data, player->dir_y * move_speed, \
			-player->dir_x * move_speed);
	if (game->move[2])
		set_player_pos(player, map->map_data, -player->dir_x * move_speed, \
			-player->dir_y * move_speed);
	if (game->move[3])
		set_player_pos(player, map->map_data, -player->dir_y * move_speed, \
			player->dir_x * move_speed);
}
