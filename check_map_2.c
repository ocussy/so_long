/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:20:49 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/11 12:23:39 by ocussy           ###   ########.fr       */
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

int	ft_size_map(char *file)
{
	int		size;
	int		fd;
	char	*line;

	size = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (0);
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

char	*ft_get_map(char *file, int size_map)
{
	char	*map;
	char	*map_final;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
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
