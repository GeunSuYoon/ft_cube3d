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

void	cast_window(t_data *data);
int		close_window(t_data *data);

void	cast_window(t_data *data)
{
	if (!data->rcast->window_img || !data->rcast->window_img->img_data)
		exit_err(data, "Invalid window image", 1);
	casting_loop(data, data->rcast, data->player);
	if (mlx_put_image_to_window(data->mlx_ctl->mlx, data->mlx_ctl->win, \
		data->rcast->window_img, 0, 0) < 0)
		exit_err(data, 0, 0);
}

int	close_window(t_data *data)
{
	data_free(data);
	printf("=========================\n");
	printf("== Player Close Window ==\n");
	printf("=========================\n");
	return (0);
}
