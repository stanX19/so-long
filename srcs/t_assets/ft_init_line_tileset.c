/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_line_tileset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:05:58 by shatan            #+#    #+#             */
/*   Updated: 2024/06/11 14:19:06 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define TILESET_START_X 0
#define TILESET_START_Y 0
#define TILESET_SIZE_X 16
#define TILESET_SIZE_Y 4

static int	get_idx(t_vec2 cord)
{
	return (cord.y * TILESET_SIZE_X + cord.x);
}

static void	set_grouped_tiles(t_assets *assets, t_sprite **src)
{
	int	x;

	x = 0;
	while (x < TILESET_SIZE_X)
	{
		assets->tiles.path_wall[x] = src[get_idx((t_vec2){x, 0})];
		assets->tiles.water_path[x] = src[get_idx((t_vec2){x, 1})];
		assets->tiles.path_tree[x] = src[get_idx((t_vec2){x, 2})];
		assets->tiles.all_grass[x] = src[get_idx((t_vec2){x, 3})];
		++x;
	}
}

t_sprite	**ft_init_line_fmt_tileset(t_assets *assets, char *path)
{
	t_image		*img;
	t_sprite	**ret;

	img = ft_read_xpm(assets, path);
	if (!img)
	{
		ft_printf("Assets missing: Using default tilesets\n");
		img = ft_default_tileset_gen(assets,
				(t_vec2){TILESET_SIZE_X, TILESET_SIZE_Y});
	}
	ret = ft_generate_sprites_array_grid(img,
			(t_vec2){TILESET_START_X, TILESET_START_Y},
			(t_vec2){TILESET_SIZE_X, TILESET_SIZE_Y},
			(t_vec2){TILESET_SIZE_X, TILESET_SIZE_Y});
	if (!ret)
		return (0);
	assets->all_tile_len = TILESET_SIZE_X * TILESET_SIZE_Y;
	assets->tile_size.y = ret[0]->height;
	assets->tile_size.x = ret[0]->width;
	set_grouped_tiles(assets, ret);
	return (ret);
}
