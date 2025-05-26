/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_cast_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:14:19 by geuyoon           #+#    #+#             */
/*   Updated: 2025/05/21 05:42:45 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cube3d_cast.h"

void	cast_init_val(t_ray *ray, t_player *player);
void	cast_side(t_ray *ray, t_player *player);
void	cast_hit(t_ray *ray, char **map_data);
void	cast_dist(t_ray *ray, t_player *player);
void	cast_wall_x(t_ray *ray, t_player *player, t_image *texture);

void	cast_init_val(t_ray *ray, t_player *player)
{
	double	camera_x;

	camera_x = 2 * (double)ray->x / (double)WWIDTH - 1;
	ray->ray_dir_x = player->dir_x + player->plane_x * camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	cast_side(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - (double)ray->map_x) * \
			ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((double)ray->map_x + 1.0 - player->pos_x) * \
			ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - (double)ray->map_y) * \
			ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((double)ray->map_y + 1.0 - player->pos_y) * \
			ray->delta_dist_y;
	}
}

void	cast_hit(t_ray *ray, char **map_data)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map_data[ray->map_y][ray->map_x] == WALL)
			hit = 1;
	}
}

void	cast_dist(t_ray *ray, t_player *player)
{
	double	hit_x;
	double	hit_y;
	double	dx;
	double	dy;

	if (ray->side)
	{
		hit_y = ray->map_y;
		hit_x = player->pos_x + ray->ray_dir_x * \
			(ray->side_dist_y - ray->delta_dist_y);
		if (ray->step_y < 0)
			hit_y += 1.0;
	}
	else
	{
		hit_x = ray->map_x;
		hit_y = player->pos_y + ray->ray_dir_y * \
			(ray->side_dist_x - ray->delta_dist_x);
		if (ray->step_x < 0)
			hit_x += 1.0;
	}
	dx = hit_x - player->pos_x;
	dy = hit_y - player->pos_y;
	ray->perp_wall_dist = sqrt(dx * dx + dy * dy);
}

void	cast_wall_x(t_ray *ray, t_player *player, t_image *texture)
{
	double	wall_x;

	if (ray->side)
		wall_x = player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	else
		wall_x = player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * (double)texture->width);
	if (ray->tex_x < 0)
		ray->tex_x = 0;
	if (ray->tex_x >= texture->width)
		ray->tex_x = texture->width - 1;
	if ((!ray->side && ray->ray_dir_x > 0) || \
		(ray->side && ray->ray_dir_y < 0))
		ray->tex_x = texture->width - ray->tex_x - 1;
}
