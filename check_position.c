/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:47:56 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/11 12:48:56 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_position_up(t_mlx *mlx)
{
	if (mlx->map->map[mlx->i][mlx->j] == 'E')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_bed_up, (mlx->j
				* 50), (mlx->i * 50));
	else
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_up, (mlx->j
				* 50), (mlx->i * 50));
	if (mlx->map->map[mlx->i][mlx->j] == 'C')
	{
		mlx->map->count--;
		mlx->map->map[mlx->i][mlx->j] = '0';
	}
}

void	ft_check_position_left(t_mlx *mlx)
{
	if (mlx->map->map[mlx->i][mlx->j] == 'E')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_bed_left,
			(mlx->j * 50), (mlx->i * 50));
	else
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_left, (mlx->j
				* 50), (mlx->i * 50));
	if (mlx->map->map[mlx->i][mlx->j] == 'C')
	{
		mlx->map->count--;
		mlx->map->map[mlx->i][mlx->j] = '0';
	}
}

void	ft_check_position_down(t_mlx *mlx)
{
	if (mlx->map->map[mlx->i][mlx->j] == 'E')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_bed_down,
			(mlx->j * 50), (mlx->i * 50));
	else
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_down, (mlx->j
				* 50), (mlx->i * 50));
	if (mlx->map->map[mlx->i][mlx->j] == 'C')
	{
		mlx->map->count--;
		mlx->map->map[mlx->i][mlx->j] = '0';
	}
}

void	ft_check_position_right(t_mlx *mlx)
{
	if (mlx->map->map[mlx->i][mlx->j] == 'E')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_bed_right,
			(mlx->j * 50), (mlx->i * 50));
	else
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_right, (mlx->j
				* 50), (mlx->i * 50));
	if (mlx->map->map[mlx->i][mlx->j] == 'C')
	{
		mlx->map->count--;
		mlx->map->map[mlx->i][mlx->j] = '0';
	}
}
