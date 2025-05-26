/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_cube3d_color.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: geuyoon <geuyoon@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/20 02:13:29 by geuyoon		   #+#	#+#			 */
/*   Updated: 2025/04/08 10:06:38 by geuyoon		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/ft_cube3d_struct.h"

void	init_color_con(t_game *game, int map_fd);
void	color_setter(t_game *game, t_image_con *img_con, char **info);
int		init_color(t_game *game, char *rgb);
int		check_dot(char *rgb);

void	init_color_con(t_game *game, int map_fd)
{
	char	*tmp_line;
	char	**color_info;
	int		cnt;

	cnt = 0;
	while (cnt < 2)
	{
		tmp_line = read_line(map_fd);
		while (tmp_line && !ft_strlen(tmp_line))
		{
			free(tmp_line);
			tmp_line = read_line(map_fd);
		}
		if (!tmp_line)
			exit_err(game, 0, 0);
		color_info = ft_split(tmp_line, ' ');
		free(tmp_line);
		if (!color_info)
			exit_err(game, 0, 0);
		if (ft_strtdlen(color_info) != 2)
			exit_err(game, ETCOLINFO, 1);
		color_setter(game, game->image_con, color_info);
		free_td_str(color_info, ft_strtdlen(color_info));
		cnt++;
	}
}

void	color_setter(t_game *game, t_image_con *img_con, char **info)
{
	if (!ft_strcmp(info[0], MFC))
		img_con->fc = init_color(game, info[1]);
	else if (!ft_strcmp(info[0], MCC))
		img_con->cc = init_color(game, info[1]);
	else
	{
		free_td_str(info, 2);
		exit_err(game, ETCOLINFO, 1);
	}
}

int	init_color(t_game *game, char *rgb)
{
	char	**tdrgb;
	int		r;
	int		g;
	int		b;
	int		ret_val;

	if (check_dot(rgb) != 2)
		exit_err(game, ETCOLINFO, 1);
	tdrgb = ft_split(rgb, ',');
	if (!tdrgb)
		exit_err(game, 0, 0);
	if (ft_strtdlen(tdrgb) != 3)
		exit_err(game, ETCOLINFO, 1);
	r = ft_atoi(tdrgb[0]);
	g = ft_atoi(tdrgb[1]);
	b = ft_atoi(tdrgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_err(game, ETCOLINFO, 1);
	free_td_str(tdrgb, ft_strtdlen(tdrgb));
	ret_val = r << 16 | g << 8 | b;
	return (ret_val);
}

int	check_dot(char *rgb)
{
	int		ret_val;
	size_t	str_cnt;
	size_t	str_len;

	ret_val = 0;
	str_cnt = 0;
	str_len = ft_strlen(rgb);
	while (str_cnt < str_len)
	{
		if (rgb[str_cnt] == ',')
			ret_val++;
		str_cnt++;
	}
	return (ret_val);
}
