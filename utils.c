/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:57:11 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/11 11:56:59 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*ft_init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map != NULL)
	{
		map->len_map = 0;
		map->map = NULL;
		map->size_map = 0;
		map->filled = NULL;
	}
	return (map);
}

int	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

int	ft_free_tab(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
	return (0);
}

char	**ft_copy_array(t_map *map)
{
	char	**filled;
	int		i;

	i = 0;
	filled = malloc(sizeof(char *) * (map->size_map + 1));
	if (!filled)
		return (0);
	while (map->map[i])
	{
		filled[i] = malloc(sizeof(char) * (map->len_map + 1));
		ft_strlcpy(filled[i], map->map[i], map->len_map + 1);
		i++;
	}
	filled[i] = NULL;
	return (filled);
}
