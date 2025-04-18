/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:29:51 by geuyoon           #+#    #+#             */
/*   Updated: 2025/04/18 09:08:19 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube3d.h"

void	test_print_round_checker(int **round_checker, t_map *map);
void	test_print_mapdata(t_map *map);

// test code
void	test_print_round_checker(int **round_checker, t_map *map)
{
	for (size_t i = 0; i < map->map_height; i++)
	{
		for (size_t j = 0; j < map->map_width - 1; j++)
		printf("%d", round_checker[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

void	test_print_mapdata(t_map *map)
{
	for (size_t i = 0; i < map->map_height; i++)
	{
		size_t j = 0;
		while (map->map_data[i][j])
		{
			printf("%c", map->map_data[i][j]);
			j++;
		}
		printf("\n");
	}
	printf("\n\n");
}
