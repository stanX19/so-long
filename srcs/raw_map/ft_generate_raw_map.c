/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_raw_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:45:28 by shatan            #+#    #+#             */
/*   Updated: 2024/05/19 22:36:53 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(int fd)
{
	int		ret;
	char	c;

	ret = 1;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			ret++;
	}
	return (ret);
}

static void	read_and_set(int fd, char **ret, size_t *width, size_t *height)
{
	char			buffer[320000];
	int				idx;
	t_stringstream	*ss;

	buffer[read(fd, buffer, sizeof(buffer) - 1)] = 0;
	ss = ss_create(buffer);
	idx = 0;
	errno = 0;
	while (ss_read_line(ss, ret + idx, "\n"))
	{
		idx++;
	}
	ss_destroy(ss);
	ret[idx] = 0;
	*width = ft_strlen(ret[0]);
	*height = idx;
}

static char	**failed(char *msg, size_t *width, size_t *height)
{
	*width = 0;
	*height = 0;
	ft_printf("ERROR: Generate raw map: %s\n", msg);
	return (0);
}

char	**ft_generate_raw_map(const char *path, size_t *width, size_t *height)
{
	char	**ret;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		return (failed(strerror(errno), width, height));
	}
	ret = (char **)malloc(sizeof(char *) * (count_lines(fd) + 1));
	close(fd);
	if (!ret)
	{
		return (failed("failed to malloc", width, height));
	}
	fd = open(path, O_RDONLY);
	read_and_set(fd, ret, width, height);
	close(fd);
	return (ret);
}
