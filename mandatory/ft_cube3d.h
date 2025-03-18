/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:28:05 by geuyoon           #+#    #+#             */
/*   Updated: 2025/03/19 01:14:19 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUBE3D_H
# define FT_CUBE3D_H

# define SPACE '0'
# define WALL '1'
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'
# define EMPTY ' '
# define ERR 1
# define MNORTH "NO"
# define MSOUTH "SO"
# define MWEST "WE"
# define MEAST "EA"
# define MFC "F"
# define MCC "C"

# include "../ft_lib/ft_printf/libft/libft.h"
# include "../ft_lib/ft_printf/ft_printf.h"
# include "../ft_lib/ft_gnl/get_next_line.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <errno.h>
# include <math.h>
# include <string.h>

// position structure
typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;
typedef struct s_map
{
	char	**map_data;
}	t_map;
typedef struct s_data
{
	t_map	*map;
}	t_data;

void	print_err(t_data *data, char *str, int errsig);

#endif
