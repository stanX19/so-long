#include "so_long.h"
#define TILE_SIZE(x) (x * 2 - 1)
#define BINARY_4BIT(num4, num3, num2, num1) \
    ((num4 << 3) | (num3 << 2) | (num2 << 1) | (num1))
#define MAP_EQL_TO(c, val)\
	c[0] = ((c[0] & val) == val);\
	c[1] = ((c[1] & val) == val);\
	c[2] = ((c[2] & val) == val);\
	c[3] = ((c[3] & val) == val);\

static t_image *	init_base_image(t_assets *assets, t_vec2 map_size, t_vec2 tile_size)
{
	t_image *	ret;
	size_t		width;
	size_t		height;

	ft_printf("Map grid size: (%i, %i)\n", map_size.x, map_size.y);
	width = TILE_SIZE(map_size.x) * tile_size.x;
	height = TILE_SIZE(map_size.y) * tile_size.y;
	ft_printf("Background size: (%i, %i)\n", width, height);
	ret = ft_new_image(assets, width, height);

	return ret;
}

t_sprite *	get_corres_sprite(t_tile c[4], t_assets *assets)
{
	t_sprite ** type;
	int			val;


	val = ((c[0] | c[1] | c[2] | c[3]) & (PATH | WALL | WATER));
	if (val == (PATH | WALL) || val == (PATH) || val == (WALL))
	{
		type = assets->tiles.path_wall;
		MAP_EQL_TO(c, WALL);
	}
	else if (val == (PATH | WATER) || val == WATER)
	{
		type = assets->tiles.water_path;
		MAP_EQL_TO(c, PATH);
	}
	else
	{
		ft_printf("ERROR: Map bg gen: no matching tiles: %i %i %i %i\n", c[0], c[1], c[2], c[3]);
		return 0;
	}

	return type[BINARY_4BIT(c[0], c[1], c[2], c[3])];
}

static void	process_cord(t_image *	img, t_map *map, t_assets *assets, t_vec2 cord)
{
	t_tile c[4];

	c[0] = map->grid[cord.y / 2][cord.x / 2];
	c[1] = map->grid[cord.y / 2][cord.x / 2 + (cord.x % 2)];
	c[2] = map->grid[cord.y / 2 + (cord.y % 2)][cord.x / 2];
	c[3] = map->grid[cord.y / 2 + (cord.y % 2)][cord.x / 2 + (cord.x % 2)];

	cord.x *= assets->tile_size.x;
	cord.y *= assets->tile_size.y;
	ft_mlx_put_sprite(img, get_corres_sprite(c, assets), cord.x, cord.y);
}

t_image *	ft_map_bg_gen(t_map *map, t_assets *assets)
{
	t_image *	ret;
	t_vec2		cord;
	t_vec2		end;

	ret = init_base_image(assets, map->grid_size, assets->tile_size);
	cord = (t_vec2){0, 0};
	end = (t_vec2){TILE_SIZE(map->grid_size.x), TILE_SIZE(map->grid_size.y)};

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

	return ret;
}

#undef TILE_SIZE
#undef BINARY_4BIT
#undef MAP_EQL_TO