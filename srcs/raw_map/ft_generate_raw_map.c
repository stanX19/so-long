/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_raw_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:45:28 by shatan            #+#    #+#             */
/*   Updated: 2024/06/04 14:50:23 by shatan           ###   ########.fr       */
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

static char	**failed(const char *msg, size_t *width, size_t *height)
{
	*width = 0;
	*height = 0;
	ft_printf("ERROR: Generate raw map: %s\n", msg);
	return (NULL);
}

static char	**generate_map(t_stringstream *ss, size_t *width, size_t *height)
{
	int		idx;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (count_lines(ss) + 1));
	if (!ret)
		return (failed("failed to malloc\n", width, height));
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
		return (failed(strerror(errno), width, height));
	ss = ss_create_from_fd(fd);
	ret = generate_map(ss, width, height);
	ss_destroy(ss);
	close(fd);
	if (!ft_is_valid_map(ret, *width, *height))
	{
		ft_free_2d(ret, *height);
		return (failed("Invalid map", width, height));
	}
	return (ret);
}
