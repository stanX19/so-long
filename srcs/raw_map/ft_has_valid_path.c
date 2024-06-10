/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_valid_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:25:17 by shatan            #+#    #+#             */
/*   Updated: 2024/06/10 18:40:33 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec2	get_player_loc(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'P')
				return ((t_vec2){j, i});
			j++;
		}
		i++;
	}
	return ((t_vec2){0, 0});
}

void	flood_fill(char **map, int width, int height, t_vec2 start)
{
	if (start.x < 0 || start.y < 0 || start.x >= width || start.y >= height)
		return ;
	if (map[start.y][start.x] == '1' || map[start.y][start.x] == 'X')
		return ;
	map[start.y][start.x] = 'X';
	flood_fill(map, width, height, (t_vec2){start.x, start.y - 1});
	flood_fill(map, width, height, (t_vec2){start.x, start.y + 1});
	flood_fill(map, width, height, (t_vec2){start.x - 1, start.y});
	flood_fill(map, width, height, (t_vec2){start.x + 1, start.y});
}

bool	ft_has_valid_path(char *const *map, int width, int height)
{
	char	**cpy;
	t_vec2	player_loc;
	bool	valid;

	cpy = ft_raw_map_copy(map, width, height);
	player_loc = get_player_loc(cpy, width, height);
	flood_fill(cpy, width, height, player_loc);
	if (ft_2d_count_charset(cpy, width, height, "PEC"))
		valid = false;
	else
		valid = true;
	ft_free_2d((void **)cpy, height);
	return (valid);
}
