/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:30:46 by geuyoon           #+#    #+#             */
/*   Updated: 2023/11/17 14:50:15 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_calloc(size_t cnt, size_t size);
void	free_gnl(t_gnl *gnl);
ssize_t	buf_read(int fd, t_gnl *gnl, size_t buf_size);
char	*str_resize(char *str, t_gnl *gnl);
size_t	gnl_strlen(char *str);

void	*gnl_calloc(size_t cnt, size_t size)
{
	unsigned char	*ret_add;
	size_t			cal_size;
	size_t			cpy_cnt;

	cal_size = cnt * size;
	if (cnt && size != cal_size / cnt)
		return (NULL);
	ret_add = (unsigned char *)malloc(cal_size);
	if (ret_add == NULL)
		return (NULL);
	cpy_cnt = 0;
	while (cpy_cnt < cal_size)
	{
		ret_add[cpy_cnt] = '\0';
		cpy_cnt++;
	}
	return ((void *)ret_add);
}

void	free_gnl(t_gnl *gnl)
{
	if (gnl->buffer != NULL)
	{
		free(gnl->buffer);
		gnl->buffer = NULL;
	}
	gnl->nxt_line = 0;
	gnl->buffer_len = 0;
	gnl->ret_len = 0;
}

ssize_t	buf_read(int fd, t_gnl *gnl, size_t buf_size)
{
	ssize_t	read_size;
	size_t	buf_cnt;

	buf_cnt = 0;
	while (buf_cnt < buf_size)
	{
		gnl->buffer[buf_cnt] = '\0';
		buf_cnt++;
	}
	read_size = read(fd, gnl->buffer, buf_size);
	if (read_size < 1)
	{
		free(gnl->buffer);
		gnl->buffer = NULL;
		gnl->buffer_len = 0;
	}
	else
		gnl->buffer_len = (size_t)read_size;
	gnl->nxt_line = 0;
	return (read_size);
}

char	*str_resize(char *str, t_gnl *gnl)
{
	char	*new_str;
	size_t	cpy_cnt;
	size_t	str_size;

	str_size = 2 * gnl->ret_len;
	if (str_size == 0)
		str_size = 1;
	new_str = (char *)gnl_calloc(str_size + 1, sizeof(char));
	if (new_str == NULL)
	{
		if (str != NULL)
			free(str);
		return (NULL);
	}
	cpy_cnt = 0;
	while (cpy_cnt < gnl->ret_len)
	{
		new_str[cpy_cnt] = str[cpy_cnt];
		cpy_cnt++;
	}
	if (str != NULL)
		free(str);
	gnl->ret_len = str_size;
	return (new_str);
}

size_t	gnl_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (str != NULL)
	{
		while (str[len] != '\0')
			len++;
	}
	return (len);
}
