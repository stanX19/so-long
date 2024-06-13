/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_default_ani_sprite.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:35:40 by stan              #+#    #+#             */
/*   Updated: 2024/06/13 19:47:19 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_ani_sprite	*ft_gen_default_ani_sp(t_assets *assets,
		unsigned int color)
{
	t_sprite		**sprites_arr;
	t_image			*img;
	t_ani_sprite	*ret;

	img = ft_new_colored_image(assets, 16, 16, COLOR_BLACK);
	ft_fill_image(img, color, (t_vec2){2, 2}, (t_vec2){14, 14});
	sprites_arr = ft_generate_sprites_array_grid(img, (t_vec2){0, 0},
			(t_vec2){1, 1}, (t_vec2){1, 1});
	ret = ft_init_animated_sprite(assets, sprites_arr, 1, 10);
	return (ret);
}
