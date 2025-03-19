/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 02:13:29 by geuyoon           #+#    #+#             */
/*   Updated: 2025/03/20 02:38:26 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

t_color	*parse_color(t_data *data, int map_fd, char *ident);
t_color	*init_color(t_data *data, char *rgb);

t_color	*parse_color(t_data *data, int map_fd, char *ident)
{
	t_color	*new_color;
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
	if (ft_strncmp(ident, tmp_td_line[0], ft_strlen(tmp_td_line[0])))
		exit_err(data, "unexpected map file information", 1);
	new_color = init_color(data, tmp_td_line[1]);
	free_td_str(tmp_td_line, 2);
	return (new_color);
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
