/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:42:49 by geuyoon           #+#    #+#             */
/*   Updated: 2025/05/27 12:07:31 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cube3d_struct.h"
#include "../includes/ft_cube3d_cast.h"

t_minimap	*init_minimap(t_game *game, t_map *map);

t_minimap	*init_minimap(t_game *game, t_map *map)
{
	t_minimap	*new_minimap;

	new_minimap = ft_calloc(1, sizeof(t_minimap));
	if (!new_minimap)
		exit_err(game, 0, 0);
	map->minimap = new_minimap;
	new_minimap->offset_x = WWIDTH - MWIDTH - MMARGIN;
	new_minimap->offset_y = WHEIGHT - MWIDTH - MMARGIN;
	return (new_minimap);
}
