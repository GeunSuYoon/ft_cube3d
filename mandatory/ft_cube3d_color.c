/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 02:13:29 by geuyoon           #+#    #+#             */
/*   Updated: 2025/04/07 11:13:46 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

t_color_con	*init_color_con(t_data *data, int map_fd);
void	parse_color(t_data *data, int map_fd);
void	color_setter(t_data *data, char **info);
t_color	*init_color(t_data *data, char *rgb);

t_color_con	*init_color_con(t_data *data, int map_fd)
{
	t_color_con	*new_color_con;

	new_color_con = ft_calloc(1, sizeof(t_color_con));
	if (!new_color_con)
		exit_err(data, 0, 0);
	data->color_con = new_color_con;
	parse_color(data, map_fd);
	return (new_color_con);
}

void	parse_color(t_data *data, int map_fd)
{
	char	*tmp_line;
	char	**color_info;
	int		cnt;

	cnt = 0;
	while (cnt < 2)
	{
		tmp_line = get_next_line(map_fd);
		while (tmp_line && ft_strlen(tmp_line) == 1)
		{
			free(tmp_line);
			tmp_line = get_next_line(map_fd);
		}
		if (!tmp_line)
			exit_err(data, 0, 0);
		color_info = ft_split(tmp_line, ' ');
		free(tmp_line);
		if (!color_info)
			exit_err(data, 0, 0);
		if (ft_strtdlen(color_info) != 2)
			exit_err(data, "unexpected image infomation", 1);
		color_setter(data, color_info);
		free_td_str(color_info, 2);
		cnt++;
	}
}

void	color_setter(t_data *data, char **info)
{
	if (!ft_strcmp(info[0], MFC))
		data->color_con->fc = init_color(data, info[1]);
	else if (!ft_strcmp(info[0], MCC))
		data->color_con->cc = init_color(data, info[1]);
	else
	{
		free_td_str(info, 2);
		exit_err(data, "unexpected color infomation", 1);
	}
}

t_color	*init_color(t_data *data, char *rgb)
{
	t_color	*new_color;
	char	**tdrgb;
	int		r;
	int		g;
	int		b;

	new_color = ft_calloc(1, sizeof(t_color));
	if (!new_color)
		exit_err(data, 0, 0);
	tdrgb = ft_split(rgb, ',');
	if (!tdrgb)
		exit_err(data, 0, 0);
	if (ft_strtdlen(tdrgb) != 3)
		exit_err(data, "unexpected color information", 1);
	r = ft_atoi(tdrgb[0]);
	g = ft_atoi(tdrgb[0]);
	b = ft_atoi(tdrgb[0]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_err(data, "unexpected color information", 1);
	new_color->r = r;
	new_color->g = g;
	new_color->b = b;
	return (new_color);
}
