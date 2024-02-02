/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init_cords.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:55:04 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 17:04:52 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assign_sprites_loc(t_map_init_cords_loc_data *d)
{
	t_vec2	cord;
	char	c;

	cord = (t_vec2){d->x, d->y};
	c = d->raw_map[d->y][d->x];
	if (c == 'P')
		d->map->player->cord = cord;
	else if (c == 'E')
		d->map->exit->cord = cord;
	else if (c == 'C')
		d->map->coins.arr[(d->idx.coin)++]->cord = cord;
	else if (c == 'S')
		d->map->slimes.arr[(d->idx.slime)++]->cord = cord;
	else if (c == 'B')
		d->map->bees.arr[(d->idx.bee)++]->cord = cord;
}

static t_tile	get_grid_val(char c)
{
	if (c == '1')
		return (TILE_WALL);
	else if (c == '2')
		return (TILE_WATER);
	else if (c == 'E')
		return (TILE_PATH | TILE_EXIT);
	else if (c == 'C')
		return (TILE_PATH | TILE_COIN);
	else if (c == 'P')
		return (TILE_PATH | TILE_PLAYER);
	else if (c == 'S')
		return (TILE_PATH | TILE_SLIME);
	else if (c == 'B')
		return (TILE_PATH | TILE_BEE);
	else
		return (TILE_PATH);
}

void	ft_map_init_cords(t_map *map, char **raw_map, int width, int height)
{
	t_map_init_cords_loc_data	cord;

	cord = (t_map_init_cords_loc_data){map, raw_map, 0, 0, {0, 0, 0}};
	while (cord.y < height)
	{
		cord.x = 0;
		while (cord.x < width)
		{
			map->grid[cord.y][cord.x] = get_grid_val(raw_map[cord.y][cord.x]);
			assign_sprites_loc(&cord);
			cord.x++;
		}
		cord.y++;
	}
}
