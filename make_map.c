/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:10:16 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/01 16:22:44 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_image(t_mlx *mlx)
{
	mlx->grass = mlx_xpm_file_to_image(mlx->ptr, "Images/grass.xpm",
			&mlx->width, &mlx->length);
	mlx->tree = mlx_xpm_file_to_image(mlx->ptr, "Images/tree_2.xpm",
			&mlx->width, &mlx->length);
	mlx->tree_apple = mlx_xpm_file_to_image(mlx->ptr, "Images/tree.xpm",
			&mlx->width, &mlx->length);
	mlx->rabbit_down = mlx_xpm_file_to_image(mlx->ptr, "Images/lapinou.xpm",
			&mlx->width, &mlx->length);
	mlx->bed = mlx_xpm_file_to_image(mlx->ptr, "Images/bed.xpm", &mlx->width,
			&mlx->length);
	mlx->apple = mlx_xpm_file_to_image(mlx->ptr, "Images/collectible.xpm",
			&mlx->width, &mlx->length);
	mlx->rabbit_up = mlx_xpm_file_to_image(mlx->ptr, "Images/lapinou_back.xpm",
			&mlx->width, &mlx->length);
	mlx->rabbit_left = mlx_xpm_file_to_image(mlx->ptr,
			"Images/lapinou_left.xpm", &mlx->width, &mlx->length);
	mlx->rabbit_right = mlx_xpm_file_to_image(mlx->ptr,
			"Images/lapinou_right.xpm", &mlx->width, &mlx->length);
}

void ft_win(t_mlx *mlx)
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
			y += 100;
			i++;
		}
		x += 100;
		j++;
	}
}

void	ft_get_interior(t_mlx *mlx)
{
	size_t	x;
	int		y;
	int		i;
	int		j;

	x = 100;
	y = 100;
	j = 1;
	while (x < mlx->x - 100)
	{
		y = 100;
		i = 1;
		while (y < mlx->y - 100)
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
			y += 100;
			i++;
		}
		x += 100;
		j++;
	}
}

void	ft_get_background(t_mlx *mlx)
{
	ft_get_walls(mlx);
	ft_get_interior(mlx);
}

void ft_move_up(t_mlx *mlx)
{	
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_up, (mlx->j * 100), (mlx->i * 100));
	if (mlx->map->map[mlx-> i][mlx->j] == 'C')
	{
		mlx->map->count--;
		mlx->map->map[mlx-> i][mlx->j] = '0';
	}
	if (mlx->map->map[mlx->i - 1][mlx->j] && mlx->map->map[mlx->i - 1][mlx->j] != '1')
	{
		if (mlx->map->map[mlx-> i][mlx->j] == 'E' && mlx->map->count != 0)
		{
			ft_putstr_fd("Tu n'as pas encore recolté toutes les pommes !\n", 1);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->bed, (mlx->j * 100), (mlx->i * 100));
		}
		else if (mlx->map->map[mlx-> i][mlx->j] == 'E' && mlx->map->count == 0)
			ft_win(mlx);
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->grass, (mlx->j * 100), (mlx->i * 100));
		mlx->i--;
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_up, (mlx->j * 100), (mlx->i * 100));
	}
	mlx->move++;
}

void ft_move_left(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_left, (mlx->j * 100), (mlx->i * 100));
	if (mlx->map->map[mlx-> i][mlx->j] == 'C')
	{
		mlx->map->count--;
		mlx->map->map[mlx-> i][mlx->j] = '0';
	}
	if (mlx->map->map[mlx->i][mlx->j - 1] && mlx->map->map[mlx->i][mlx->j - 1] != '1')
	{
		if (mlx->map->map[mlx-> i][mlx->j] == 'E' && mlx->map->count != 0)
		{
			ft_putstr_fd("Tu n'as pas encore recolté toutes les pommes !\n", 1);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->bed, (mlx->j * 100), (mlx->i * 100));
		}
		else if (mlx->map->map[mlx-> i][mlx->j] == 'E' && mlx->map->count == 0)
			ft_win(mlx);
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->grass, (mlx->j  * 100), (mlx->i * 100));
		mlx->j--;
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_left, (mlx->j * 100), (mlx->i * 100));
	}
	mlx->move++;
}

void ft_move_down(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_down, (mlx->j * 100), (mlx->i * 100));
	if (mlx->map->map[mlx-> i][mlx->j] == 'C')
	{
		mlx->map->count--;
		mlx->map->map[mlx-> i][mlx->j] = '0';
	}
	if (mlx->map->map[mlx->i +1][mlx->j] && mlx->map->map[mlx->i+1][mlx->j] != '1')
	{
		if (mlx->map->map[mlx-> i][mlx->j] == 'E' && mlx->map->count != 0)
		{
			ft_putstr_fd("Tu n'as pas encore recolté toutes les pommes !\n", 1);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->bed, (mlx->j * 100), (mlx->i * 100));
		}
		else if (mlx->map->map[mlx-> i][mlx->j] == 'E' && mlx->map->count == 0)
			ft_win(mlx);
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->grass, (mlx->j * 100), (mlx->i * 100));
		mlx->i++;
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_down, (mlx->j * 100), (mlx->i * 100));
	}
	mlx->move++;
}

void ft_move_right(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_right, (mlx->j* 100), (mlx->i * 100));
	if (mlx->map->map[mlx-> i][mlx->j] == 'C')
	{
		mlx->map->count--;
		mlx->map->map[mlx-> i][mlx->j] = '0';
	}
	if (mlx->map->map[mlx->i][mlx->j+1] && mlx->map->map[mlx->i][mlx->j+1] != '1')
	{
		if (mlx->map->map[mlx-> i][mlx->j] == 'E' && mlx->map->count != 0)
		{
			ft_putstr_fd("Tu n'as pas encore recolté toutes les pommes !\n", 1);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->bed, (mlx->j * 100), (mlx->i * 100));
		}
		else if (mlx->map->map[mlx-> i][mlx->j] == 'E' && mlx->map->count == 0)
			ft_win(mlx);
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->grass, (mlx->j  * 100), (mlx->i * 100));
		mlx->j++;
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_right, (mlx->j * 100), (mlx->i * 100));
	}
	mlx->move++;
}

int	manage_keys(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		close_window(mlx);
	if (keycode == 122)
		ft_move_up(mlx);
	if (keycode == 113)
		ft_move_left(mlx);
	if (keycode == 115)
		ft_move_down(mlx);
	if (keycode == 100)
		ft_move_right(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->tree_apple, 100,
					0);
	mlx_string_put(mlx->ptr, mlx->win, 0, 10, 50, "Nombre de mouvements :");
	mlx_string_put(mlx->ptr, mlx->win, 140, 10, 50, ft_itoa(mlx->move));
	
	return (0);
}

void ft_move(t_mlx *mlx)
{
	mlx_hook(mlx->win, KeyPress, KeyPressMask, &manage_keys, &mlx);
}

void ft_find_start(t_map *map, t_mlx *mlx)
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
	mlx->width = 100;
	mlx->length = 100;
	ft_get_image(mlx);
	ft_get_background(mlx);
	mlx->move = 0;
	mlx_string_put(mlx->ptr, mlx->win, 0, 10, 50, "Nombre de mouvements :");
	mlx_string_put(mlx->ptr, mlx->win, 140, 10, 50, ft_itoa(mlx->move));
	ft_find_start(mlx->map, mlx);
	ft_move(mlx);
	// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->tree, 0, 100);
	// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->tree_apple, 0, 200);
	// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->grass, 100, 0);
	// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->apple, 100, 100);
	// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_down, 200, 100);
	// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->bed, 300, 100);
	// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_up, 200, 200);
	// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_left, 200, 300);
	// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_right, 300, 300);
}
