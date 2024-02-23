/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:54:37 by ocussy            #+#    #+#             */
/*   Updated: 2024/02/23 11:07:49 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*res;

	res = malloc(elementSize * elementCount);
	if (!res)
		return (NULL);
	ft_bzero_gnl(res, elementSize * elementCount);
	return (res);
}

char	*ft_make_line(int fd, char *line)
{
	char	*buf;
	int		count;

	if (!line)
		line = ft_calloc(1, 1);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	count = 1;
	while (count > 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1 || (count == 0 && line[0] == '\0'))
		{
			free(buf);
			free(line);
			return (NULL);
		}
		buf[count] = '\0';
		line = ft_make_join(line, buf);
		if (count != BUFFER_SIZE || ft_strchr_gnl(buf) != 0)
			break ;
	}
	free(buf);
	return (line);
}

char	*ft_get_line(char *tempo)
{
	char	*line;
	int		i;

	i = 0;
	if (!tempo)
		return (NULL);
	while (tempo[i] && tempo[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (tempo[i] && tempo[i] != '\n')
	{
		line[i] = tempo[i];
		i++;
	}
	if (tempo[i] && tempo[i] == '\n')
	{
		line[i] = tempo[i];
		i++;
	}
	return (line);
}

char	*ft_clean(char *line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!line)
	{
		free(line);
		return (NULL);
	}
	while (line[i] != '\n' && line[i])
		i++;
	tmp = ft_calloc((ft_strlen_gnl(line) - i + 1), sizeof(char));
	if (!tmp)
	{
		free(line);
		return (NULL);
	}
	if (line[i] && line[i] == '\n')
		i++;
	while (line[i])
		tmp[j++] = line[i++];
	free(line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*final_line;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_make_line(fd, line);
	if (!line || *line == '\0')
	{
		free(line);
		return (NULL);
	}
	final_line = ft_get_line(line);
	line = ft_clean(line);
	return (final_line);
}

// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }