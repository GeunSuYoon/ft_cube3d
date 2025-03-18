/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:58:14 by geuyoon           #+#    #+#             */
/*   Updated: 2023/11/17 18:43:54 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n);
size_t	itoa_helper(int n, int sign, char temp_val[]);

char	*ft_itoa(int n)
{
	char		temp_val[12];
	char		*ret_char;
	int			sign;
	size_t		size;
	size_t		cnt;

	sign = 1;
	if (n < 0)
		sign *= -1;
	size = 0;
	size = itoa_helper(n, sign, temp_val);
	if (sign < 0)
		temp_val[size++] = '-';
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

size_t	itoa_helper(int n, int sign, char temp_val[])
{
	size_t	size;

	size = 0;
	while (n / 10 != 0)
	{
		temp_val[size++] = '0' + (n % 10) * sign;
		n = n / 10;
	}
	temp_val[size++] = '0' + n * sign;
	return (size);
}
