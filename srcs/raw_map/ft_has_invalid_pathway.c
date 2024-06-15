/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_invalid_pathway.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:25:17 by shatan            #+#    #+#             */
/*   Updated: 2024/06/15 17:31:31 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_invalid_cord(char **map, t_vec2 cord, int width, int height)
{
	if (cord.x < 0 || cord.y < 0 || cord.x >= width || cord.y >= height
		|| ft_strchr("12X", map[cord.y][cord.x]) != NULL)
		return (1);
	return (0);
}

int	propagate(char **map, t_vec2 *stack, int width, int height)
{
	const t_vec2	d[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	t_vec2			curr;
	t_vec2			new;
	int				idx;
	int				i;

	idx = 0;
	curr = stack[idx--];
	map[curr.y][curr.x] = 'X';
	i = 0;
	while (i < 4)
	{
		new = vec2_add(curr, d[i]);
		if (!is_invalid_cord(map, new, width, height))
			stack[++idx] = new;
		i++;
	}
	return (idx);
}

void	flood_fill_with_x(char **map, int width, int height, t_vec2 start)
{
	t_vec2	*stack;
	int		top;

	if (is_invalid_cord(map, start, width, height))
		return ;
	stack = (t_vec2 *)malloc(width * height * sizeof(t_vec2));
	if (!stack)
		return ;
	top = -1;
	stack[++top] = start;
	while (top >= 0)
	{
		top += propagate(map, stack + top, width, height);
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
