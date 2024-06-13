/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_coin_ani_sprites.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:44:11 by stan              #+#    #+#             */
/*   Updated: 2024/06/13 22:06:06 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_ani_sprite	*get_animated_sprite(t_assets *assets, t_sp_data sp_data)
{
	t_sprite		**sprites_arr;
	t_image			*img;
	t_ani_sprite	*ret;

	if (!sp_data.rel_path)
		return (0);
	if (sp_data.size.x * sp_data.size.y <= 0)
	{
		ft_printf("Error\n\tcoin animated sprites: Invalid grid range for %s",
			sp_data.rel_path);
		return (0);
	}
	img = ft_read_xpm(assets, sp_data.rel_path);
	if (img == NULL)
		return (ft_gen_default_ani_sp(assets, COLOR_ORANGE));
	sprites_arr = ft_generate_sprites_array_grid(img, sp_data.start,
			sp_data.end, sp_data.size);
	ret = ft_init_animated_sprite(assets, sprites_arr, sp_data.size.x
			* sp_data.size.y, 10);
	ret->offset = (t_vec2){0, 0};
	return (ret);
}

t_ani_sprite	***ft_init_coin_ani_sprites(t_assets *assets)
{
	t_ani_sprite	***ret;
	t_sp_data		sp_data;
	int				y;
	int				x;

	ret = (t_ani_sprite ***)ft_calloc_2d(NUM_DIRECTIONS, NUM_ACTIONS,
			sizeof(t_ani_sprite **), sizeof(t_ani_sprite *));
	sp_data = (t_sp_data){PATH_COIN_D_IDLE, {0, 0}, {15, 1}, {15, 1}};
	y = 0;
	while (y < NUM_DIRECTIONS)
	{
		x = 0;
		while (x < NUM_ACTIONS)
		{
			ret[y][x] = 0;
			x++;
		}
		y++;
	}
	ret[DOWN][IDLE] = get_animated_sprite(assets, sp_data);
	ret[UP][IDLE] = ret[DOWN][IDLE];
	ret[RIGHT][IDLE] = ret[DOWN][IDLE];
	ret[LEFT][IDLE] = ret[DOWN][IDLE];
	return (ret);
}
