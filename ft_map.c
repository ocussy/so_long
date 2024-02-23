/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:45:07 by ocussy            #+#    #+#             */
/*   Updated: 2024/02/23 12:40:27 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(int fd)
{
	write(2, "Error", 6);
	exit(fd);
	return (0);
}

int	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int	ft_error_map(char **tab, int i)
{
	if (i == 1)
		ft_putstr_fd("La taille de la map n'est pas bonne\n", 1);
	ft_free_tab(tab);
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
		ft_error(fd);
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
	char	*tmp;

	i = 0;
	fd = open("map1.ber", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (0);
	}
	map_final = "";
	while (i < size_map)
	{
		map = get_next_line(fd);
		tmp = map_final;
		map_final = ft_strjoin(map_final, map);
		if (ft_strlen(tmp) != 0)
			free(tmp);
		free(map);
		printf("La ligne %d est %s\n", i, map_final);
		i++;
	}
	free(map);
	close(fd);
	return (map_final);
}

char	*ft_make_tab(char **map)
{
	char	*str_final;
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (map[i])
	{
		len += ft_strlen(map[i]);
		i++;
	}
	i = 0;
	str_final = NULL;
	while (map[i])
	{
		str_final = ft_strjoin(str_final, map[i]);
		printf("La ligne finale est %s", str_final);
		i++;
	}
	return (str_final);
}

// int	ft_verif_wall(char **map)
// {
// 	int	i;
// 	int	j;
// }

// int	verif_char_multiple(char **map, char c)
// {
// 	int	i;
// 	int	j;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == c)
// 				count++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (count >= 1)
// 		return (0);
// 	return (1);
// }

// int	ft_verif_char(char **map, char c)
// {
// 	if (c == 'C')
// 		ft_verif_char_multiple(map, c);
// 	else
// 		ft_verif_char_simple(map, c);
// }
// }

int	ft_verif_size_wall(char **map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		printf("Len : %ld\n", ft_strlen(map[i]));
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	ft_verif_map(char **map)
{
	if (!ft_verif_size_wall(map))
		ft_error_map(map, 1);
	// if (ft_verif_wall(map) || ft_verif_char(map, 'E')
	// || ft_verif_char(map, 'P')
	// 	|| ft_verif_char(map, 'C'))
	// 	return (1);
	return (0);
}

int	ft_map(void)
{
	int		j;
	int		size_map;
	char	*map;
	char	**map_final;

	j = 0;
	// enlever les backslash end
	size_map = ft_size_map();
	printf("La taille de la map est de %d\n", size_map);
	if (size_map > 2)
	{
		map = ft_get_map(size_map);
		map_final = ft_split(map, '\n');
		free(map);
		while (map_final[j])
		{
			printf("La case %d du tableau est %s\n", j, map_final[j]);
			j++;
		}
		ft_verif_map(map_final);
	}
	return (0);
}
