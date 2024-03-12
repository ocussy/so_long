/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:45:58 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/12 16:29:09 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_mlx *mlx)
{
	ft_putstr_fd("Une bonne nuit de repos !\n", 1);
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

void	ft_choose_interior(t_mlx *mlx, size_t x, int j)
{
	int	i;
	int	y;

	y = 50;
	i = 1;
	while (y < mlx->y - 50)
	{
		if (mlx->map->map[i][j] == '1')
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->tree, x, y);
		if (mlx->map->map[i][j] == '0')
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->grass, x, y);
		if (mlx->map->map[i][j] == 'P')
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_down, x, y);
		if (mlx->map->map[i][j] == 'C')
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->apple, x, y);
		if (mlx->map->map[i][j] == 'E')
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->bed, x, y);
		y += 50;
		i++;
	}
}

void	ft_get_interior(t_mlx *mlx)
{
	size_t	x;
	int		j;

	x = 50;
	j = 1;
	while (x < mlx->x - 50)
	{
		ft_choose_interior(mlx, x, j);
		x += 50;
		j++;
	}
}

void	ft_get_background(t_mlx *mlx)
{
	ft_get_walls(mlx);
	ft_get_interior(mlx);
}
