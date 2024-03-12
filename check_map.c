/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:03:00 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/12 16:32:18 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verif_map(t_map *map)
{
	if (!ft_verif_size_wall(map))
		ft_error_map(map, 1);
	if (!ft_verif_wall(map))
		ft_error_map(map, 2);
	if (!ft_verif_char(map, 'E'))
		ft_error_map(map, 3);
	if (!ft_verif_char(map, 'P'))
		ft_error_map(map, 4);
	if (!ft_verif_char(map, 'C'))
		ft_error_map(map, 5);
	if (!ft_verif_path(map))
		ft_error_map(map, 6);
	return (0);
}

int	ft_verif_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	len = len - 4;
	if (ft_strncmp(file + len, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	ft_verif_str(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

t_map	*ft_map(char *file)
{
	char	*join_map;
	t_map	*map;

	if (ft_verif_file(file) == 0)
		return (0);
	map = ft_init();
	map->size_map = ft_size_map(file);
	if (map->size_map == 0)
	{
		free(map);
		return (0);
	}
	join_map = ft_get_map(file, map->size_map);
	if (ft_verif_str(join_map) == 0 || join_map[0] != '1')
	{
		free(join_map);
		free(map);
		exit(1);
	}
	map->map = ft_split(join_map, '\n');
	free(join_map);
	ft_verif_map(map);
	return (map);
}
