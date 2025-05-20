/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_rcast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:51:17 by geuyoon           #+#    #+#             */
/*   Updated: 2025/05/20 19:41:06 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cube3d_struct.h"
#include "../ft_cube3d_cast.h"

t_ray	*init_rcast(t_game *game);
void	get_frame_time(t_ray *rcast);
void	init_rcast_cf(t_ray *rcast);

t_ray	*init_rcast(t_game *game)
{
	t_ray	*new_rcast;

	new_rcast = ft_calloc(1, sizeof(t_ray));
	if (!new_rcast)
		exit_err(game, 0, 0);
	game->rcast = new_rcast;
	new_rcast->window_img = init_rcast_img(game, new_rcast);
	new_rcast->now_time = get_current_time();
	return (new_rcast);
}

void	get_frame_time(t_ray *rcast)
{
	rcast->old_time = rcast->now_time;
	rcast->now_time = get_current_time();
	rcast->fram_time = rcast->now_time - rcast->old_time;
}

void	init_rcast_cf(t_ray *rcast)
{
	size_t	h_cnt;
	size_t	w_cnt;

	h_cnt = 0;
	while (h_cnt < WHEIGHT / 2)
	{
		w_cnt = 0;
		while (w_cnt < WWIDTH)
		{
			draw_pixel(rcast->window_img, w_cnt, h_cnt, rcast->cc);
			w_cnt++;
		}
		h_cnt++;
	}
	while (h_cnt < WHEIGHT)
	{
		w_cnt = 0;
		while (w_cnt < WWIDTH)
		{
			draw_pixel(rcast->window_img, w_cnt, h_cnt, rcast->fc);
			w_cnt++;
		}
		h_cnt++;
	}
}
