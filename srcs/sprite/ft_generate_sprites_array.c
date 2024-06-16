/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_sprites_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:29:58 by shatan            #+#    #+#             */
/*   Updated: 2024/06/16 23:32:18 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_range(t_vec2 start, t_vec2 end, t_vec2 grid_size)
{
	if (start.x < 0 || start.y < 0 || end.x > grid_size.x
		|| end.y > grid_size.y)
		return (0);
	if (grid_size.x * grid_size.y == 0)
		return (0);
	return (1);
}

t_sprite	**ft_generate_sprites_array_rows(t_image *image,
		t_vec2 end, t_vec2 grid_size)
{
	int			total_length;
	int			idx;
	int			x;
	int			y;
	t_sprite	**ret;

	if (image == NULL || !is_valid_range((t_vec2){0, 0}, end, grid_size))
		return (0);
	total_length = end.x + (end.y - 1) * grid_size.x;
	ret = malloc(sizeof(t_sprite *) * total_length);
	idx = 0;
	y = 0;
	while (y < end.y - 1)
	{
		x = 0;
		while (x < grid_size.x)
			ret[idx++] = ft_init_sprite(image, x++, y, grid_size);
		++y;
	}
	x = 0;
	while (x < end.x)
		ret[idx++] = ft_init_sprite(image, x++, end.y - 1, grid_size);
	return (ret);
}

t_sprite	**ft_generate_sprites_array_grid(t_image *image, t_vec2 start,
		t_vec2 end, t_vec2 grid_size)
{
	size_t		total_length;
	int			idx;
	t_sprite	**ret;
	int			x;
	int			y;

	if (image == NULL || !is_valid_range(start, end, grid_size))
		return (0);
	total_length = (end.x - start.x) * (end.y - start.y);
	ret = malloc(sizeof(t_sprite *) * total_length);
	idx = 0;
	y = start.y;
	while (y < end.y)
	{
		x = start.x;
		while (x < end.x)
		{
			ret[idx++] = ft_init_sprite(image, x, y, grid_size);
			x++;
		}
		y++;
	}
	return (ret);
}
