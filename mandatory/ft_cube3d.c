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

#include "ft_cube3d.h"

int	init_map_fd(char *name);

int	main(int argc, char **argv)
{
	t_game	*game;
	int		map_fd;

	if (argc != 2)
		exit_err(0, ETPROARG, ERR);
	map_fd = init_map_fd(argv[1]);
	game = init_game(map_fd);
	cast_window(game);
	key_ctl(game);
	mlx_loop(game->mlx_ctl->mlx);
	game_free(game);
	exit(EXIT_SUCCESS);
}

int	init_map_fd(char *name)
{
	int		fd;
	size_t	name_len;

	name_len = ft_strlen(name);
	if (name_len < 4)
		exit_err(0, ETMAPNAME, ERR);
	if (ft_strcmp(name + name_len - 4, ".cub"))
		exit_err(0, ETMAPNAME, ERR);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		exit_err(0, 0, 0);
	return (fd);
}
