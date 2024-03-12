/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:30:13 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/11 12:30:29 by ocussy           ###   ########.fr       */
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
	return (1);
}

int	ft_get_image_2(t_mlx *mlx)
{
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
	mlx->rabbit_bed_down = mlx_xpm_file_to_image(mlx->ptr,
			"Images/lapinou_bed_down.xpm", &mlx->width, &mlx->length);
	if (!mlx->rabbit_bed_down)
		return (0);
	mlx->rabbit_bed_up = mlx_xpm_file_to_image(mlx->ptr,
			"Images/lapinou_bed_up.xpm", &mlx->width, &mlx->length);
	if (!mlx->rabbit_bed_up)
		return (0);
	mlx->rabbit_bed_left = mlx_xpm_file_to_image(mlx->ptr,
			"Images/lapinou_bed_left.xpm", &mlx->width, &mlx->length);
	if (!mlx->rabbit_bed_left)
		return (0);
	return (1);
}

int	ft_get_image_3(t_mlx *mlx)
{
	mlx->rabbit_bed_right = mlx_xpm_file_to_image(mlx->ptr,
			"Images/lapinou_bed_right.xpm", &mlx->width, &mlx->length);
	if (!mlx->rabbit_bed_right)
		return (0);
	return (1);
}
