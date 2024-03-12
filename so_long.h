/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:33 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/11 15:17:16 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define XK_Z 0x005a

typedef struct s_map
{
	int		size_map;
	size_t	len_map;
	char	**map;
	char	**filled;
	int		count;
	int		x;
	size_t	y;
}			t_map;

typedef struct s_mlx
{
	t_map	*map;
	void	*ptr;
	void	*win;
	void	*grass;
	void	*tree;
	void	*tree_apple;
	void	*apple;
	void	*bed;
	void	*rabbit_down;
	void	*rabbit_up;
	void	*rabbit_left;
	void	*rabbit_right;
	void	*rabbit_bed_down;
	void	*rabbit_bed_up;
	void	*rabbit_bed_left;
	void	*rabbit_bed_right;
	int		width;
	int		length;
	int		move;
	int		i;
	int		j;
	size_t	x;
	int		y;
}			t_mlx;

// CHECK_MAP

int			ft_verif_map(t_map *map);
int			ft_verif_file(char *file);
int			ft_verif_str(char *str);
t_map		*ft_map(char *file);

// CHECK_MAP_2

int			ft_error_map(t_map *tab, int i);
int			ft_size_map(char *file);
char		*ft_get_map(char *file, int size_map);

// CHECK_POSITION

void		ft_check_position_up(t_mlx *mlx);
void		ft_check_position_left(t_mlx *mlx);
void		ft_check_position_down(t_mlx *mlx);
void		ft_check_position_right(t_mlx *mlx);

// GET_BACKGROUND

void		ft_win(t_mlx *mlx);
void		ft_get_walls(t_mlx *mlx);
void		ft_choose_interior(t_mlx *mlx, size_t x, int j);
void		ft_get_interior(t_mlx *mlx);
void		ft_get_background(t_mlx *mlx);

// GET_IMAGE

int			ft_get_image(t_mlx *mlx);
int			ft_get_image_2(t_mlx *mlx);
int			ft_get_image_3(t_mlx *mlx);

// GNL
char		*get_next_line(int fd);
char		*ft_clean(char *line);
char		*ft_get_line(char *tempo);
char		*ft_make_line(int fd, char *line);
void		*ft_calloc(size_t elementCount, size_t elementSize);

// GNL_UTILS

char		*ft_make_join(char *line, char *buf);
char		*ft_strjoin_gnl(char *s1, char *s2);
void		ft_bzero_gnl(void *s, size_t n);
int			ft_strchr_gnl(char *s);
int			ft_strlen_gnl(char *str);

// MAIN

int			close_window(t_mlx *mlx);
int			ft_init_window(t_mlx *mlx);
void		ft_init_pos(t_mlx *mlx);
t_mlx		ft_init_mlx(t_mlx *mlx);
int			main(int argc, char **argv);

// MAKE_MAP

void		ft_move(t_mlx *mlx);
void		ft_find_start(t_map *map, t_mlx *mlx);
void		ft_destroy_image_2(t_mlx *mlx);
void		ft_destroy_image(t_mlx *mlx);
void		ft_make_map(t_mlx *mlx);

// MAKE_MAP_2

void		ft_move_up(t_mlx *mlx);
void		ft_move_left(t_mlx *mlx);
void		ft_move_down(t_mlx *mlx);
void		ft_move_right(t_mlx *mlx);
int			manage_keys(int keycode, t_mlx *mlx);

// UTILS

t_map		*ft_init(void);
int			ft_free_tab(t_map *map);
char		**ft_copy_array(t_map *map);
int			ft_free_array(char **array);

// UTILS_MAP

int			ft_verif_wall_verti(char **map, size_t len, int size_map);
int			ft_verif_wall_horiz(char **map, int size_map);
int			ft_verif_wall(t_map *map);
int			ft_verif_char(t_map *map, char c);
int			ft_verif_size_wall(t_map *map);

// UTILS_MAP_2

void		fill(t_map *map, int x, size_t y);
int			ft_check_filled(char **filled);
int			ft_verif_path(t_map *map);

#endif