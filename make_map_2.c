/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:49:39 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/11 12:50:57 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_mlx *mlx)
{
	ft_check_position_up(mlx);
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
		if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count != 0)
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_bed_up,
				(mlx->j * 50), (mlx->i * 50));
		else if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count == 0)
			ft_win(mlx);
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_up, (mlx->j
					* 50), (mlx->i * 50));
	}
	mlx->move++;
}

void	ft_move_left(t_mlx *mlx)
{
	ft_check_position_left(mlx);
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
		if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count != 0)
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_bed_left,
				(mlx->j * 50), (mlx->i * 50));
		else if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count == 0)
			ft_win(mlx);
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_left,
				(mlx->j * 50), (mlx->i * 50));
	}
	mlx->move++;
}

void	ft_move_down(t_mlx *mlx)
{
	ft_check_position_down(mlx);
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
		if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count != 0)
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_bed_down,
				(mlx->j * 50), (mlx->i * 50));
		else if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count == 0)
			ft_win(mlx);
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_down,
				(mlx->j * 50), (mlx->i * 50));
	}
	mlx->move++;
}

void	ft_move_right(t_mlx *mlx)
{
	ft_check_position_right(mlx);
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
		if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count != 0)
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_bed_right,
				(mlx->j * 50), (mlx->i * 50));
		else if (mlx->map->map[mlx->i][mlx->j] == 'E' && mlx->map->count == 0)
			ft_win(mlx);
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->rabbit_right,
				(mlx->j * 50), (mlx->i * 50));
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
