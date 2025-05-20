/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:42:49 by geuyoon           #+#    #+#             */
/*   Updated: 2025/05/20 17:37:57 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cube3d_struct.h"
#include "../ft_cube3d_cast.h"

t_minimap	*init_minimap(t_game *game, t_map *map);

t_minimap	*init_minimap(t_game *game, t_map *map)
{
	t_minimap	*new_minimap;
	double		scale_y;

	new_minimap = ft_calloc(1, sizeof(t_minimap));
	if (!new_minimap)
		exit_err(game, 0, 0);
	map->minimap = new_minimap;
	new_minimap->scale = (double)MWIDTH / (double)map->map_width;
	scale_y = (double)MHEIGHT / (double)map->map_height;
	if (scale_y < new_minimap->scale)
		new_minimap->scale = scale_y;
	new_minimap->offset_x = WWIDTH - MWIDTH - MMARGIN;
	new_minimap->offset_y = WHEIGHT - MWIDTH - MMARGIN;
	return (new_minimap);
}
