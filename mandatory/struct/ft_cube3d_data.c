/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_cube3d_game.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: geuyoon <geuyoon@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/29 16:14:55 by geuyoon		   #+#	#+#			 */
/*   Updated: 2025/04/18 11:15:21 by geuyoon		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../ft_cube3d_struct.h"

t_game	*init_game(int map_fd);

t_game	*init_game(int map_fd)
{
	t_game	*new_game;

	new_game = ft_calloc(1, sizeof(t_game));
	if (!new_game)
		exit_err(0, 0, 0);
	new_game->mlx_ctl = ft_calloc(1, sizeof(t_mlx));
	if (!new_game->mlx_ctl)
		exit_err(new_game, 0, 0);
	new_game->mlx_ctl->mlx = mlx_init();
	if (!new_game->mlx_ctl->mlx)
		exit_err(new_game, 0, 0);
	new_game->mlx_ctl->win = mlx_new_window(new_game->mlx_ctl->mlx, \
		WWIDTH, WHEIGHT, "cube3D");
	new_game->window_img = init_window_img(new_game);
	new_game->image_con = init_image_con(new_game, map_fd);
	init_color_con(new_game, map_fd);
	new_game->player = init_player(new_game);
	new_game->map = init_map(new_game, map_fd);
	return (new_game);
}
