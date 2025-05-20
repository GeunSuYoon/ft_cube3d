/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_cast_draw.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:45:56 by geuyoon           #+#    #+#             */
/*   Updated: 2025/05/20 19:38:54 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cube3d_cast.h"

void	draw_pixel(t_image *img, int x, int y, int color);
void	draw_circle(t_image *img, int cx, int cy, int color);
void	draw_line(t_image *img, t_player *player, int offset_x, int offset_y);
void	init_circle(t_dcircle *dcircle);
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
	t_dcircle	dcircle;

	init_circle(&dcircle);
	while (dcircle.y <= dcircle.x)
	{
		draw_pixel(img, cx + dcircle.x, cy + dcircle.y, color);
		draw_pixel(img, cx + dcircle.y, cy + dcircle.x, color);
		draw_pixel(img, cx + dcircle.y, cy - dcircle.x, color);
		draw_pixel(img, cx + dcircle.x, cy - dcircle.y, color);
		draw_pixel(img, cx - dcircle.y, cy + dcircle.x, color);
		draw_pixel(img, cx - dcircle.x, cy + dcircle.y, color);
		draw_pixel(img, cx - dcircle.x, cy - dcircle.y, color);
		draw_pixel(img, cx - dcircle.y, cy - dcircle.x, color);
		dcircle.y += 1;
		if (dcircle.err <= 0)
			dcircle.err += 2 * dcircle.y + 1;
		if (dcircle.err > 0)
		{
			dcircle.x -= 1;
			dcircle.err -= 2 * dcircle.x + 1;
		}
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

void	init_circle(t_dcircle *dcircle)
{
	dcircle->x = MPLAYER;
	dcircle->y = 0;
	dcircle->err = 0;
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
