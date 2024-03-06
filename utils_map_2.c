/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:08:24 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/01 10:53:05 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(t_map *map, int x, size_t y)
{
	if (x < 0 || x >= map->size_map || y >= map->len_map)
		return ;
	if (map->filled[x][y] == '1')
		return ;
	else
		map->filled[x][y] = '1';
	fill(map, x + 1, y);
	fill(map, x - 1, y);
	fill(map, x, y + 1);
	fill(map, x, y - 1);
}

int	ft_check_filled(char **filled)
{
	int	i;
	int	j;

	i = 0;
	while (filled[i])
	{
		j = 0;
		while (filled[i][j])
		{
			if (filled[i][j] == 'C' || filled[i][j] == 'P'
				|| filled[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_verif_path(t_map *map)
{
	int		x;
	size_t	y;

	x = 0;
	map->filled = ft_copy_array(map);
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y])
		{
			if (map->map[x][y] == 'P')
				fill(map, x, y);
			y++;
		}
		x++;
	}
	if (!ft_check_filled(map->filled))
	{
		ft_free_array(map->filled);
		return (0);
	}
	ft_free_array(map->filled);
	return (1);
}
