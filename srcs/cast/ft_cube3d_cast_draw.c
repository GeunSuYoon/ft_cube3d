/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_cast_draw.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:45:56 by geuyoon           #+#    #+#             */
/*   Updated: 2025/05/20 23:09:45 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cube3d_cast.h"

void	draw_pixel(t_image *img, int x, int y, int color);
void	draw_circle(t_image *img, int cx, int cy, int color);
void	draw_line(t_image *img, t_player *player, int offset_x, int offset_y);
void	init_line(t_dline *dline, t_player *player, int offset_x, int offset_y);

void	draw_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WWIDTH || y >= WHEIGHT)
		return ;
	dst = img->img_data + (y * img->sizeline + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_circle(t_image *img, int cx, int cy, int color)
{
	int		angle_cnt;
	double	angle;
	int		dist_a;
	int		dist_b;

	angle_cnt = 0;
	while (angle_cnt < 45)
	{
		angle = angle_cnt * M_PI / 180;
		dist_a = cos(angle) * MPLAYER;
		dist_b = sin(angle) * MPLAYER;
		draw_pixel(img, cx + dist_a, cy + dist_b, color);
		draw_pixel(img, cx + dist_a, cy - dist_b, color);
		draw_pixel(img, cx - dist_a, cy + dist_b, color);
		draw_pixel(img, cx - dist_a, cy - dist_b, color);
		draw_pixel(img, cx + dist_b, cy + dist_a, color);
		draw_pixel(img, cx + dist_b, cy - dist_a, color);
		draw_pixel(img, cx - dist_b, cy + dist_a, color);
		draw_pixel(img, cx - dist_b, cy - dist_a, color);
		angle_cnt++;
	}
}

void	draw_line(t_image *img, t_player *player, int offset_x, int offset_y)
{
	t_dline	dline;
	int		err_checker;

	init_line(&dline, player, offset_x, offset_y);
	while (1)
	{
		draw_pixel(img, dline.x0, dline.y0, COLORGREEN);
		if (dline.x0 == dline.x1 && dline.y0 == dline.y1)
			break ;
		err_checker = 2 * dline.err;
		if (err_checker >= dline.dy)
		{
			dline.err += dline.dy;
			dline.x0 += dline.sx;
		}
		if (err_checker <= dline.dx)
		{
			dline.err += dline.dx;
			dline.y0 += dline.sy;
		}
	}
}

void	init_line(t_dline *dline, t_player *player, int offset_x, int offset_y)
{
	int	dir_x;
	int	dir_y;

	dir_x = (int)(player->dir_x * MPLINE);
	dir_y = (int)(player->dir_y * MPLINE);
	dline->x0 = offset_x + MWIDTH / 2;
	dline->y0 = offset_y + MHEIGHT / 2;
	dline->x1 = dline->x0 + dir_x;
	dline->y1 = dline->y0 + dir_y;
	dline->dx = dir_x;
	if (dline->dx < 0)
		dline->dx *= -1;
	dline->dy = dir_y;
	if (dline->dy > 0)
		dline->dy *= -1;
	dline->sx = 1;
	if (dir_x <= 0)
		dline->sx *= -1;
	dline->sy = 1;
	if (dir_y <= 0)
		dline->sy *= -1;
	dline->err = dline->dx + dline->dy;
}
