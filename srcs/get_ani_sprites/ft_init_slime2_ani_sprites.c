/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_slime2_ani_sprites.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:37:16 by stan              #+#    #+#             */
/*   Updated: 2024/06/11 14:11:39 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_slime2_rel_paths(t_sp_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS])
{
	sp_data[UP][DEATH] = (t_sp_data){PATH_SLIME_U_DEATH2,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[UP][WALK] = (t_sp_data){PATH_SLIME_U_WALK2,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[DOWN][DEATH] = (t_sp_data){PATH_SLIME_D_DEATH2,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[DOWN][WALK] = (t_sp_data){PATH_SLIME_D_WALK2,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[LEFT][DEATH] = (t_sp_data){PATH_SLIME_S_DEATH2,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[LEFT][WALK] = (t_sp_data){PATH_SLIME_S_WALK2,
	{0, 0}, {6, 1}, {6, 1}};
}

static t_ani_sprite	*get_animated_sprite(t_assets *assets, char *rel_path,
		t_vec2 size)
{
	t_sprite		**sprites_arr;
	t_image			*img;
	t_ani_sprite	*ret;

	if (!rel_path)
		return (0);
	if (size.x * size.y <= 0)
	{
		ft_printf("Error\n\tSlime2 animated sprites: Invalid grid range for %s",
			rel_path);
		return (0);
	}
	img = ft_read_xpm(assets, rel_path);
	sprites_arr = ft_generate_sprites_array_grid(img, (t_vec2){0, 0}, size,
			size);
	ret = ft_init_animated_sprite(assets, sprites_arr, size.x * size.y, 10);
	return (ret);
}

t_ani_sprite	***ft_init_slime2_ani_sprites(t_assets *assets)
{
	t_ani_sprite	***ret;
	t_sp_data		sp_data[NUM_DIRECTIONS][NUM_ACTIONS];
	int				y;
	int				x;

	ret = (t_ani_sprite ***)ft_calloc_2d(NUM_DIRECTIONS, NUM_ACTIONS,
			sizeof(t_ani_sprite **), sizeof(t_ani_sprite *));
	init_sp_data(sp_data);
	get_slime2_rel_paths(sp_data);
	y = 0;
	while (y < NUM_DIRECTIONS)
	{
		x = 0;
		while (x < NUM_ACTIONS)
		{
			ret[y][x] = get_animated_sprite(assets, sp_data[y][x].rel_path,
					sp_data[y][x].size);
			++x;
		}
		++y;
	}
	ret[UP][IDLE] = ret[UP][WALK];
	ret[DOWN][IDLE] = ret[DOWN][WALK];
	ret[LEFT][IDLE] = ret[LEFT][WALK];
	return (ret);
}
