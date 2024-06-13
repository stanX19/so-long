/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bee_ani_sprites.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:46:46 by stan              #+#    #+#             */
/*   Updated: 2024/06/13 20:24:03 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_bee_rel_paths(t_sp_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS])
{
	sp_data[UP][DEATH] = (t_sp_data){PATH_BEE_U_DEATH,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[UP][WALK] = (t_sp_data){PATH_BEE_U_WALK,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[DOWN][DEATH] = (t_sp_data){PATH_BEE_D_DEATH,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[DOWN][WALK] = (t_sp_data){PATH_BEE_D_WALK,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[LEFT][DEATH] = (t_sp_data){PATH_BEE_S_DEATH,
	{0, 0}, {6, 1}, {6, 1}};
	sp_data[LEFT][WALK] = (t_sp_data){PATH_BEE_S_WALK,
	{0, 0}, {6, 1}, {6, 1}};
}

static t_ani_sprite	*get_animated_sprite(t_assets *assets, t_sp_data sp_data)
{
	t_sprite		**sprites_arr;
	t_image			*img;
	t_ani_sprite	*ret;

	if (!sp_data.rel_path)
		return (0);
	if (sp_data.size.x * sp_data.size.y <= 0)
	{
		ft_printf("Error\n\tBee animated sprites: Invalid grid range for %s",
			sp_data.rel_path);
		return (0);
	}
	img = ft_read_xpm(assets, sp_data.rel_path);
	if (img == NULL)
		return (ft_gen_default_ani_sp(assets, COLOR_YELLOW));
	sprites_arr = ft_generate_sprites_array_grid(img, sp_data.start,
			sp_data.end, sp_data.size);
	ret = ft_init_animated_sprite(assets, sprites_arr, sp_data.size.x
			* sp_data.size.y, 10);
	ret->offset = (t_vec2){-16, -16};
	return (ret);
}

t_ani_sprite	***ft_init_bee_ani_sprites(t_assets *assets)
{
	t_ani_sprite	***ret;
	t_sp_data		sp_data[NUM_DIRECTIONS][NUM_ACTIONS];
	int				y;
	int				x;

	ret = (t_ani_sprite ***)ft_calloc_2d(NUM_DIRECTIONS, NUM_ACTIONS,
			sizeof(t_ani_sprite **), sizeof(t_ani_sprite *));
	init_sp_data(sp_data);
	get_bee_rel_paths(sp_data);
	y = 0;
	while (y < NUM_DIRECTIONS)
	{
		x = 0;
		while (x < NUM_ACTIONS)
		{
			ret[y][x] = get_animated_sprite(assets, sp_data[y][x]);
			++x;
		}
		++y;
	}
	ret[UP][IDLE] = ret[UP][WALK];
	ret[DOWN][IDLE] = ret[DOWN][WALK];
	ret[LEFT][IDLE] = ret[LEFT][WALK];
	return (ret);
}
