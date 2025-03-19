/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:54:26 by geuyoon           #+#    #+#             */
/*   Updated: 2025/03/20 02:33:53 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

t_image	*parse_image(t_data *data, int map_fd, char *ident);
t_image	*init_image(t_data *data, char *path);

t_image	*parse_image(t_data *data, int map_fd, char *ident)
{
	t_image	*new_image;
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
		exit_err(data, "unexpected map file information", 0);
	new_image = init_image(data, tmp_td_line[1]);
	free_td_str(tmp_td_line, 2);
	return (new_image);
}

t_image	*init_image(t_data *data, char *path)
{
	t_image	*new_image;

	new_image = ft_calloc(1, sizeof(t_image));
	if (!new_image)
		exit_err(data, 0, 0);
	new_image->image_path = ft_strdup(path);
	if (!new_image->image_path)
		exit_err(data, 0, 0);
	return (new_image);
}
