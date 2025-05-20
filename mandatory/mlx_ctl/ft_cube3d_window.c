/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_cube3d_window.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: geuyoon <geuyoon@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/18 10:30:54 by geuyoon		   #+#	#+#			 */
/*   Updated: 2025/04/18 10:34:13 by geuyoon		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../ft_cube3d.h"

void	cast_window(t_game *game);
int		close_window(t_game *game);

void	cast_window(t_game *game)
{
	if (!game->rcast->window_img || !game->rcast->window_img->img_ptr || \
		!game->rcast->window_img->img_data)
		exit_err(game, "Invalid window image", 1);
	if (mlx_clear_window(game->mlx_ctl->mlx, game->mlx_ctl->win) < 0)
		exit_err(game, 0, 0);
	// minimap(game);
	casting_loop(game, game->rcast, game->player);
	if (mlx_put_image_to_window(game->mlx_ctl->mlx, game->mlx_ctl->win, \
		game->rcast->window_img->img_ptr, 0, 0) < 0)
		exit_err(game, 0, 0);
}

int	close_window(t_game *game)
{
	game_free(game);
	printf("=========================\n");
	printf("== Player Close Window ==\n");
	printf("=========================\n");
	return (0);
}
