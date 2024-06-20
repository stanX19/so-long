/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_WOLF_ani_sprites.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:35:18 by stan              #+#    #+#             */
/*   Updated: 2024/02/14 17:48:52 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_wolf_rel_paths(t_sp_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS])
{
	sp_data[UP][DEATH] = (t_sp_data){PATH_WOLF_U_DEATH,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[UP][WALK] = (t_sp_data){PATH_WOLF_U_WALK,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[UP][ATTACK] = (t_sp_data){PATH_WOLF_U_ATTACK,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[DOWN][DEATH] = (t_sp_data){PATH_WOLF_D_DEATH,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[DOWN][WALK] = (t_sp_data){PATH_WOLF_D_WALK,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[DOWN][ATTACK] = (t_sp_data){PATH_WOLF_D_ATTACK,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[LEFT][DEATH] = (t_sp_data){PATH_WOLF_S_DEATH,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[LEFT][WALK] = (t_sp_data){PATH_WOLF_S_WALK,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[LEFT][ATTACK] = (t_sp_data){PATH_WOLF_S_ATTACK,
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
		ft_printf("Error\n\tWOLF animated sprites: Invalid grid range for %s",
			rel_path);
		return (0);
	}
	img = ft_read_xpm(assets, rel_path);
	if (img == NULL)
		return (ft_gen_default_ani_sp(assets, COLOR_GRAY));
	sprites_arr = ft_generate_sprites_array_grid(img, (t_vec2){0, 0}, size,
			size);
	ret = ft_init_animated_sprite(assets, sprites_arr, size.x * size.y, 8);
	ret->offset = (t_vec2){-16, -16};
	return (ret);
}

t_ani_sprite	***ft_init_wolf_ani_sprites(t_assets *assets)
{
	t_ani_sprite	***ret;
	t_sp_data		sp_data[NUM_DIRECTIONS][NUM_ACTIONS];
	int				y;
	int				x;

	ret = (t_ani_sprite ***)ft_calloc_2d(NUM_DIRECTIONS, NUM_ACTIONS,
			sizeof(t_ani_sprite **), sizeof(t_ani_sprite *));
	init_sp_data(sp_data);
	get_wolf_rel_paths(sp_data);
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
