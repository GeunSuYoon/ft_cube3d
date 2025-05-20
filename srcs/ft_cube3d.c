/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_cube3d.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: geuyoon <geuyoon@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/19 00:28:05 by geuyoon		   #+#	#+#			 */
/*   Updated: 2025/04/09 07:50:40 by geuyoon		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

int	init_map_fd(char *name);

int	main(int argc, char **argv)
{
	t_game	*game;
	int		map_fd;

	if (argc != 2)
		exit_err(0, ETPROARG, ERR);
	map_fd = init_map_fd(argv[1]);
	game = init_game(map_fd);
	mlx_loop_hook(game->mlx_ctl->mlx, &cast_window, game);
	mlx_hook(game->mlx_ctl->win, 2, (1L << 0), &key_press, game);
	mlx_hook(game->mlx_ctl->win, 3, (1L << 1), &key_release, game);
	mlx_hook(game->mlx_ctl->win, 17, 0, &close_window, game);
	mlx_loop(game->mlx_ctl->mlx);
	game_free(game);
	exit(EXIT_SUCCESS);
}

int	init_map_fd(char *name)
{
	size_t	name_parse_len;
	char	**name_parse;
	size_t	name_len;
	int		fd;

	name_parse = ft_split(name, '/');
	name_parse_len = ft_strtdlen(name_parse);
	name_len = ft_strlen(name_parse[name_parse_len - 1]);
	if (name_len <= 4 || name_parse[name_parse_len - 1][0] == '.')
		exit_err(0, ETMAPNAME, ERR);
	if (ft_strcmp(name_parse[name_parse_len - 1] + name_len - 4, ".cub"))
		exit_err(0, ETMAPNAME, ERR);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		exit_err(0, 0, 0);
	free_td_str(name_parse, name_parse_len);
	return (fd);
}
