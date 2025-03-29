/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:54:26 by geuyoon           #+#    #+#             */
/*   Updated: 2025/03/29 15:58:37 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

void	parse_image(t_data *data, int map_fd);
int		image_setter(t_data *data, char *ident, char *path);
t_image	*init_image(t_data *data, char *path);

void	parse_image(t_data *data, int map_fd)
{
	char	*tmp_line;
	char	**tmp_td_line;
	
	tmp_line = get_next_line(map_fd);
	while (tmp_line && !ft_strlen(tmp_line))
		tmp_line = get_next_line(map_fd);
		if (!tmp_line)
		exit_err(data, 0, 0);
		tmp_td_line = ft_split(tmp_line, ' ');
		free(tmp_line);
		if (!tmp_td_line)
		exit_err(data, 0, 0);
		if (ft_strtdlen(tmp_td_line) != 2)
		exit_err(data, 0, 0);
		if (image_setter(data, tmp_td_line[0], tmp_td_line[1]))
		{
			free_td_str(tmp_td_line, 2);
		exit_err(data, "unexpected image infomation", 1);
	}
	free_td_str(tmp_td_line, 2);
}

int	image_setter(t_data *data, char *ident, char *path)
{
	if (!ft_strcmp(ident, MNORTH))
		data->no = init_image(data, path);
	else if (!ft_strcmp(ident, MSOUTH))
		data->so = init_image(data, path);
	else if (!ft_strcmp(ident, MWEST))
		data->we = init_image(data, path);
	else if (!ft_strcmp(ident, MEAST))
		data->ea = init_image(data, path);
	else
		return (1);
	return (0);
}

t_image	*init_image(t_data *data, char *path)
{
	t_image	*new_image;
	int		image_fd;

	image_fd = open(path, O_RDONLY);
	if (image_fd == -1)
		exit_err(data, 0, 0);
	close(image_fd);
	new_image = ft_calloc(1, sizeof(t_image));
	if (!new_image)
		exit_err(data, 0, 0);
	new_image->img_ptr = mlx_xpm_file_to_image(data->mlx_ctl->mlx, path, &(new_image->width), &(new_image->height));
	if (new_image->img_ptr == 0)
	{
		free(new_image);
		exit_err(data, 0, 0);
	}
	return (new_image);
}
