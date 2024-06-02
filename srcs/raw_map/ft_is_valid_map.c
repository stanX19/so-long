/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:48:21 by shatan            #+#    #+#             */
/*   Updated: 2024/06/02 18:33:42 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_grid(t_stringstream *ss)
{
	int		prev_len;
	int		length;
	char	*line;

	if (ss_read_line(ss, &line, "\n\t"))
	{
		prev_len = ft_strlen(line);
		free(line);
	}
	else
		return (false);
	while (ss_read_line(ss, &line, "\n\t"))
	{
		length = ft_strlen(line);
		free(line);
		if (length != prev_len)
		{
			return (false);
		}
	}
	return (true);
}

int	ft_is_valid_map(const char *path)
{
	int				valid;
	int				fd;
	t_stringstream	*ss;

	fd = open(path, O_RDONLY);
	ss = ss_create_from_fd(fd);
	valid = is_grid(ss);
	ss_destroy(ss);
	close(fd);
	return (valid);
}
