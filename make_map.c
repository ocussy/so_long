/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:10:16 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/06 12:20:20 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_image(t_mlx *mlx)
{
	mlx->grass = mlx_xpm_file_to_image(mlx->ptr, "Images/grass.xpm",
			&mlx->width, &mlx->length);
	if (!mlx->grass)
		return (0);
	mlx->tree = mlx_xpm_file_to_image(mlx->ptr, "Images/tree_2.xpm",
			&mlx->width, &mlx->length);
	if (!mlx->tree)
		return (0);
	mlx->tree_apple = mlx_xpm_file_to_image(mlx->ptr, "Images/tree.xpm",
			&mlx->width, &mlx->length);
	if (!mlx->tree_apple)
		return (0);
	mlx->rabbit_down = mlx_xpm_file_to_image(mlx->ptr,
			"Images/lapinou_back.xpm", &mlx->width, &mlx->length);
	if (!mlx->rabbit_down)
		return (0);
	mlx->bed = mlx_xpm_file_to_image(mlx->ptr, "Images/bed.xpm", &mlx->width,
			&mlx->length);
	if (!mlx->bed)
		return (0);
	mlx->apple = mlx_xpm_file_to_image(mlx->ptr, "Images/collectible.xpm",
			&mlx->width, &mlx->length);
	if (!mlx->apple)
		return (0);
	mlx->rabbit_up = mlx_xpm_file_to_image(mlx->ptr, "Images/lapinou.xpm",
			&mlx->width, &mlx->length);
	if (!mlx->rabbit_up)
		return (0);
	mlx->rabbit_left = mlx_xpm_file_to_image(mlx->ptr,
			"Images/lapinou_left.xpm", &mlx->width, &mlx->length);
	if (!mlx->rabbit_left)
		return (0);
	mlx->rabbit_right = mlx_xpm_file_to_image(mlx->ptr,
			"Images/lapinou_right.xpm", &mlx->width, &mlx->length);
	if (!mlx->rabbit_right)
		return (0);
	return (1);
}

void	ft_win(t_mlx *mlx)
{
	ft_putstr_fd("Une bonne nuit de repos !", 1);
	close_window(mlx);
}

void	ft_get_walls(t_mlx *mlx)
{
	size_t	x;
	int		y;
	int		i;
	int		j;

	x = 0;
	y = 0;
	j = 0;
	while (x < mlx->x)
	{
		y = 0;
		i = 0;
		while (y < mlx->y)
		{
			if (mlx->map->map[i][j] == '1')
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->tree_apple, x,
					y);
			y += 50;
			i++;
		}
		x += 50;
		j++;
	}
}

void	ft_get_interior(t_mlx *mlx)
{
	size_t	x;
	int		y;
	int		i;
	int		j;

	x = 50;
	y = 50;
	j = 1;
	while (x < mlx->x - 50)
	{
		y = 50;
		i = 1;
		while (y < mlx->y - 50)
		{
			if (mlx->map->map[i][j] == '1')
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->tree, x, y);
			if (mlx->map->map[i][j] == '0')
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->grass, x, y);
			if (mlx->map->map[i][j] == 'P')
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_down, x,
					y);
			if (mlx->map->map[i][j] == 'C')
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->apple, x, y);
			if (mlx->map->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->bed, x, y);
			y += 50;
			i++;
		}
		x += 50;
		j++;
	}
}

void	ft_get_background(t_mlx *mlx)
{
	ft_get_walls(mlx);
	ft_get_interior(mlx);
}

void	ft_move_up(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_up, (mlx->j * 50),
		(mlx->i * 50));
	if (mlx->map->map[mlx->i][mlx->j] == 'C')
	{
		mlx->map->count--;
		mlx->map->map[mlx->i][mlx->j] = '0';
	}
	if (mlx->map->map[mlx->i - 1][mlx->j] && mlx->map->map[mlx->i
		- 1][mlx->j] != '1')
	{
		if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count != 0)
		{
			ft_putstr_fd("Tu n'as pas encore recolté toutes les pommes !\n", 1);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->bed, (mlx->j * 50),
				(mlx->i * 50));
		}
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->grass, (mlx->j
					* 50), (mlx->i * 50));
		mlx->i--;
		if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count == 0)
			ft_win(mlx);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_up, (mlx->j
				* 50), (mlx->i * 50));
	}
	mlx->move++;
}

void	ft_move_left(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_left, (mlx->j * 50),
		(mlx->i * 50));
	if (mlx->map->map[mlx->i][mlx->j] == 'C')
	{
		mlx->map->count--;
		mlx->map->map[mlx->i][mlx->j] = '0';
	}
	if (mlx->map->map[mlx->i][mlx->j - 1] && mlx->map->map[mlx->i][mlx->j
		- 1] != '1')
	{
		if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count != 0)
		{
			ft_putstr_fd("Tu n'as pas encore recolté toutes les pommes !\n", 1);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->bed, (mlx->j * 50),
				(mlx->i * 50));
		}
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->grass, (mlx->j
					* 50), (mlx->i * 50));
		mlx->j--;
		if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count == 0)
			ft_win(mlx);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_left, (mlx->j
				* 50), (mlx->i * 50));
	}
	mlx->move++;
}

void	ft_move_down(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_down, (mlx->j * 50),
		(mlx->i * 50));
	if (mlx->map->map[mlx->i][mlx->j] == 'C')
	{
		mlx->map->count--;
		mlx->map->map[mlx->i][mlx->j] = '0';
	}
	if (mlx->map->map[mlx->i + 1][mlx->j] && mlx->map->map[mlx->i
		+ 1][mlx->j] != '1')
	{
		if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count != 0)
		{
			ft_putstr_fd("Tu n'as pas encore recolté toutes les pommes !\n", 1);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->bed, (mlx->j * 50),
				(mlx->i * 50));
		}
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->grass, (mlx->j
					* 50), (mlx->i * 50));
		mlx->i++;
		if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count == 0)
			ft_win(mlx);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_down, (mlx->j
				* 50), (mlx->i * 50));
	}
	mlx->move++;
}

void	ft_move_right(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_right, (mlx->j
			* 50), (mlx->i * 50));
	if (mlx->map->map[mlx->i][mlx->j] == 'C')
	{
		mlx->map->count--;
		mlx->map->map[mlx->i][mlx->j] = '0';
	}
	if (mlx->map->map[mlx->i][mlx->j + 1] && mlx->map->map[mlx->i][mlx->j
		+ 1] != '1')
	{
		if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count != 0)
		{
			ft_putstr_fd("Tu n'as pas encore recolté toutes les pommes !\n", 1);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->bed, (mlx->j * 50),
				(mlx->i * 50));
		}
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->grass, (mlx->j
					* 50), (mlx->i * 50));
		mlx->j++;
		if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count == 0)
			ft_win(mlx);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_right, (mlx->j
				* 50), (mlx->i * 50));
	}
	mlx->move++;
}

int	manage_keys(int keycode, t_mlx *mlx)
{
	char	*str;

	if (keycode == XK_Escape)
		close_window(mlx);
	if (keycode == XK_w || keycode == XK_W)
		ft_move_up(mlx);
	if (keycode == XK_A || keycode == XK_a)
		ft_move_left(mlx);
	if (keycode == XK_s || keycode == XK_S)
		ft_move_down(mlx);
	if (keycode == XK_d || keycode == XK_D)
		ft_move_right(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->tree_apple, 100, 0);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->tree_apple, 150, 0);
	str = ft_itoa(mlx->move);
	mlx_string_put(mlx->ptr, mlx->win, 0, 10, 50, "Nombre de mouvements :");
	mlx_string_put(mlx->ptr, mlx->win, 140, 10, 50, str);
	free(str);
	return (0);
}

void	ft_move(t_mlx *mlx)
{
	mlx_hook(mlx->win, KeyPress, KeyPressMask, &manage_keys, &mlx);
	// ft_win(mlx);
}

void	ft_find_start(t_map *map, t_mlx *mlx)
{
	int i; // lignes
	int j; // colonnes
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				mlx->i = i;
				mlx->j = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_make_map(t_mlx *mlx)
{
	char	*str;

	mlx->width = 50;
	mlx->length = 50;
	if (ft_init_window(mlx) == 1)
	{
		ft_free_tab(mlx->map);
		return ;
	}
	if (ft_get_image(mlx) == 0)
	{
		free(mlx->win);
		free(mlx->ptr);
		free(mlx);
		exit(1);
	}
	ft_get_background(mlx);
	mlx->move = 0;
	str = ft_itoa(mlx->move);
	mlx_string_put(mlx->ptr, mlx->win, 0, 10, 50, "Nombre de mouvements :");
	mlx_string_put(mlx->ptr, mlx->win, 140, 10, 50, str);
	free(str);
	ft_find_start(mlx->map, mlx);
	ft_move(mlx);
}
