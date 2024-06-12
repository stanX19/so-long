/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_invalid_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:25:17 by shatan            #+#    #+#             */
/*   Updated: 2024/06/12 15:39:00 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_with_x(char **map, int width, int height, t_vec2 start)
{
	if (start.x < 0 || start.y < 0 || start.x >= width || start.y >= height)
		return ;
	if (map[start.y][start.x] == '1' || map[start.y][start.x] == 'X')
		return ;
	map[start.y][start.x] = 'X';
	flood_fill_with_x(map, width, height, (t_vec2){start.x, start.y - 1});
	flood_fill_with_x(map, width, height, (t_vec2){start.x, start.y + 1});
	flood_fill_with_x(map, width, height, (t_vec2){start.x - 1, start.y});
	flood_fill_with_x(map, width, height, (t_vec2){start.x + 1, start.y});
}

static void	flood_fill_from_player(char **map, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			if (ft_strchr("P", map[y][x]))
				flood_fill_with_x(map, width, height, (t_vec2){x, y});
			y++;
		}
		x++;
	}
}

// extension of ft_is_invalid_map_file, do not use
char	*ft_has_invalid_pathway(char **map, int width, int height)
{
	flood_fill_from_player(map, width, height);
	if (ft_2d_count_charset(map, width, height, "E"))
		return ("Unreachable exit");
	if (ft_2d_count_charset(map, width, height, "C"))
		return ("Unreachable collectibles");
	return (NULL);
}
