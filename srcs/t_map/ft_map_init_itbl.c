/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init_itbl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:55:04 by shatan            #+#    #+#             */
/*   Updated: 2024/06/15 18:04:07 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_private.h"

static t_itbl	*init_from_cfg(const t_itbl_dict *hash, int c, t_vec2 cord)
{
	t_itbl	*ret;

	ret = ft_itbl_copy(hash[c].itbl);
	ft_itbl_set_faction(ret, hash[c].faction);
	ret->cord = cord;
	return (ret);
}

static t_itbl	**find_assign_loc(t_map_init_data *d, char c)
{
	if (c == 'P')
		return (&(d->map->player));
	else if (c == 'E')
		return (&(d->map->exit));
	else if (c == 'C')
		return (&(d->map->coins.arr[(d->idx.coin)++]));
	else if (d->hash[(int)c].itbl)
		return (&(d->map->enemies.arr[(d->idx.enemy)++]));
	return (NULL);
}

static void	assign_itbl(t_map_init_data *d, char c, t_vec2 cord)
{
	t_itbl	**assign_loc;

	assign_loc = find_assign_loc(d, c);
	if (assign_loc != NULL)
		*assign_loc = init_from_cfg(d->hash, c, cord);
}

void	ft_map_init_ibtl(t_map *map)
{
	t_map_init_data	d;
	int				c;
	t_vec2			cord;

	d = (t_map_init_data){map, {0, 0}, ft_get_itbl_dict(map->assets),
		ft_get_itbl_hash(map->assets)};
	cord = (t_vec2){0, 0};
	while (cord.y < map->raw.height)
	{
		cord.x = 0;
		while (cord.x < map->raw.width)
		{
			c = map->raw.grid[cord.y][cord.x];
			map->grid[cord.y][cord.x] = TILE_PATH;
			if (d.hash[c].background)
				map->grid[cord.y][cord.x] = d.hash[c].background;
			if (d.hash[c].itbl)
				map->grid[cord.y][cord.x] |= d.hash[c].itbl->self
					| d.hash[c].faction;
			assign_itbl(&d, c, cord);
			cord.x++;
		}
		cord.y++;
	}
}
