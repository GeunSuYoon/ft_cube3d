/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:28:05 by geuyoon           #+#    #+#             */
/*   Updated: 2025/03/29 17:19:31 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUBE3D_H
# define FT_CUBE3D_H

# define EMPTY ' '
# define SPACE '0'
# define WALL '1'
# define PNORTH 'N'
# define PSOUTH 'S'
# define PWEST 'W'
# define PEAST 'E'
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
# include <stdlib.h>
# include <fcntl.h>

// position structure
typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;
typedef struct s_map
{
	char	**map_data;
	size_t	map_height;
}	t_map;
typedef struct s_image
{
	void	*img_ptr;
	int		height;
	int		width;
}	t_image;
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_pos	start_pos;
}	t_mlx;
typedef struct s_data
{
	t_map	*map;
	t_image	*no;
	t_image	*so;
	t_image	*we;
	t_image	*ea;
	t_color	*fc;
	t_color	*cc;
	t_mlx	*mlx_ctl;
}	t_data;

void	parse_color(t_data *data, int map_fd);
void	parse_image(t_data *data, int map_fd);

size_t	ft_strtdlen(char **tdstr);
void	free_td_str(char **str, size_t str_height);
void	exit_err(t_data *data, char *str, int errsig);
void	print_err(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif
