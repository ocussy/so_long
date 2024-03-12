/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:10:16 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/11 15:48:43 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(t_mlx *mlx)
{
	mlx_hook(mlx->win, KeyPress, KeyPressMask, &manage_keys, &mlx);
}

void	ft_find_start(t_map *map, t_mlx *mlx)
{
	int	i;
	int	j;

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

void	ft_destroy_image_2(t_mlx *mlx)
{
	if (mlx->rabbit_bed_left != NULL)
		mlx_destroy_image(mlx->ptr, mlx->rabbit_bed_left);
	if (mlx->rabbit_bed_right != NULL)
		mlx_destroy_image(mlx->ptr, mlx->rabbit_bed_right);
	ft_free_tab(mlx->map);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
}

void	ft_destroy_image(t_mlx *mlx)
{
	if (mlx->apple != NULL)
		mlx_destroy_image(mlx->ptr, mlx->apple);
	if (mlx->tree != NULL)
		mlx_destroy_image(mlx->ptr, mlx->tree);
	if (mlx->tree_apple != NULL)
		mlx_destroy_image(mlx->ptr, mlx->tree_apple);
	if (mlx->rabbit_up != NULL)
		mlx_destroy_image(mlx->ptr, mlx->rabbit_up);
	if (mlx->rabbit_down != NULL)
		mlx_destroy_image(mlx->ptr, mlx->rabbit_down);
	if (mlx->rabbit_right != NULL)
		mlx_destroy_image(mlx->ptr, mlx->rabbit_right);
	if (mlx->rabbit_left != NULL)
		mlx_destroy_image(mlx->ptr, mlx->rabbit_left);
	if (mlx->bed != NULL)
		mlx_destroy_image(mlx->ptr, mlx->bed);
	if (mlx->grass != NULL)
		mlx_destroy_image(mlx->ptr, mlx->grass);
	if (mlx->rabbit_bed_down != NULL)
		mlx_destroy_image(mlx->ptr, mlx->rabbit_bed_down);
	if (mlx->rabbit_bed_up != NULL)
		mlx_destroy_image(mlx->ptr, mlx->rabbit_bed_up);
	ft_destroy_image_2(mlx);
}

void	ft_make_map(t_mlx *mlx)
{
	char	*str;

	mlx->width = 50;
	mlx->length = 50;
	if (ft_init_window(mlx) == 1)
	{
		ft_free_tab(mlx->map);
		exit(1);
	}
	if (ft_get_image(mlx) == 0 || ft_get_image_2(mlx) == 0
		|| ft_get_image_3(mlx) == 0)
	{
		ft_destroy_image(mlx);
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
