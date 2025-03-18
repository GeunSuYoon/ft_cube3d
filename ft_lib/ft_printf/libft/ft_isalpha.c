/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:17:10 by geuyoon           #+#    #+#             */
/*   Updated: 2023/10/08 16:17:14 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c);

int	ft_isalpha(int c)
{
	if (c >= (int) 'A' && c <= (int) 'Z')
		return (1);
	if (c >= (int) 'a' && c <= (int) 'z')
		return (1);
	return (0);
}
