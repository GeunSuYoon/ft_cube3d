/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_cube3d_image.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: geuyoon <geuyoon@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/20 01:54:26 by geuyoon		   #+#	#+#			 */
/*   Updated: 2025/04/08 10:05:20 by geuyoon		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../ft_cube3d.h"

t_image_con	*init_image_con(t_data *data, int map_fd);
void		parse_image(t_data *data, int map_fd);
void		image_setter(t_data *data, char **info);
t_image		*init_image(t_data *data, char *path);
t_image		*init_rcast_img(t_data *data, t_rcast *rcast);

t_image_con	*init_image_con(t_data *data, int map_fd)
{
	t_image_con	*new_image_con;

	new_image_con = ft_calloc(1, sizeof(t_image_con));
	if (!new_image_con)
		exit_err(data, 0, 0);
	data->image_con = new_image_con;
	parse_image(data, map_fd);
	return (new_image_con);
}

void	parse_image(t_data *data, int map_fd)
{
	char	*tmp_line;
	char	**image_info;
	int		cnt;

	cnt = 0;
	while (cnt < 4)
	{
		tmp_line = read_line(map_fd);
		while (tmp_line && !ft_strlen(tmp_line))
		{
			free(tmp_line);
			tmp_line = read_line(map_fd);
		}
		if (!tmp_line)
			exit_err(data, 0, 0);
		image_info = ft_split(tmp_line, ' ');
		free(tmp_line);
		if (!image_info)
			exit_err(data, 0, 0);
		if (ft_strtdlen(image_info) != 2)
			exit_err(data, ETIMGINFO, 1);
		image_setter(data, image_info);
		free_td_str(image_info, ft_strtdlen(image_info));
		cnt++;
	}
}

void	image_setter(t_data *data, char **info)
{
	if (!ft_strcmp(info[0], MNORTH))
		data->image_con->no = init_image(data, info[1]);
	else if (!ft_strcmp(info[0], MSOUTH))
		data->image_con->so = init_image(data, info[1]);
	else if (!ft_strcmp(info[0], MWEST))
		data->image_con->we = init_image(data, info[1]);
	else if (!ft_strcmp(info[0], MEAST))
		data->image_con->ea = init_image(data, info[1]);
	else
	{
		free_td_str(info, 2);
		exit_err(data, ETIMGINFO, 1);
	}
}

t_image	*init_image(t_data *data, char *path)
{
	t_image	*new_image;

	new_image = ft_calloc(1, sizeof(t_image));
	if (!new_image)
		exit_err(data, 0, 0);
	new_image->img_ptr = mlx_xpm_file_to_image(data->mlx_ctl->mlx, path, &(new_image->width), &(new_image->height));
	if (new_image->img_ptr == 0)
	{
		free(new_image);
		exit_err(data, 0, 0);
	}
	new_image->img_data = mlx_get_data_addr(new_image->img_ptr, &new_image->bpp, &new_image->sizeline, &new_image->endian);
	if (!new_image->img_data)
	{
		image_free(data, new_image);
		exit_err(data, 0, 0);
	}
	image_resizer(data, new_image);
	return (new_image);
}

t_image	*init_rcast_img(t_data *data, t_rcast *rcast)
{
	t_image	*new_image;

	new_image = ft_calloc(1, sizeof(t_image));
	if (!new_image)
		exit_err(data, 0, 0);
	rcast->window_img = new_image;
	new_image->img_ptr = mlx_new_image(data->mlx_ctl->mlx, WWIDTH, WHEIGHT);
	if (!new_image->img_ptr)
		exit_err(data, 0, 0);
	new_image->img_data = mlx_get_data_addr(new_image->img_ptr, &new_image->bpp, &new_image->sizeline, &new_image->endian);
	return (new_image);
}
