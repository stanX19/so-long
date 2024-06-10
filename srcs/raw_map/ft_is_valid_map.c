/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:48:21 by shatan            #+#    #+#             */
/*   Updated: 2024/06/10 18:40:59 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	has_equ_width(char *const*map, size_t width, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		if (ft_strlen(map[i]) != width)
			return (false);
		i++;
	}
	return (true);
}

// assuming that map is confirmed to have equ width
static bool	has_solid_border(char *const*map, int width, int height)
{
	const char	*wall = "12";
	int			i;

	i = 0;
	if (ft_str_count_charset(map[i++], wall) != width)
		return (false);
	while (i < height - 1)
	{
		if (!ft_strchr(wall, map[i][0]) || !ft_strchr(wall, map[i][width - 1]))
			return (false);
		i++;
	}
	if (ft_str_count_charset(map[i], wall) != width)
		return (false);
	return (true);
}

static bool	has_player_coin_exit(char *const*map, int width, int height)
{
	return (ft_2d_count_val(map, width, height, 'P') == 1
		&& ft_2d_count_val(map, width, height, 'E') == 1 && ft_2d_count_val(map,
			width, height, 'C') >= 1);
}

bool	ft_is_valid_map(char * const*map, int width, int height)
{
	if (!has_equ_width(map, width, height))
		return (false);
	if (!has_solid_border(map, width, height))
		return (false);
	if (!has_player_coin_exit(map, width, height))
		return (false);
	if (!ft_has_valid_path(map, width, height))
		return (false);
	return (true);
}
