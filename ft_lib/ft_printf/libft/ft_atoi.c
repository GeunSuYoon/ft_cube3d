/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:16:38 by geuyoon           #+#    #+#             */
/*   Updated: 2023/11/25 18:41:02 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str);

int	ft_atoi(const char *str)
{
	long long	ret_val;
	int			sign;

	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	ret_val = 0;
	while (ft_isdigit(*str))
	{
		ret_val *= 10;
		ret_val += *str - '0';
		str++;
	}
	ret_val *= sign;
	return (ret_val);
}
