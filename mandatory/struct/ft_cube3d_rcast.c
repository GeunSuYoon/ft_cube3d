/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_rcast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:51:17 by geuyoon           #+#    #+#             */
/*   Updated: 2025/04/24 11:08:31 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cube3d.h"

t_rcast *init_rcast(t_data *data);

t_rcast *init_rcast(t_data *data)
{
    t_rcast *new_rcast;

    new_rcast = ft_calloc(1, sizeof(t_rcast));
    if (!new_rcast)
        exit_err(data, 0, 0);
    data->rcast = new_rcast;
    new_rcast->window_img = init_rcast_img(data, new_rcast);
    return (new_rcast);
}
