/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:09:26 by geuyoon           #+#    #+#             */
/*   Updated: 2025/04/18 11:15:32 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

t_player    *init_player(t_data *data);
void        set_player_pos(t_player *player, size_t x, size_t y);
void        set_player_dir(t_player *player, char dir);

t_player    *init_player(t_data *data)
{
    t_player    *new_player;

    new_player = ft_calloc(1, sizeof(t_player));
    if (!new_player)
        exit_err(data, 0, 0);
    data->player = new_player;
    return (new_player);
}

void    set_player_pos(t_player *player, size_t x, size_t y)
{
    player->pos_x = (double)x;
    player->pos_y = (double)y;
}

void    set_player_dir(t_player *player, char dir)
{
    if (dir == PNORTH)
    {
        player->dir_x = 0;
        player->dir_y = 1;
    }
    else if (dir == PSOUTH)
    {
        player->dir_x = 0;
        player->dir_y = -1;
    }
    else if (dir == PEAST)
    {
        player->dir_x = 1;
        player->dir_y = 0;
    }
    else if (dir == PEAST)
    {
        player->dir_x = -1;
        player->dir_y = 0;
    }
}
