/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:30:57 by geuyoon           #+#    #+#             */
/*   Updated: 2023/11/17 16:28:11 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl
{
	char	*buffer;
	size_t	nxt_line;
	size_t	buffer_len;
	size_t	ret_len;
}	t_gnl;
char	*get_next_line(int fd);
char	*find_line(int fd, t_gnl *gnl, ssize_t *read_size, size_t buf_size);
char	*cpy_line(t_gnl *gnl, char *str, size_t end);
char	*fit_str(t_gnl *gnl, char *str);
char	*free_str_gnl(char *str, t_gnl *gnl);
void	*gnl_calloc(size_t cnt, size_t size);
void	free_gnl(t_gnl *gnl);
ssize_t	buf_read(int fd, t_gnl *gnl, size_t buf_size);
char	*str_resize(char *str, t_gnl *gnl);
size_t	gnl_strlen(char *str);

#endif
