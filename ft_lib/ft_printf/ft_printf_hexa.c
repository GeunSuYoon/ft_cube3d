/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:50:13 by geuyoon           #+#    #+#             */
/*   Updated: 2024/01/07 23:40:13 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t			ft_printf_x(va_list arg);
ssize_t			ft_printf_ux(va_list arg);
ssize_t			ft_printf_p(va_list arg);
static char		*ft_hex_str(char *str, size_t len,
					unsigned long long hex, int is_low);
static size_t	ft_hex_len(unsigned long long print_int);

ssize_t	ft_printf_x(va_list arg)
{
	unsigned int	arg_ll;
	size_t			hex_len;
	char			*print_hex;
	ssize_t			write_val;

	arg_ll = va_arg(arg, unsigned int);
	hex_len = ft_hex_len((unsigned long long)arg_ll);
	print_hex = (char *)ft_calloc(hex_len + 1, sizeof(char));
	if (print_hex == NULL)
		return (-1);
	print_hex = ft_hex_str(print_hex, hex_len,
			(unsigned long long)arg_ll, 1);
	write_val = write(1, print_hex, ft_strlen(print_hex));
	free(print_hex);
	print_hex = 0;
	return (write_val);
}

ssize_t	ft_printf_ux(va_list arg)
{
	unsigned int	arg_ll;
	size_t			hex_len;
	char			*print_hex;
	ssize_t			write_val;

	arg_ll = va_arg(arg, unsigned int);
	hex_len = ft_hex_len((unsigned long long)arg_ll);
	print_hex = (char *)ft_calloc(hex_len + 1, sizeof(char));
	if (print_hex == NULL)
		return (-1);
	print_hex = ft_hex_str(print_hex, hex_len,
			(unsigned long long)arg_ll, 2);
	write_val = write(1, print_hex, ft_strlen(print_hex));
	free(print_hex);
	print_hex = 0;
	return (write_val);
}

ssize_t	ft_printf_p(va_list arg)
{
	void				*arg_ptr;
	unsigned long long	arg_ull;
	size_t				hex_len;
	char				*print_hex;
	ssize_t				write_val;

	arg_ptr = va_arg(arg, void *);
	arg_ull = (unsigned long long)arg_ptr;
	hex_len = ft_hex_len(arg_ull);
	print_hex = (char *)ft_calloc(hex_len + 3, sizeof(char));
	if (print_hex == NULL)
		return (-1);
	print_hex[0] = '0';
	print_hex[1] = 'x';
	print_hex = ft_hex_str(print_hex + 2, hex_len,
			arg_ull, 1) - 2;
	write_val = write(1, print_hex, ft_strlen(print_hex));
	free(print_hex);
	print_hex = 0;
	return (write_val);
}

static char	*ft_hex_str(char *str, size_t len,
				unsigned long long hex, int is_low)
{
	size_t	hex_cnt;

	hex_cnt = 0;
	while (hex_cnt < len)
	{
		if (is_low == 1)
			str[len - 1 - hex_cnt] = "0123456789abcdef"[hex % 16];
		else
			str[len - 1 - hex_cnt] = "0123456789ABCDEF"[hex % 16];
		hex /= 16;
		hex_cnt++;
	}
	return (str);
}

static size_t	ft_hex_len(unsigned long long print_int)
{
	size_t	hex_len;

	hex_len = 1;
	while (print_int / 16 != 0)
	{
		hex_len++;
		print_int /= 16;
	}
	return (hex_len);
}
