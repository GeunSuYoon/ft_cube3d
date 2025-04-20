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

#include "ft_cube3d.h"

void		key_ctl(t_data *data);
static int	key_press(int keycode, t_data *data);
static void	key_angle(int keycode, t_data *data);
static void	key_move(int keycode, t_data *data);

void	key_ctl(t_data *data)
{
	mlx_key_hook(data->mlx_ctl->win, &key_press, data);
}

static int	key_press(int keycode, t_data *data)
{
	if (keycode == KESC)
		close_window(data);
	if (keycode == KLEFT || keycode == KRIGHT)
		key_angle(keycode, data);
	else if (keycode == KW || keycode == KA || keycode == KS || keycode == KD)
		key_move(keycode, data);
	return (0);
}
