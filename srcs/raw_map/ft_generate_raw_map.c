/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_raw_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:45:28 by shatan            #+#    #+#             */
/*   Updated: 2024/06/11 14:19:44 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(t_stringstream *ss)
{
	int	count;

	count = 1;
	ss_reset(ss);
	while (ss_read_line(ss, NULL, "\n\r"))
	{
		count++;
	}
	ss_reset(ss);
	return (count);
}

static char	**failed(const char *msg, const char *path, size_t *width, size_t *height)
{
	*width = 0;
	*height = 0;
	ft_printf("Error\n\t%s: %s\n", msg, path);
	return (NULL);
}

static char	**generate_map(t_stringstream *ss, size_t *width, size_t *height)
{
	int		idx;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (count_lines(ss) + 1));
	if (!ret)
		return (NULL);
	idx = 0;
	while (ss_read_line(ss, ret + idx, "\n\r"))
	{
		idx++;
	}
	ret[idx] = NULL;
	*width = ft_strlen(ret[0]);
	*height = idx;
	return (ret);
}

char	**ft_generate_raw_map(const char *path, size_t *width, size_t *height)
{
	char			**ret;
	int				fd;
	t_stringstream	*ss;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (failed(strerror(errno), path, width, height));
	ss = ss_create_from_fd(fd);
	ret = generate_map(ss, width, height);
	if (ret == NULL)
		return (failed("Not enough ram", path, width, height));
	ss_destroy(ss);
	close(fd);
	if (!ft_is_valid_map(ret, *width, *height))
	{
		ft_free_2d((void **)ret, *height);
		return ((failed("Invalid map", path, width, height)));
	}
	return (ret);
}
