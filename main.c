/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:57:26 by ocussy            #+#    #+#             */
/*   Updated: 2024/02/21 10:48:41 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

// typedef struct s_data
// {
// 	void	*img;
// 	void	*ptr;
// 	void	*win;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		size_line;
// 	int		endian;
// }			t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// int	get_t(int trgb)
// {
// 	return ((trgb >> 24) & 0xFF);
// }

// int	get_r(int trgb)
// {
// 	return ((trgb >> 16) & 0xFF);
// }

// int	get_g(int trgb)
// {
// 	return ((trgb >> 8) & 0xFF);
// }

// int	get_b(int trgb)
// {
// 	return (trgb & 0xFF);
// }
// int	close_window(t_data *img)
// {
// 	mlx_destroy_image(img->ptr, img->img);
// 	mlx_destroy_window(img->ptr, img->win);
// 	mlx_destroy_display(img->ptr);
// 	exit(0);
// 	return (0);
// }
// int	manage_keys(int keycode, t_data *img)
// {
// 	if (keycode == XK_Escape)
// 		close_window(img);
// 	return (0);
// }

// int	mouse_hook(int key_hook, t_data *img)
// {
// 	if (key_hook == 1)
// 		printf("Bonjour !");
// 	(void)img;
// 	return (0);
// }

int	main(void)
{
	// t_data	mlx;
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
	ft_map();
	// mlx.ptr = mlx_init();
	// if (mlx.ptr == NULL)
	// 	return (1);
	// mlx.win = mlx_new_window(mlx.ptr, 1800, 1260, "Hello World");
	// if (mlx.win == NULL)
	// {
	// 	free(mlx.ptr);
	// 	return (1);
	// }
	// mlx.img = mlx_new_image(mlx.ptr, 500, 500);
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
	// mlx_hook(mlx.win, KeyPress, KeyPressMask, &manage_keys, &mlx);
	// mlx_hook(mlx.win, DestroyNotify, ButtonPressMask, &close_window, &mlx);
	// mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
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
	// mlx_loop(mlx.ptr);
	return (0);
}
