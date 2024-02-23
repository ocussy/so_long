/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:33 by ocussy            #+#    #+#             */
/*   Updated: 2024/02/23 12:21:45 by ocussy           ###   ########.fr       */
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

typedef struct s_data
{
	int		size_map;
	int		len_map;
	char	**map;
}			t_data;

// FT_MAP
int			ft_error(int fd);
int			ft_size_map(void);
int			ft_verif_map(char **tab);
int			ft_map(void);
char		*ft_get_map(int size_map);

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