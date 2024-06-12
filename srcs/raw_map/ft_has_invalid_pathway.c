/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_invalid_pathway.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:25:17 by shatan            #+#    #+#             */
/*   Updated: 2024/06/12 18:33:06 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_with_x(char **map, int width, int height, t_vec2 start)
{
	t_vec2	*stack;
	int		top;
	t_vec2	curr;

	stack = (t_vec2 *)malloc((width * 2) * (height * 2) * sizeof(t_vec2));
	if (!stack)
		return ;
	top = -1;
	stack[++top] = start;
	while (top >= 0)
	{
		curr = stack[top--];
		if (curr.x < 0 || curr.y < 0 || curr.x >= width || curr.y >= height
			|| map[curr.y][curr.x] == '1' || map[curr.y][curr.x] == 'X')
			continue ;
		map[curr.y][curr.x] = 'X';
		stack[++top] = (t_vec2){curr.x, curr.y - 1};
		stack[++top] = (t_vec2){curr.x, curr.y + 1};
		stack[++top] = (t_vec2){curr.x - 1, curr.y};
		stack[++top] = (t_vec2){curr.x + 1, curr.y};
	}
	free(stack);
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
			if (strchr("P", map[y][x]))
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
