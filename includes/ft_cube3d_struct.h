/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:35:42 by geuyoon           #+#    #+#             */
/*   Updated: 2025/05/20 23:16:03 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUBE3D_STRUCT_H
# define FT_CUBE3D_STRUCT_H

# include "ft_cube3d.h"

// resizer structure
typedef struct s_cutter
{
	int		h_flag;
	int		w_flag;
	size_t	w_s;
	size_t	h_s;
	size_t	new_height;
}	t_cutter;

// map
t_map		*init_map(t_game *game, int map_fd);
// minimap
t_minimap	*init_minimap(t_game *game, t_map *map);
// color
void		init_color_con(t_game *game, int map_fd);
// player
t_player	*init_player(t_game *game);
// image
t_image_con	*init_image_con(t_game *game, int map_fd);
t_image		*init_window_img(t_game *game);
// image utils
void		parse_image(t_game *game, int map_fd);
void		image_resizer(t_game *game, t_image *image);
// map checker
void		map_checker(t_game *game, t_map *map);
void		map_dp(t_game *game, int **round_checker, size_t x, size_t y);
int			**init_round_checker(t_game *game, t_map *map);
int			map_ele_checker(char ele);
void		map_check_exit(t_game *game, int **round_checker, char *str, \
	int errsig);
void		map_p_pos_setter(t_game *game, int **round_checker, size_t x, \
	size_t y);
void		wall_topbot_copier(t_game *game, t_map *map, int **round_checker, \
	size_t h_cnt);
void		wall_copier(t_game *game, t_map *map, int **round_checker, \
	size_t h_cnt);
// map opt
void		map_optimizer(t_map *map, int **round_checker);
void		map_resizer(t_game *game, t_map *map);
// player
void		init_player_pos(t_player *player, size_t x, size_t y);
void		init_player_dir(t_player *player, char dir);

#endif