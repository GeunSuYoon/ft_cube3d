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

void	data_free(t_data *data);
void	rcast_free(t_data *data, t_rcast *rcast);
void	map_free(t_map *map);
void	image_con_free(t_data *data, t_image_con *image_con);
void	image_free(t_data *data, t_image *image);

void	data_free(t_data *data)
{
	if (!data)
		return ;
	if (data->mlx_ctl)
	{
		rcast_free(data, data->rcast);
		data->rcast = 0;
		image_con_free(data, data->image_con);
		data->image_con = 0;
		if (data->player)
			free(data->player);
		data->player = 0;
		map_free(data->map);
		data->map = 0;
		if (data->mlx_ctl->win)
			mlx_destroy_window(data->mlx_ctl->mlx, data->mlx_ctl->win);
		data->mlx_ctl->win = 0;
		if (data->mlx_ctl->mlx)
			free(data->mlx_ctl->mlx);
		data->mlx_ctl->mlx = 0;
		free(data->mlx_ctl);
		data->mlx_ctl = 0;
	}
	free(data);
}

void	rcast_free(t_data *data, t_rcast *rcast)
{
	if (!rcast)
		return ;
	if (rcast->window_img)
		image_free(data, rcast->window_img);
	rcast->window_img = 0;
}

void	map_free(t_map *map)
{
	if (!map)
		return ;
	if (map->map_data)
		free_td_str(map->map_data, map->map_height);
	map->map_data = 0;
	free(map);
}

void	image_con_free(t_data *data, t_image_con *image_con)
{
	if (!image_con)
		return ;
	image_free(data, image_con->no);
	image_con->no = 0;
	image_free(data, image_con->so);
	image_con->so = 0;
	image_free(data, image_con->ea);
	image_con->ea = 0;
	image_free(data, image_con->we);
	image_con->we = 0;
	free(image_con);
}

void	image_free(t_data *data, t_image *image)
{
	if (!image)
		return ;
	if (image->img_ptr)
		mlx_destroy_image(data->mlx_ctl->mlx, image->img_ptr);
	image->img_ptr = 0;
	free(image);
}
