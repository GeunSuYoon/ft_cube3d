/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_image_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:05:20 by geuyoon           #+#    #+#             */
/*   Updated: 2025/04/24 15:37:19 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cube3d.h"

void	image_resizer(t_data *data, t_image *image);
void	image_resizer_loop(t_image *image, char **resize_data);
void	image_resizer_size(t_image *image, char **resize_data, int h_cnt, \
	int w_cnt);
void	image_changer(t_data *data, t_image *image, void *resize_ptr, \
	char *resize_data);

void	image_resizer(t_data *data, t_image *image)
{
	void	*resize_ptr;
	char	*resize_data;
	int		bpp;
	int		sizeline;
	int		endian;

	resize_ptr = mlx_new_image(data->mlx_ctl->mlx, SIZE, SIZE);
	if (!resize_ptr)
	{
		image_free(data, image);
		exit_err(data, 0, 0);
	}
	resize_data = mlx_get_data_addr(resize_ptr, &bpp, &sizeline, &endian);
	if (!resize_data)
	{
		image_free(data, image);
		exit_err(data, 0, 0);
	}
	image_resizer_loop(image, &resize_data);
	image_changer(data, image, resize_ptr, resize_data);
}

void	image_resizer_loop(t_image *image, char **resize_data)
{
	int	h_cnt;
	int	w_cnt;

	h_cnt = 0;
	while (h_cnt < SIZE)
	{
		w_cnt = 0;
		while (w_cnt < SIZE)
		{
			image_resizer_size(image, resize_data, h_cnt, w_cnt);
			w_cnt++;
		}
		h_cnt++;
	}
}

void	image_resizer_size(t_image *image, char **resize_data, int h_cnt, \
	int w_cnt)
{
	int	src_w;
	int	src_h;
	int	src_idx;
	int	resize_idx;

	src_w = w_cnt * image->width / SIZE;
	src_h = h_cnt * image->height / SIZE;
	src_idx = src_w * (image->bpp / 8) + src_h * image->sizeline;
	resize_idx = w_cnt * (image->bpp / 8) + h_cnt * (SIZE * image->bpp / 8);
	*(int *)(*resize_data + resize_idx) = *(int *)(image->img_data + src_idx);
}

void	image_changer(t_data *data, t_image *image, void *resize_ptr, \
	char *resize_data)
{
	mlx_destroy_image(data->mlx_ctl->mlx, image->img_ptr);
	image->img_ptr = resize_ptr;
	image->img_data = resize_data;
	image->width = SIZE;
	image->height = SIZE;
	image->sizeline = SIZE * image->bpp / 8;
}
