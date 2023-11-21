#include "so_long.h"

static t_image *	init_base_image(t_assets *assets, t_vec2 map_size, t_vec2 tile_size)
{
	t_image *	ret;
	size_t		width;
	size_t		height;

	ft_printf("Map grid size: (%i, %i)\n", map_size.x, map_size.y);
	width = (map_size.x * 2 - 1) * tile_size.x;
	height = (map_size.y * 2 - 1) * tile_size.y;
	ft_printf("Background size: (%i, %i)\n", width, height);
	ret = ft_new_image(assets, width, height);

	return ret;
}

t_image *	ft_map_bg_gen(t_map *map, t_assets *assets)
{
	t_image *	ret;
	t_vec2		cord;

	ret = init_base_image(assets, map->grid_size, assets->tile_size);
	cord = (t_vec2){0, 0};
	while (cord.y < map->grid_size.y * 2 - 1)
	{
		cord.x = 0;
		while (cord.x < map->grid_size.x * 2 - 1)
		{
			int x;
			int y;
			t_sprite *sprite;
			t_vec2 mod2;
			mod2 = (t_vec2){cord.x / 2, cord.y / 2};
			
			ft_printf("(%i, %i), (%i, %i)\n", cord.x, cord.y, mod2.x, mod2.y);
			if (cord.x % 2 == 0 && cord.y % 2 == 0)
				sprite = assets->tiles.land_hill[1][1];
			else if (cord.x % 2 == 0 && cord.y % 2 == 1) // top core down core
			{
				x = 1;
				if (map->grid[mod2.y + 1][mod2.x] & map->grid[mod2.y][mod2.x] & (PATH | WALL))
					y = 1;
				else if (map->grid[mod2.y + 1][mod2.x] & WALL) // not same level, down is WALL
					y = 2;
				else
					y = 0;
				sprite = assets->tiles.land_hill[y][x];
			}
			else if (cord.x % 2 == 1 && cord.y % 2 == 0)
			{
				y = 1;
				if (map->grid[mod2.y][mod2.x + 1] & map->grid[mod2.y][mod2.x] & (PATH | WALL))
					x = 1;
				else if (map->grid[mod2.y][mod2.x + 1] & WALL) // not same level, right is WALL
					x = 2;
				else
					x = 0;
				sprite = assets->tiles.land_hill[y][x];
			}
			else // corner base
			{
				int c1, c2, c3, c4;
				int	land_hill = 1;

				c1 = map->grid[mod2.y][mod2.x];
				c2 = map->grid[mod2.y][mod2.x + 1];
				c3 = map->grid[mod2.y + 1][mod2.x];
				c4 = map->grid[mod2.y + 1][mod2.x + 1];
				
				if (c1 & c2 & c3 & c4 & (WALL | PATH))
				{
					x = 1;
					y = 1;
				}
				else if ((c1 & c2 & (WALL | PATH)) && (c3 & c4 & (WALL | PATH)))
				{
					x = 1;
					if (c1 & c2 & WALL) // top is wall
						y = 0;
					else
						y = 2;
				}
				else if ((c1 & c3 & (WALL | PATH)) && (c2 & c4 & (WALL | PATH)))
				{
					y = 1;
					if (c1 & c3 & WALL) // left is wall
						x = 0;
					else
						x = 2;
				}
				else
				{
					land_hill = 0;
				}
				if (land_hill)
					sprite = assets->tiles.land_hill[y][x];
				else
				{
					++cord.x;
					continue;
				}

			}
			ft_mlx_put_sprite(ret, sprite,
				cord.x * assets->tile_size.x, cord.y * assets->tile_size.y);

			++cord.x;
		}
		++cord.y;
	}
	// cord = (t_vec2){0, 0};
	// while (cord.y < map->grid_size.y * 3)
	// {
	// 	cord.x = 0;
	// 	while (cord.x < map->grid_size.x * 3)
	// 	{
	// 		int pattern[4] = {0, 1, 2 ,1};
	// 		ft_mlx_put_sprite(ret,
	// 			assets->tiles.land_hill[pattern[cord.y % 4]][pattern[cord.x % 4]],
	// 			cord.x * assets->tile_size.x, cord.y * assets->tile_size.y);
	// 		++cord.x;
	// 	}
	// 	++cord.y;
	// }

	return ret;
}