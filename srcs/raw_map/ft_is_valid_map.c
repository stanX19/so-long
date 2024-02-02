/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:48:21 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 17:48:27 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_grid(const char *path)
{
	int		prev;
	int		cur;
	char	c;
	int		fd;

	fd = open(path, O_RDONLY);
	prev = 0;
	while (read(fd, &c, 1) && c != '\n')
		prev++;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
		{
			if (cur != prev)
				return (0);
			cur = 0;
		}
		else
			cur++;
	}
	return (cur == prev);
}

int	ft_is_valid_map(const char *path)
{
	int	valid;

	valid = is_grid(path);
	return (valid);
}
