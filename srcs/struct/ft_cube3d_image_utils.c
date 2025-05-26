/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_image_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:05:20 by geuyoon           #+#    #+#             */
/*   Updated: 2025/05/26 13:46:55 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cube3d_struct.h"

void	image_resizer(t_game *game, t_image *image);
void	image_resizer_loop(t_image *image, char **resize_data);
void	image_resizer_size(t_image *image, char **resize_data, int h_cnt, \
	int w_cnt);
void	image_changer(t_game *data, t_image *image, void *resize_ptr, \
	char *resize_data);
void	image_err(t_game *game, t_image *image, char *path);

void	image_resizer(t_game *game, t_image *image)
{
	void	*resize_ptr;
	char	*resize_data;
	int		bpp;
	int		sizeline;
	int		endian;

	if (image->width == SIZE && image->height == SIZE)
		return ;
	resize_ptr = mlx_new_image(game->mlx_ctl->mlx, SIZE, SIZE);
	if (!resize_ptr)
	{
		image_free(game, image);
		exit_err(game, 0, 0);
	}
	resize_data = mlx_get_data_addr(resize_ptr, &bpp, &sizeline, &endian);
	if (!resize_data)
	{
		image_free(game, image);
		exit_err(game, 0, 0);
	}
	image_resizer_loop(image, &resize_data);
	image_changer(game, image, resize_ptr, resize_data);
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

	src_w = (SIZE - 1 - w_cnt) * image->width / SIZE;
	src_h = h_cnt * image->height / SIZE;
	if (src_w >= image->width)
		src_w = image->width - 1;
	if (src_h >= image->height)
		src_h = image->height - 1;
	src_idx = src_h * image->sizeline + src_w * (image->bpp / 8);
	resize_idx = h_cnt * (SIZE * image->bpp / 8) + w_cnt * (image->bpp / 8);
	*(int *)(*resize_data + resize_idx) = *(int *)(image->img_data + src_idx);
}

void	image_changer(t_game *game, t_image *image, void *resize_ptr, \
	char *resize_data)
{
	mlx_destroy_image(game->mlx_ctl->mlx, image->img_ptr);
	image->img_ptr = resize_ptr;
	image->img_data = resize_data;
	image->width = SIZE;
	image->height = SIZE;
	image->sizeline = SIZE * image->bpp / 8;
}

void	image_err(t_game *game, t_image *image, char *path)
{
	int		img_fd;
	char	buf[1024];

	img_fd = open(path, O_RDONLY);
	image_free(game, image);
	if (img_fd < 0)
		exit_err(game, ETIMGINFO, 1);
	if (read(img_fd, (void *)buf, 1024) < 0)
	{
		close(img_fd);
		exit_err(game, 0, 0);
	}
	if (ft_strcmp(buf, "/* XPM */\nstatic char *"))
	{
		close(img_fd);
		exit_err(game, ETIMGINFO, 1);
	}
	close(img_fd);
	exit_err(game, 0, 0);
}
