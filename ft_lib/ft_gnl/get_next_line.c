/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:30:08 by geuyoon           #+#    #+#             */
/*   Updated: 2023/11/20 14:48:08 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
char	*find_line(int fd, t_gnl *gnl, ssize_t *read_size, size_t buf_size);
char	*cpy_line(t_gnl *gnl, char *str, size_t end);
char	*fit_str(t_gnl *gnl, char *str);
char	*free_str_gnl(char *str, t_gnl *gnl);

char	*get_next_line(int fd)
{
	static t_gnl	gnl;
	size_t			buf_size;
	ssize_t			read_size;
	char			*ret_str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf_size = BUFFER_SIZE;
	read_size = (ssize_t)gnl.buffer_len;
	if (gnl.buffer == NULL)
	{
		gnl.buffer = (char *)gnl_calloc(buf_size, sizeof(char));
		if (gnl.buffer == NULL)
			return (NULL);
		read_size = buf_read(fd, &gnl, buf_size);
	}
	ret_str = find_line(fd, &gnl, &read_size, buf_size);
	ret_str = fit_str(&gnl, ret_str);
	if (read_size == -1)
		ret_str = free_str_gnl(ret_str, &gnl);
	if (gnl.nxt_line == gnl.buffer_len)
		free_gnl(&gnl);
	return (ret_str);
}

char	*find_line(int fd, t_gnl *gnl, ssize_t *read_size, size_t buf_size)
{
	char	*ret_str;
	size_t	buf_cnt;

	ret_str = NULL;
	buf_cnt = gnl->nxt_line;
	while (*read_size > 0)
	{
		if (gnl->buffer_len && buf_cnt >= gnl->buffer_len)
		{
			ret_str = cpy_line(gnl, ret_str, buf_cnt);
			if (ret_str == NULL)
				return (NULL);
			*read_size = buf_read(fd, gnl, buf_size);
			buf_cnt = 0;
		}
		if (*read_size > 0 && (gnl->buffer[buf_cnt] == '\n'
				|| gnl->buffer[buf_cnt] == '\0'))
		{
			ret_str = cpy_line(gnl, ret_str, buf_cnt);
			return (ret_str);
		}
		buf_cnt++;
	}
	free_gnl(gnl);
	return (ret_str);
}

char	*cpy_line(t_gnl *gnl, char *str, size_t end)
{
	size_t	cpy_cnt;
	size_t	str_len;

	if (end < gnl->buffer_len && gnl->buffer[end] == '\n')
		end++;
	cpy_cnt = 0;
	str_len = gnl_strlen(str);
	while (cpy_cnt < end - gnl->nxt_line)
	{
		if (cpy_cnt + str_len == gnl->ret_len)
		{
			str = str_resize(str, gnl);
			if (str == NULL)
				return (NULL);
		}
		str[str_len + cpy_cnt] = gnl->buffer[cpy_cnt + gnl->nxt_line];
		cpy_cnt++;
	}
	gnl->nxt_line = end;
	return (str);
}

char	*fit_str(t_gnl *gnl, char *str)
{
	char	*new_str;
	size_t	str_len;
	size_t	cpy_cnt;

	if (str == NULL)
	{
		free_gnl(gnl);
		return (NULL);
	}
	str_len = gnl_strlen(str);
	new_str = (char *)gnl_calloc(str_len + 1, sizeof(char));
	if (new_str == NULL)
	{
		free_str_gnl(str, gnl);
		return (NULL);
	}
	cpy_cnt = 0;
	while (cpy_cnt < str_len)
	{
		new_str[cpy_cnt] = str[cpy_cnt];
		cpy_cnt++;
	}
	free(str);
	gnl->ret_len = 0;
	return (new_str);
}

char	*free_str_gnl(char *str, t_gnl *gnl)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	free_gnl(gnl);
	return (NULL);
}
