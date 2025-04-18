/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:33:04 by geuyoon           #+#    #+#             */
/*   Updated: 2025/04/18 08:56:11 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

void    **realloc_td_ptr(void **ptr, size_t data_size, size_t data_len, size_t prev_len);
void	free_td_str(char **ptr, size_t height);
void	free_td_int(int **ptr, size_t height);
char	*ft_strndup(char *str, size_t len);

void    **realloc_td_ptr(void **ptr, size_t data_size, size_t data_len, size_t prev_len)
{
    void	*new_ptr;
	size_t	copy_size;

	new_ptr = ft_calloc(data_len, data_size);
	if (new_ptr == 0)
		return (0);
	copy_size = prev_len * data_size;
	if (copy_size > data_len * data_size)
		copy_size = data_len * data_size;
	new_ptr = ft_memmove(new_ptr, ptr, prev_len * data_size);
	free(ptr);
	ptr = 0;
	return (new_ptr);
}

void	free_td_str(char **ptr, size_t height)
{
	size_t	height_cnt;

	height_cnt = 0;
	while (height_cnt < height)
	{
		free(ptr[height_cnt]);
		ptr[height_cnt] = 0;
		height_cnt++;
	}
	free(ptr);
	ptr = 0;
}

void	free_td_int(int **ptr, size_t height)
{
	size_t	height_cnt;

	height_cnt = 0;
	while (height_cnt < height)
	{
		free(ptr[height_cnt]);
		ptr[height_cnt] = 0;
		height_cnt++;
	}
	free(ptr);
	ptr = 0;
}

char	*ft_strndup(char *str, size_t len)
{
	char	*ret_str;
	size_t	cnt;

	ret_str = ft_calloc(len + 1, sizeof(char));
	if (!ret_str)
		return (0);
	cnt = 0;
	while (str[cnt] && cnt < len)
	{
		ret_str[cnt] = str[cnt];
		cnt++;
	}
	return (ret_str);
}
