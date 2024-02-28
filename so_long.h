/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:33 by ocussy            #+#    #+#             */
/*   Updated: 2024/02/28 18:16:58 by ocussy           ###   ########.fr       */
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

typedef struct s_map
{
	int		size_map;
	size_t	len_map;
	char	**map;
	char	**filled;
}			t_map;

// CHECK_MAP

int			ft_error_map(t_map *tab, int i);
int			ft_size_map(void);
char		*ft_get_map(int size_map);
int			ft_verif_map(t_map *map);
int			ft_map(void);

// UTILS

t_map		*ft_init(void);
int			ft_free_tab(t_map *map);
char		**ft_copy_array(t_map *map);

// UTILS_MAP

int			ft_verif_wall_verti(char **map, size_t len, int size_map);
int			ft_verif_wall_horiz(char **map, int size_map);
int			ft_verif_wall(t_map *map);
int			ft_verif_char(char **map, char c);
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

#endif