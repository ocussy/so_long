/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:57:26 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/12 16:35:45 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	close_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->tree);
	mlx_destroy_image(mlx->ptr, mlx->tree_apple);
	mlx_destroy_image(mlx->ptr, mlx->rabbit_up);
	mlx_destroy_image(mlx->ptr, mlx->rabbit_down);
	mlx_destroy_image(mlx->ptr, mlx->rabbit_right);
	mlx_destroy_image(mlx->ptr, mlx->rabbit_left);
	mlx_destroy_image(mlx->ptr, mlx->bed);
	mlx_destroy_image(mlx->ptr, mlx->grass);
	mlx_destroy_image(mlx->ptr, mlx->apple);
	mlx_destroy_image(mlx->ptr, mlx->rabbit_bed_down);
	mlx_destroy_image(mlx->ptr, mlx->rabbit_bed_up);
	mlx_destroy_image(mlx->ptr, mlx->rabbit_bed_left);
	mlx_destroy_image(mlx->ptr, mlx->rabbit_bed_right);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	ft_free_tab(mlx->map);
	exit(0);
}

int	ft_init_window(t_mlx *mlx)
{
	mlx->y = (mlx->map->size_map * 50);
	mlx->x = (mlx->map->len_map * 50);
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		return (1);
	if (mlx->x > 1900 || mlx->y > 1000)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		return (1);
	}
	mlx->win = mlx_new_window(mlx->ptr, mlx->x, mlx->y, "horrible game");
	if (mlx->win == NULL)
	{
		ft_free_tab(mlx->map);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		return (1);
	}
	return (0);
}

void	ft_init_pos(t_mlx *mlx)
{
	mlx->i = 0;
	mlx->j = 0;
	mlx->x = 0;
	mlx->y = 0;
}

t_mlx	ft_init_mlx(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->grass = NULL;
	mlx->tree = NULL;
	mlx->tree_apple = NULL;
	mlx->apple = NULL;
	mlx->bed = NULL;
	mlx->rabbit_down = NULL;
	mlx->rabbit_up = NULL;
	mlx->rabbit_left = NULL;
	mlx->rabbit_right = NULL;
	mlx->rabbit_bed_down = NULL;
	mlx->rabbit_bed_left = NULL;
	mlx->rabbit_bed_right = NULL;
	mlx->rabbit_bed_up = NULL;
	mlx->width = 0;
	mlx->length = 0;
	mlx->move = 0;
	mlx->i = 0;
	mlx->j = 0;
	mlx->x = 0;
	mlx->y = 0;
	return (*mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	else
	{
		mlx = ft_init_mlx(&mlx);
		mlx.map = ft_map(argv[1]);
		if (!mlx.map)
			return (0);
		ft_make_map(&mlx);
		mlx_hook(mlx.win, KeyPress, KeyPressMask, &manage_keys, &mlx);
		mlx_hook(mlx.win, DestroyNotify, ButtonPressMask, &close_window, &mlx);
		mlx_loop(mlx.ptr);
		return (0);
	}
}
