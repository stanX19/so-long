#include "so_long.h"
# define START (t_vec2){0, 0}
# define END SIZE
# define SIZE (t_vec2){16, 3}

static int get_idx(t_vec2 cord)
{
	return cord.y * SIZE.x + cord.x;
}

// static void	assign_group_sprite(t_vec2 vec[3][3], t_sprite *group[3][3], t_sprite**src)
// {
// 	int x;
// 	int y;
// 	int idx;

// 	y = 0;
// 	while (y < 3)
// 	{
// 		x = 0;
// 		while (x < 3)
// 		{
// 			if (!src)
// 			{
// 				group[y][x++] = 0;
// 				continue ;
// 			}
// 			idx = get_idx(vec[y][x]);
// 			group[y][x] = src[idx];
// 			++x;
// 		}
// 		++y;
// 	}
// }

// static void idx_to_3x3_vec2(t_vec2 vec[3][3], int idx)
// {
// 	t_vec2 cord;
// 	t_vec2 target;

// 	target.x = (idx % 3) * 3;
// 	target.y = idx / 3 * 3;
// 	cord = (t_vec2){0, 0};
// 	while (cord.y < 3)
// 	{
// 		cord.x = 0;
// 		while (cord.x < 3)
// 		{
// 			vec[cord.y][cord.x] = (t_vec2){target.x + cord.x, target.y + cord.y};
// 			++cord.x;
// 		}
// 		++cord.y;
// 	}
// }

// static void set_grouped_tiles(t_assets *assets, t_sprite**src)
// {
// 	t_vec2 vec[3][3];

// 	idx_to_3x3_vec2(vec, 1);
// 	assign_group_sprite(vec, assets->tiles.path_hill, src);
// 	idx_to_3x3_vec2(vec, 0);
// 	assign_group_sprite(vec, assets->tiles.hill_path, src);
// 	assign_group_sprite(vec, assets->tiles.hill_hill, 0);
// 	assign_group_sprite(vec, assets->tiles.water_path, 0);
// 	assign_group_sprite(vec, assets->tiles.path_water, 0);
// 	assign_group_sprite(vec, assets->tiles.water_water, 0);
// }

static void set_grouped_tiles(t_assets *assets, t_sprite**src)
{
	int x;

	x = 0;
	while (x < 16)
	{
		assets->tiles.path_hill[x] = src[get_idx((t_vec2){x, 0})];
		assets->tiles.water_path[x] = src[get_idx((t_vec2){x, 1})];
		assets->tiles.path_tree[x] = src[get_idx((t_vec2){x, 2})];
		++x;
	}
}

t_sprite** ft_init_connected_grass_tileset(t_assets *assets)
{
	t_image *	img;
	t_sprite **	ret;
	
	img = ft_read_xpm(assets, "./assets/sprites/tileset_grass_connected.xpm");
	if (!img)
	{
		assets->tile_size.y = 0;
		assets->tile_size.x = 0;
		assets->all_tile_len = 0;
		set_grouped_tiles(assets, 0);
		return 0;
	}
	ret = ft_generate_sprites_array_grid(img, (t_vec2){0, 0}, (t_vec2){9 ,9}, (t_vec2){9 ,9});
	if (!ret)
		return 0;
	assets->all_tile_len = SIZE.x * SIZE.y;
	assets->tile_size.y = ret[0]->height;
	assets->tile_size.x = ret[0]->width;
	set_grouped_tiles(assets, ret);
	return ret;
}