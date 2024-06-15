/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:42:59 by shatan            #+#    #+#             */
/*   Updated: 2024/06/15 17:28:32 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	*init_memory(char **raw_map, int width, int height,
		t_assets *assets)
{
	t_map	*map;
	char	*enemy_c;

	enemy_c = ft_get_enemy_charset();
	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	map->grid = (t_tile **)ft_calloc_2d(height, width, sizeof(t_tile *),
			sizeof(t_tile));
	map->coins.len = ft_2d_count_val(raw_map, width, height, 'C');
	map->enemies.len = ft_2d_count_charset(raw_map, width, height, enemy_c);
	map->coins.arr = (t_itbl **)ft_calloc(sizeof(t_itbl *), map->coins.len);
	map->enemies.arr = (t_itbl **)ft_calloc(sizeof(t_itbl *), map->enemies.len);
	map->grid_size.x = width;
	map->grid_size.y = height;
	map->assets = assets;
	map->raw.grid = raw_map;
	map->raw.width = width;
	map->raw.height = height;
	return (map);
}

t_map	*ft_map_init(const char *path, t_assets *assets)
{
	t_map	*map;
	char	**raw_map;
	size_t	width;
	size_t	height;

	raw_map = ft_gen_raw_map_safe(path, &width, &height);
	if (raw_map == NULL)
		return (NULL);
	map = init_memory(raw_map, width, height, assets);
	ft_map_init_ibtl(map);
	map->bkg_img = ft_map_bg_gen(map, assets);
	map->assets = assets;
	return (map);
}
