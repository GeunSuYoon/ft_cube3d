/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_cast_minimap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:28:10 by geuyoon           #+#    #+#             */
/*   Updated: 2025/05/20 20:34:38 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cube3d_cast.h"

void	cast_minimap(t_game *game);
void	minimap_black(t_image *img, int offset_x, int offset_y);
void	minimap_wall(t_image *img, t_map *map, t_player *player, \
	t_minimap *minimap);
void	init_wall(t_wall *wall, t_player *player, t_minimap *minimap);

void	cast_minimap(t_game *game)
{
	t_image		*img;
	t_player	*player;
	t_map		*map;
	t_minimap	*minimap;

	img = game->window_img;
	player = game->player;
	map = game->map;
	minimap = map->minimap;
	minimap_black(img, minimap->offset_x, minimap->offset_y);
	minimap_wall(img, map, player, minimap);
	draw_circle(img, minimap->offset_x + MWIDTH / 2, \
		minimap->offset_y + MHEIGHT / 2, COLORRED);
	draw_line(img, player, minimap->offset_x, minimap->offset_y);
}

void	minimap_black(t_image *img, int offset_x, int offset_y)
{
	int	y_cnt;
	int	x_cnt;

	y_cnt = 0;
	while (y_cnt < MHEIGHT)
	{
		x_cnt = 0;
		while (x_cnt < MWIDTH)
		{
			draw_pixel(img, offset_x + x_cnt, offset_y + y_cnt, COLORBLACK);
			x_cnt++;
		}
		y_cnt++;
	}
}

void	minimap_wall(t_image *img, t_map *map, t_player *player, \
	t_minimap *minimap)
{
	t_wall	wall;
	int		world_x;
	int		world_y;
	int		y_cnt;
	int		x_cnt;

	init_wall(&wall, player, minimap);
	y_cnt = 0;
	while (y_cnt < MHEIGHT)
	{
		world_y = (int)((wall.start_y + y_cnt) / minimap->scale);
		x_cnt = 0;
		while (x_cnt++ < MWIDTH)
		{
			world_x = (int)((wall.start_x + x_cnt) / minimap->scale);
			if (world_x >= 0 && world_x < (int)map->map_width && \
				world_y >= 0 && world_y < (int)map->map_height)
			{
				if ((map->map_data[world_y][world_x] == WALL))
					draw_pixel(img, minimap->offset_x + x_cnt, \
						minimap->offset_y + y_cnt, COLORGRAY);
			}
		}
		y_cnt++;
	}
}

void	init_wall(t_wall *wall, t_player *player, t_minimap *minimap)
{
	wall->start_x = (int)(player->pos_x * minimap->scale) - MWIDTH / 2;
	wall->start_y = (int)(player->pos_y * minimap->scale) - MHEIGHT / 2;
}
