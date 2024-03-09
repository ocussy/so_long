/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:57:26 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/06 12:15:27 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

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
	// if (mlx->x > 2500 || mlx->y > 1400)
	// 	return (1);
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		return (1);
	mlx->win = mlx_new_window(mlx->ptr, mlx->x, mlx->y, "horrible game");
	if (mlx->win == NULL)
	{
		free(mlx->ptr);
		return (1);
	}
	return (0);
}

// verifier truc qunad on trouve pas image
// verifier leak
// faire le lit

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
	{
		ft_putstr_fd("Error", 2);
		return (1);
	}
	else
	{
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

// int		t;
// int		r;
// int		g;
// int		b;
// int		color;
// char	*relative_path;
// int		img_width;
// int		img_height;
// int		x;
// int		y;
// mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel,
// &mlx.size_line,
// 		&mlx.endian);
// my_mlx_pixel_put(&mlx, 10, 10, 0x00FF0000);
// mlx_string_put(mlx.ptr, mlx.win, 250, 500, 200, "Bonne Saint-Valentin");
// t = 255;
// r = 128;
// g = 64;
// b = 32;
// color = create_trgb(t, r, g, b);
// mlx_pixel_put(mlx.ptr, mlx.win, 250, 250, color);
// // mlx_string_put(mlx.ptr, mlx.win, 10, 10, 0xFF0000,
// "Background color");
// relative_path = "./Grass.xpm";
// img_height = 0;
// img_width = 0;
// mlx.img = mlx_xpm_file_to_image(mlx.ptr, relative_path,
// &img_width,
// 		&img_height);
// x = 0;
// while (x <= 1800)
// {
// 	y = 0;
// 	while (y <= 1260)
// 	{
// 		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, x, y);
// 		y += 60;
// 	}
// 	x += 60;
// }
