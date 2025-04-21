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

int	close_window(t_data *data);

int	close_window(t_data *data)
{
	data_free(data);
	printf("=========================\n");
	printf("== Player Close Window ==\n");
	printf("=========================\n");
	return (0);
}
