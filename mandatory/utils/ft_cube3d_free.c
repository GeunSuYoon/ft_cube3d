/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_cube3d_free.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: geuyoon <geuyoon@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/30 13:04:55 by geuyoon		   #+#	#+#			 */
/*   Updated: 2025/04/18 11:57:26 by geuyoon		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../ft_cube3d.h"

void	game_free(t_game *game);
void	map_free(t_map *map);
void	image_con_free(t_game *game, t_image_con *image_con);
void	image_free(t_game *game, t_image *image);

void	game_free(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx_ctl)
	{
		image_con_free(game, game->image_con);
		game->image_con = 0;
		if (game->player)
			free(game->player);
		game->player = 0;
		map_free(game->map);
		game->map = 0;
		if (game->window_img)
			image_free(game, game->window_img);
		game->window_img = 0;
		if (game->mlx_ctl->win)
			mlx_destroy_window(game->mlx_ctl->mlx, game->mlx_ctl->win);
		game->mlx_ctl->win = 0;
		if (game->mlx_ctl->mlx)
			free(game->mlx_ctl->mlx);
		game->mlx_ctl->mlx = 0;
		free(game->mlx_ctl);
		game->mlx_ctl = 0;
	}
	free(game);
}

void	map_free(t_map *map)
{
	if (!map)
		return ;
	if (map->map_data)
		free_td_str(map->map_data, map->map_height);
	map->map_data = 0;
	if (map->minimap)
		free(map->minimap);
	map->minimap = 0;
	free(map);
}

void	image_con_free(t_game *game, t_image_con *image_con)
{
	if (!image_con)
		return ;
	image_free(game, image_con->no);
	image_con->no = 0;
	image_free(game, image_con->so);
	image_con->so = 0;
	image_free(game, image_con->ea);
	image_con->ea = 0;
	image_free(game, image_con->we);
	image_con->we = 0;
	free(image_con);
}

void	image_free(t_game *game, t_image *image)
{
	if (!image)
		return ;
	if (image->img_ptr)
		mlx_destroy_image(game->mlx_ctl->mlx, image->img_ptr);
	image->img_ptr = 0;
	free(image);
}
