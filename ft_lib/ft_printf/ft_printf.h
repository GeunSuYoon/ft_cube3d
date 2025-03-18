/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:15:25 by geuyoon           #+#    #+#             */
/*   Updated: 2024/02/17 18:29:39 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
ssize_t	ft_printf_c(va_list arg);
ssize_t	ft_printf_s(va_list arg);
ssize_t	ft_printf_pers(void);
ssize_t	ft_printf_x(va_list arg);
ssize_t	ft_printf_ux(va_list arg);
ssize_t	ft_printf_p(va_list arg);
ssize_t	ft_printf_d(va_list arg);
ssize_t	ft_printf_i(va_list arg);
ssize_t	ft_printf_u(va_list arg);

#endif
