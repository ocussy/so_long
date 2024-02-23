/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:12:28 by ocussy            #+#    #+#             */
/*   Updated: 2024/02/17 14:50:29 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

//#include <fcntl.h>
//#include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen_gnl(char *str);
int		ft_strchr_gnl(char *s);
void	ft_bzero_gnl(void *s, size_t n);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_make_join(char *line, char *buf);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*ft_make_line(int fd, char *line);
char	*ft_get_line(char *tempo);
char	*ft_clean(char *line);
char	*get_next_line(int fd);

#endif
