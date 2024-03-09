/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:33 by ocussy            #+#    #+#             */
/*   Updated: 2024/03/06 12:06:33 by ocussy           ###   ########.fr       */
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
	int		width;
	int		length;
	int		move;
	int		pos_x;
	size_t	pos_y;
	int		i;
	int		j;
	size_t	x;
	int		y;
}			t_mlx;

// CHECK_MAP

int			ft_error_map(t_map *tab, int i);
int			ft_size_map(char *file);
char		*ft_get_map(char *file, int size_map);
int			ft_verif_map(t_map *map);
t_map		*ft_map(char *file);

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

// MAKE_MAP

int			ft_get_image(t_mlx *mlx);
void		ft_make_map(t_mlx *mlx);
void		ft_get_background(t_mlx *mlx);

// MAIN

int			close_window(t_mlx *mlx);
int			manage_keys(int keycode, t_mlx *mlx);
int			mouse_hook(int key_hook, t_mlx *mlx);
int			ft_init_window(t_mlx *mlx);
int			main(int argc, char **argv);

#endif