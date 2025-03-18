/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:15:21 by geuyoon           #+#    #+#             */
/*   Updated: 2024/01/08 08:47:52 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *str, ...);
static int		ft_printf_write(const char *str, va_list args);
static ssize_t	ft_varg_data(const char str, va_list arg);

int	ft_printf(const char *str, ...)
{
	int		ret_int;
	va_list	args;

	va_start(args, str);
	ret_int = ft_printf_write(str, args);
	va_end(args);
	return (ret_int);
}

static int	ft_printf_write(const char *str, va_list args)
{
	ssize_t	ret_int;
	ssize_t	write_val;

	ret_int = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			write_val = ft_varg_data(*str, args);
		}
		else
			write_val = write(1, str, 1);
		if (write_val == -1)
			return (-1);
		str++;
		ret_int += write_val;
	}
	return ((int)ret_int);
}

static ssize_t	ft_varg_data(const char str, va_list arg)
{
	if (str == 'c')
		return (ft_printf_c(arg));
	if (str == 's')
		return (ft_printf_s(arg));
	if (str == 'p')
		return (ft_printf_p(arg));
	if (str == 'd')
		return (ft_printf_d(arg));
	if (str == 'i')
		return (ft_printf_i(arg));
	if (str == 'u')
		return (ft_printf_u(arg));
	if (str == 'x')
		return (ft_printf_x(arg));
	if (str == 'X')
		return (ft_printf_ux(arg));
	if (str == '%')
		return (ft_printf_pers());
	return (-1);
}
