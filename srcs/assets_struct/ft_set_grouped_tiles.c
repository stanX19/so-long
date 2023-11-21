#include "so_long.h"

static int get_idx(t_vec2 cord)
{
	return cord.y * 12 + cord.x;
}

static void set_land_hill(t_vec2 vec[3][3])
{
	t_vec2 val[3][3] = {
        {{6, 7}, {7, 6}, {7, 7}},
        {{8, 5}, {0, 0}, {6, 5}},
        {{6, 8}, {7, 4}, {7, 8}},
    };

	ft_memcpy(vec, val, sizeof(val));
}

static void set_hill_land(t_vec2 vec[3][3])
{
	t_vec2 val[3][3] = {
        {{6, 4}, {7, 4}, {8, 4}},
        {{6, 5}, {0, 0}, {8, 5}},
        {{6, 6}, {7, 6}, {8, 6}},
    };

	ft_memcpy(vec, val, sizeof(val));
}

static void	assign_group_sprite(t_vec2 vec[3][3], t_sprite *group[3][3], t_sprite**src)
{
	int x;
	int y;
	int idx;

	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			idx = get_idx(vec[y][x]);
			group[y][x] = src[idx];
			++x;
		}
		++y;
	}
}

void ft_set_grouped_tiles(t_assets *assets)
{
	t_vec2 vec[3][3];

	set_land_hill(vec);
	assign_group_sprite(vec, assets->tiles.land_hill, assets->all_tile);
	set_hill_land(vec);
	assign_group_sprite(vec, assets->tiles.hill_land, assets->all_tile);
}