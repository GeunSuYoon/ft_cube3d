/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:11:12 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/13 16:25:08 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	char	val;
	int		sign;

	sign = 1;
	if (n < 0)
		sign *= -1;
	if (n / 10 == 0)
	{
		if (sign == -1)
			write(fd, "-", 1);
		val = '0' + sign * n;
		write(fd, &val, 1);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	val = '0' + sign * (n % 10);
	write(fd, &val, 1);
}
