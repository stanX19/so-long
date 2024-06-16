/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_invalid_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:01:47 by stan              #+#    #+#             */
/*   Updated: 2024/06/16 23:49:15 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	has_equ_width(char *const *map, size_t width, size_t height)
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
static bool	has_solid_border(char *const *map, int width, int height)
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

static bool	only_contains_charset(char *const *map, int width, int height,
		const char *charset)
{
	if (charset == NULL)
		return (true);
	return (ft_2d_count_charset(map, width, height, charset) == width * height);
}

static const char	*get_ret(char **map, int width, int height)
{
	if (!has_equ_width(map, width, height))
		return ("Lines have unequal width");
	else if (!has_solid_border(map, width, height))
		return ("No solid border");
	else if (!only_contains_charset(map, width, height,
			ft_get_accepted_charset()))
		return ("Contains unknown character");
	else if (ft_2d_count_val(map, width, height, 'P') != 1)
		return ("Player count is not one");
	else if (ft_2d_count_val(map, width, height, 'E') != 1)
		return ("Exit count is not one");
	else if (ft_2d_count_val(map, width, height, 'C') < 1)
		return ("No collectibles");
	else
		return (ft_has_invalid_pathway(map, width, height));
}

// NULL: ok
// str: error message, ko
const char	*ft_is_invalid_map_file(const char *path)
{
	char		**map;
	size_t		width;
	size_t		height;
	const char	*ret;

	if (!ft_endswith(path, ".ber"))
		return ("Is not a ber file");
	map = ft_generate_raw_map(path, &width, &height);
	if (map == NULL)
		return (strerror(errno));
	ret = get_ret(map, width, height);
	ft_free_2d((void **)map, height);
	return (ret);
}
