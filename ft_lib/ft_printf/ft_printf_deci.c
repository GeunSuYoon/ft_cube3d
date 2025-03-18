/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_deci.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:38:01 by geuyoon           #+#    #+#             */
/*   Updated: 2024/01/07 23:40:54 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t			ft_printf_d(va_list arg);
ssize_t			ft_printf_i(va_list arg);
ssize_t			ft_printf_u(va_list arg);
static char		*ft_uitoa(unsigned int n);
static size_t	uitoa_helper(unsigned int n, char temp_val[]);

ssize_t	ft_printf_d(va_list arg)
{
	int		arg_int;
	char	*print_int;
	ssize_t	write_val;
	size_t	str_len;

	arg_int = va_arg(arg, int);
	print_int = ft_itoa(arg_int);
	if (print_int == 0)
		return (-1);
	str_len = ft_strlen(print_int);
	write_val = write(1, print_int, str_len);
	free(print_int);
	print_int = 0;
	return (write_val);
}

ssize_t	ft_printf_i(va_list arg)
{
	int		arg_int;
	char	*print_int;
	ssize_t	write_val;
	size_t	str_len;

	arg_int = va_arg(arg, int);
	print_int = ft_itoa(arg_int);
	if (print_int == 0)
		return (-1);
	str_len = ft_strlen(print_int);
	write_val = write(1, print_int, str_len);
	free(print_int);
	print_int = 0;
	return (write_val);
}

ssize_t	ft_printf_u(va_list arg)
{
	unsigned int	arg_int;
	char			*print_int;
	ssize_t			write_val;
	size_t			str_len;

	arg_int = va_arg(arg, unsigned int);
	print_int = ft_uitoa(arg_int);
	if (print_int == 0)
		return (-1);
	str_len = ft_strlen(print_int);
	write_val = write(1, print_int, str_len);
	free(print_int);
	print_int = 0;
	return (write_val);
}

static char	*ft_uitoa(unsigned int n)
{
	char		temp_val[12];
	char		*ret_char;
	size_t		size;
	size_t		cnt;

	size = uitoa_helper(n, temp_val);
	ret_char = (char *)ft_calloc(size + 1, sizeof(char));
	if (ret_char == NULL)
		return (NULL);
	cnt = 0;
	while (cnt < size)
	{
		ret_char[cnt] = temp_val[size - cnt - 1];
		cnt++;
	}
	return (ret_char);
}

static size_t	uitoa_helper(unsigned int n, char temp_val[])
{
	size_t	size;

	size = 0;
	while (n / 10 != 0)
	{
		temp_val[size++] = '0' + (n % 10);
		n = n / 10;
	}
	temp_val[size++] = '0' + n;
	return (size);
}
