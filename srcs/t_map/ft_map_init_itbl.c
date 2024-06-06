/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init_itbl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:55:04 by shatan            #+#    #+#             */
/*   Updated: 2024/06/06 00:35:16 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_private.h"

// char, self, faction, on_path, animation resource
t_itbl_dict	*get_itbl_dict(t_assets *assets)
{
	static t_itbl_dict	ret[100];
	const t_itbl_dict	itbl_dict[] = {
	{'0', 0, TILE_PATH, NULL},
	{'1', 0, TILE_WALL, NULL},
	{'2', 0, TILE_WATER, NULL},
	{'P', TILE_PLAYER | TILE_ALLY, TILE_PATH, assets->human},
	{'E', TILE_EXIT, TILE_PATH, assets->portal},
	{'C', TILE_COLLECTIBLE, TILE_PATH, assets->coin},
	{'S', TILE_ENEMY, TILE_PATH, assets->slime},
	{'B', TILE_ENEMY, TILE_PATH, assets->bee},
	{'W', TILE_ALLY, TILE_PATH, assets->wolf},
	{'G', TILE_ENEMY, TILE_PATH, assets->goblin},
	{'L', TILE_PLAYER, TILE_PATH, assets->human},
	{'\0', 0, 0, NULL}};

	ft_memcpy(ret, itbl_dict, sizeof(itbl_dict));
	return (ret);
}

t_itbl_dict	*get_itbl_hash(t_assets *assets)
{
	static t_itbl_dict	hash[256];
	int					idx;
	t_itbl_dict			*dict;

	ft_bzero(hash, sizeof(hash));
	dict = get_itbl_dict(assets);
	idx = 0;
	while (dict[idx].key)
	{
		hash[(int)dict[idx].key] = dict[idx];
		idx++;
	}
	return (hash);
}

static t_itbl	*init_from_cfg(t_itbl_dict *hash, int c, t_vec2 cord)
{
	t_itbl	*ret;

	ret = ft_itbl_copy(hash[c].itbl);
	ft_itbl_set_faction(ret, hash[c].faction);
	ret->cord = cord;
	ret->blocking |= ret->self;
	return (ret);
}

static void	assign_itbl(t_map_init_data *d, char c, t_vec2 cord)
{
	t_itbl	**assign_loc;
	int		idx;

	assign_loc = NULL;
	if (c == 'P')
		assign_loc = &(d->map->player);
	else if (c == 'E')
		assign_loc = &(d->map->exit);
	else if (c == 'C')
		assign_loc = &(d->map->coins.arr[(d->idx.coin)++]);
	idx = 0;
	while (d->dict[idx].key && d->dict[idx].key != c)
	{
		idx++;
	}
	if (d->dict[idx].key == c && d->dict[idx].itbl != NULL)
	{
		if (assign_loc == NULL)
			assign_loc = &(d->map->enemies.arr[(d->idx.enemy)++]);
		*assign_loc = init_from_cfg(d->hash, c, cord);
	}
}

void	ft_map_init_ibtl(t_map *map, char **raw_map, int width, int height)
{
	t_map_init_data	d;
	int				c;
	t_vec2			cord;

	d = (t_map_init_data){map, raw_map, {0, 0}, get_itbl_dict(map->assets),
		get_itbl_hash(map->assets)};
	cord = (t_vec2){0, 0};
	while (cord.y < height)
	{
		cord.x = 0;
		while (cord.x < width)
		{
			c = d.raw_map[cord.y][cord.x];
			map->grid[cord.y][cord.x] = TILE_PATH;
			if (d.hash[c].background)
				map->grid[cord.y][cord.x] = d.hash[c].background;
			if (d.hash[c].itbl)
				map->grid[cord.y][cord.x] |= d.hash[c].itbl->self | d.hash[c].faction;
			assign_itbl(&d, c, cord);
			cord.x++;
		}
		cord.y++;
	}
}
