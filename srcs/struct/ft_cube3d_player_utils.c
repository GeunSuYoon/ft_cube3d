/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_player_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:59:09 by geuyoon           #+#    #+#             */
/*   Updated: 2025/05/20 17:38:10 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

int	is_move_safe(double x, double y, char **map_data);
int	is_wall(double x, double y, char **map_data);

int	is_move_safe(double x, double y, char **map_data)
{
	return (!is_wall(x + PSIZE, y + PSIZE, map_data) && \
			!is_wall(x - PSIZE, y + PSIZE, map_data) && \
			!is_wall(x + PSIZE, y - PSIZE, map_data) && \
			!is_wall(x - PSIZE, y - PSIZE, map_data));
}

int	is_wall(double x, double y, char **map_data)
{
	size_t	map_height;
	size_t	map_x;
	size_t	map_y;

	if (x < 0 || y < 0)
		return (1);
	map_x = (size_t)x;
	map_y = (size_t)y;
	map_height = ft_strtdlen(map_data);
	if (map_y >= map_height || map_x >= ft_strlen(map_data[map_y]))
		return (1);
	return (map_data[map_y][map_x] == WALL);
}
