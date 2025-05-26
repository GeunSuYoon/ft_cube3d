/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_cube3d_key.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: geuyoon <geuyoon@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/18 10:32:24 by geuyoon		   #+#	#+#			 */
/*   Updated: 2025/04/20 08:22:09 by geuyoon		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes_bonus/ft_cube3d_bonus.h"

int			key_press(int keycode, t_game *game);
static void	key_press_player(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);
static void	key_release_player(int keycode, t_game *game);

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_window(game);
	if (keycode == XK_Left || keycode == XK_Right || \
		keycode == XK_W || keycode == XK_A || \
		keycode == XK_S || keycode == XK_D || \
		keycode == XK_w || keycode == XK_a || \
		keycode == XK_s || keycode == XK_d || \
		keycode == XK_Shift_L)
		key_press_player(keycode, game);
	return (0);
}

static void	key_press_player(int keycode, t_game *game)
{
	if (keycode == XK_Left)
		game->rot[0] = 1;
	if (keycode == XK_Right)
		game->rot[1] = 1;
	if (keycode == XK_W || keycode == XK_w)
		game->move[0] = 1;
	if (keycode == XK_A || keycode == XK_a)
		game->move[1] = 1;
	if (keycode == XK_S || keycode == XK_s)
		game->move[2] = 1;
	if (keycode == XK_D || keycode == XK_d)
		game->move[3] = 1;
	if (keycode == XK_Shift_L)
		game->run_flag = 1;
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_Left || keycode == XK_Right || \
		keycode == XK_W || keycode == XK_A || \
		keycode == XK_S || keycode == XK_D || \
		keycode == XK_w || keycode == XK_a || \
		keycode == XK_s || keycode == XK_d || \
		keycode == XK_Shift_L)
		key_release_player(keycode, game);
	return (0);
}

static void	key_release_player(int keycode, t_game *game)
{
	if (keycode == XK_Left)
		game->rot[0] = 0;
	if (keycode == XK_Right)
		game->rot[1] = 0;
	if (keycode == XK_W || keycode == XK_w)
		game->move[0] = 0;
	if (keycode == XK_A || keycode == XK_a)
		game->move[1] = 0;
	if (keycode == XK_S || keycode == XK_s)
		game->move[2] = 0;
	if (keycode == XK_D || keycode == XK_d)
		game->move[3] = 0;
	if (keycode == XK_Shift_L)
		game->run_flag = 0;
}
