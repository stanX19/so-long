/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_bg_gen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:03:32 by shatan            #+#    #+#             */
/*   Updated: 2024/06/12 18:52:16 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		get_tile_size(int x);
int		binary_4bit(int num4, int num3, int num2, int num1);
void	map_equal_to(t_tile c[4], int val);
void	map_not_equal_to(t_tile c[4], unsigned int val);

static t_image	*init_base_image(t_assets *assets, t_vec2 map_size,
		t_vec2 tile_size)
{
	t_image	*ret;
	size_t	width;
	size_t	height;

	width = get_tile_size(map_size.x) * tile_size.x;
	height = get_tile_size(map_size.y) * tile_size.y;
	ret = ft_new_image(assets, width, height);
	return (ret);
}

t_sprite	*get_corres_sprite(t_tile c[4], t_assets *assets)
{
	t_sprite	**type;
	int			val;

	val = ((c[0] | c[1] | c[2] | c[3]) & (TILE_PATH | TILE_WALL | TILE_WATER));
	type = assets->tiles.water_path;
	if (val == (TILE_PATH | TILE_WALL) || val == (TILE_PATH)
		|| val == (TILE_WALL))
	{
		type = assets->tiles.path_wall;
		map_equal_to(c, TILE_WALL);
	}
	else if (val == (TILE_PATH | TILE_WATER) || (val & TILE_WATER))
	{
		type = assets->tiles.water_path;
		map_not_equal_to(c, TILE_WATER);
	}
	val = binary_4bit(c[0], c[1], c[2], c[3]);
	if ((type == assets->tiles.path_wall && val == 0)
		|| (type == assets->tiles.water_path && val == 15))
	{
		type = assets->tiles.all_grass;
		val = (rand() % 4 == 0) * rand() % 16;
	}
	return (type[val % 16]);
}

static void	process_cord(t_image *img, t_map *map, t_assets *assets,
		t_vec2 cord)
{
	t_tile	c[4];

	c[0] = map->grid[cord.y / 2][cord.x / 2];
	c[1] = map->grid[cord.y / 2][cord.x / 2 + (cord.x % 2)];
	c[2] = map->grid[cord.y / 2 + (cord.y % 2)][cord.x / 2];
	c[3] = map->grid[cord.y / 2 + (cord.y % 2)][cord.x / 2 + (cord.x % 2)];
	cord.x *= assets->tile_size.x;
	cord.y *= assets->tile_size.y;
	ft_mlx_put_sprite(img, get_corres_sprite(c, assets), cord.x, cord.y);
}

t_image	*ft_map_bg_gen(t_map *map, t_assets *assets)
{
	t_image	*ret;
	t_vec2	cord;
	t_vec2	end;

	ret = init_base_image(assets, map->grid_size, assets->tile_size);
	cord = (t_vec2){0, 0};
	end = (t_vec2){get_tile_size(map->grid_size.x),
		get_tile_size(map->grid_size.y)};
	while (cord.y < end.y)
	{
		cord.x = 0;
		while (cord.x < end.x)
		{
			process_cord(ret, map, assets, cord);
			++cord.x;
		}
		++cord.y;
	}
	return (ret);
}
