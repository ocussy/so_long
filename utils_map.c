/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:07:12 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/01 16:05:48 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verif_wall_verti(char **map, size_t len, int size_map)
{
	int	i;

	i = 0;
	while (i <= size_map)
	{
		if (map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i <= size_map)
	{
		if (map[i][len] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_verif_wall_horiz(char **map, int size_map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[size_map][i])
	{
		if (map[size_map][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_verif_wall(t_map *map)
{
	if (ft_verif_wall_verti(map->map, map->len_map - 1, map->size_map - 1) == 0)
		return (0);
	if (ft_verif_wall_horiz(map->map, map->size_map - 1) == 0)
		return (0);
	return (1);
}

int	ft_verif_char(t_map *map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if (count != 1 && (c == 'P' || c == 'E'))
		return (0);
	if (count == 0 && c == 'C')
		return (0);
	if (c == 'C')
		map->count = count;
	return (1);
}

int	ft_verif_size_wall(t_map *map)
{
	int	i;

	i = 0;
	map->len_map = ft_strlen(map->map[i]);
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != map->len_map)
			return (0);
		i++;
	}
	return (1);
}
