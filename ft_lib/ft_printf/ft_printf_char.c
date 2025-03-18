/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:37:14 by geuyoon           #+#    #+#             */
/*   Updated: 2024/01/07 23:41:38 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_printf_c(va_list arg);
ssize_t	ft_printf_s(va_list arg);
ssize_t	ft_printf_pers(void);

ssize_t	ft_printf_c(va_list arg)
{
	int				args_int;
	unsigned char	print_char;
	ssize_t			write_val;

	args_int = (char)va_arg(arg, int);
	print_char = (unsigned char)args_int;
	write_val = write(1, &print_char, 1);
	return (write_val);
}

ssize_t	ft_printf_s(va_list arg)
{
	const char	*args_str;
	char		*null_str;
	ssize_t		write_val;

	args_str = va_arg(arg, const char *);
	if (args_str == NULL)
	{
		null_str = ft_strdup("(null)");
		if (null_str == 0)
			return (-1);
		write_val = write(1, null_str, ft_strlen(null_str));
		free(null_str);
		null_str = 0;
	}
	else
		write_val = write(1, args_str, ft_strlen(args_str));
	return (write_val);
}

ssize_t	ft_printf_pers(void)
{
	char	pers;
	ssize_t	write_val;

	pers = '%';
	write_val = write(1, &pers, 1);
	return (write_val);
}
