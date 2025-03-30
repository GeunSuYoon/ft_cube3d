/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:14:55 by geuyoon           #+#    #+#             */
/*   Updated: 2025/03/30 14:07:26 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

t_data  *init_data(int map_fd);

t_data  *init_data(int map_fd)
{
    t_data  *new_data;

    new_data = ft_calloc(1, sizeof(t_data));
    if (!new_data)
        exit_err(0, 0, 0);
    new_data->mlx_ctl = ft_calloc(1, sizeof(t_mlx));
    if (!new_data->mlx_ctl)
        exit_err(new_data, 0, 0);
    new_data->mlx_ctl->mlx = mlx_init();
    if (!new_data->mlx_ctl->mlx)
        exit_err(new_data, 0, 0);
    new_data->mlx_ctl->win = mlx_new_window(new_data->mlx_ctl->mlx, \
        1920, 1060, "cube3D");
    new_data->image_con = init_image_con(new_data, map_fd);
    new_data->color_con = init_color_con(new_data, map_fd);
    return (new_data);
}
