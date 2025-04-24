/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_cast_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:14:19 by geuyoon           #+#    #+#             */
/*   Updated: 2025/04/24 11:39:42 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cube3d.h"

void	cast_cam(t_rcast *rcast, t_player *player);
void	cast_side(t_rcast *rcast, t_player *player);
void	cast_hit(t_rcast *rcast, char **map_data);
void	cast_wall_x(t_rcast *rcast, t_player *player, t_image *texture);

void	cast_cam(t_rcast *rcast, t_player *player)
{
	double  camera_x;

	camera_x = 2 * (double)rcast->x / (double)SIZE - 1;
	rcast->ray_dir_x = player->dir_x + player->plane_x * camera_x;
	rcast->ray_dir_y = player->dir_y + player->plane_y * camera_x;
	rcast->map_x = (int)player->pos_x;
	rcast->map_y = (int)player->pos_y;
	rcast->delta_dist_x = sqrt(1 + (rcast->ray_dir_y * rcast->ray_dir_y) / \
        (rcast->ray_dir_x * rcast->ray_dir_x));
	rcast->delta_dist_y = sqrt(1 + (rcast->ray_dir_x * rcast->ray_dir_x) / \
        (rcast->ray_dir_y * rcast->ray_dir_y));
}

void	cast_side(t_rcast *rcast, t_player *player)
{
	if (rcast->ray_dir_x < 0)
	{
		rcast->step_x = -1;
		rcast->side_dist_x = (player->pos_x - (double)rcast->map_x) * \
            rcast->delta_dist_x;
	}
	else
	{
		rcast->step_x = 1;
		rcast->side_dist_x = ((double)rcast->map_x + 1.0 - player->pos_x) * \
            rcast->delta_dist_x;
	}
	if (rcast->ray_dir_y < 0)
	{
		rcast->step_y = -1;
		rcast->side_dist_y = (player->pos_y - (double)rcast->map_y) * \
            rcast->delta_dist_y;
	}
	else
	{
		rcast->step_y = 1;
		rcast->side_dist_y = ((double)rcast->map_y + 1.0 - player->pos_y) * \
            rcast->delta_dist_y;
	}
}

void	cast_hit(t_rcast *rcast, char **map_data)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (rcast->side_dist_x < rcast->side_dist_y)
		{
			rcast->side_dist_x += rcast->delta_dist_x;
			rcast->map_x += rcast->step_x;
			rcast->side = 0;
		}
		else
		{
			rcast->side_dist_y += rcast->delta_dist_y;
			rcast->map_y += rcast->step_y;
			rcast->side = 1;				
		}
		if (map_data[rcast->map_y][rcast->map_x] == WALL)
			hit = 1;
	}
}

void	cast_wall_x(t_rcast *rcast, t_player *player, t_image *texture)
{
	double	wall_x;
	
	if (rcast->side)
	wall_x = player->pos_x + rcast->perp_wall_dist * rcast->ray_dir_x;
	else
	wall_x = player->pos_y + rcast->perp_wall_dist * rcast->ray_dir_y;
	wall_x -= floor(wall_x);
	
	rcast->tex_x = (int)(wall_x * (double)texture->width);
	if ((!rcast->side && rcast->ray_dir_x > 0) || \
        (rcast->side && rcast->ray_dir_y < 0))
		rcast->tex_x = texture->width - rcast->tex_x - 1;
}
