/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:03:00 by ocussy            #+#    #+#             */
/*   Updated: 2024/02/28 18:18:15 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_map(t_map *tab, int i)
{
	if (i == 1)
		ft_putstr_fd("La taille de la map n'est pas bonne\n", 1);
	if (i == 2)
		ft_putstr_fd("Il faut que la map soit entouree de murs (1)\n", 1);
	if (i == 3)
		ft_putstr_fd("La map doit contenir une unique sortie (E)\n", 1);
	if (i == 4)
		ft_putstr_fd("La map doit contenir une unique position de depart (P)\n",
			1);
	if (i == 5)
		ft_putstr_fd("La map doit contenir au moins un item a collecter (C)\n",
			1);
	if (i == 6)
		ft_putstr_fd("Il n'y a aucun chemin valable (0)\n", 1);
	ft_free_tab(tab);
	exit(1);
	return (0);
}

int	ft_size_map(void)
{
	int		size;
	int		fd;
	char	*line;

	size = 0;
	fd = open("map1.ber", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	if (line == NULL)
		ft_putstr_fd("Error", 2);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		size++;
	}
	free(line);
	close(fd);
	return (size);
}

char	*ft_get_map(int size_map)
{
	char	*map;
	char	*map_final;
	int		i;
	int		fd;

	i = 0;
	fd = open("map1.ber", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (0);
	}
	map_final = malloc(sizeof(char));
	map_final[0] = '\0';
	while (i < size_map)
	{
		map = get_next_line(fd);
		map_final = ft_strjoin(map_final, map);
		i++;
		free(map);
	}
	get_next_line(fd);
	close(fd);
	return (map_final);
}

int	ft_verif_map(t_map *map)
{
	if (!ft_verif_size_wall(map))
		ft_error_map(map, 1);
	if (!ft_verif_wall(map))
		ft_error_map(map, 2);
	if (!ft_verif_char(map->map, 'E'))
		ft_error_map(map, 3);
	if (!ft_verif_char(map->map, 'P'))
		ft_error_map(map, 4);
	if (!ft_verif_char(map->map, 'C'))
		ft_error_map(map, 5);
	if (!ft_verif_path(map))
		ft_error_map(map, 6);
	return (0);
}

int	ft_map(void)
{
	char	*join_map;
	t_map	*map;

	map = ft_init();
	map->size_map = ft_size_map();
	join_map = ft_get_map(map->size_map);
	map->map = ft_split(join_map, '\n');
	ft_verif_map(map);
	return (0);
}
