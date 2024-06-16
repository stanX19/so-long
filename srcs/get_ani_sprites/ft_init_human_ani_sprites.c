/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_human_ani_sprites.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:39:25 by stan              #+#    #+#             */
/*   Updated: 2024/06/16 23:56:49 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_human_rel_paths(t_sp_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS])
{
	sp_data[DOWN][ATTACK] = (t_sp_data){PATH_PLAYER_D_ATTACK,
	{0, 0}, {1, 2}, {2, 2}};
	sp_data[DOWN][IDLE] = (t_sp_data){PATH_PLAYER_D_IDLE,
	{0, 0}, {1, 2}, {4, 2}};
	sp_data[DOWN][WALK] = (t_sp_data){PATH_PLAYER_D_WALK,
	{0, 0}, {2, 2}, {4, 2}};
	sp_data[LEFT][ATTACK] = (t_sp_data){PATH_PLAYER_S_ATTACK,
	{0, 0}, {1, 2}, {2, 2}};
	sp_data[LEFT][IDLE] = (t_sp_data){PATH_PLAYER_S_IDLE,
	{0, 0}, {1, 2}, {4, 2}};
	sp_data[LEFT][WALK] = (t_sp_data){PATH_PLAYER_S_WALK,
	{0, 0}, {2, 2}, {4, 2}};
	sp_data[UP][ATTACK] = (t_sp_data){PATH_PLAYER_U_ATTACK,
	{0, 0}, {1, 2}, {2, 2}};
	sp_data[UP][IDLE] = (t_sp_data){PATH_PLAYER_U_IDLE,
	{0, 0}, {1, 2}, {4, 2}};
	sp_data[UP][WALK] = (t_sp_data){PATH_PLAYER_U_WALK,
	{0, 0}, {2, 2}, {4, 2}};
}

static int	get_size(t_sp_data sp_data)
{
	return (sp_data.start.x + sp_data.end.x
		+ (sp_data.end.y - sp_data.start.y - 1) * sp_data.size.x);
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
		ft_printf("Error\n\thuman animated sprites: Invalid grid range for %s",
			sp_data.rel_path);
		return (0);
	}
	img = ft_read_xpm(assets, sp_data.rel_path);
	if (img == NULL)
		return (ft_gen_default_ani_sp(assets, COLOR_RED));
	sprites_arr = ft_generate_sprites_array_rows(img,
			sp_data.end, sp_data.size);
	ret = ft_init_animated_sprite(assets, sprites_arr, get_size(sp_data), 8);
	ret->offset = (t_vec2){-24, -32};
	return (ret);
}

t_ani_sprite	***ft_init_human_ani_sprites(t_assets *assets)
{
	t_ani_sprite	***ret;
	t_sp_data		sp_data[NUM_DIRECTIONS][NUM_ACTIONS];
	int				y;
	int				x;

	ret = (t_ani_sprite ***)ft_calloc_2d(NUM_DIRECTIONS, NUM_ACTIONS,
			sizeof(t_ani_sprite **), sizeof(t_ani_sprite *));
	init_sp_data(sp_data);
	get_human_rel_paths(sp_data);
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
	return (ret);
}
