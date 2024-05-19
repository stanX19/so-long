/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_interactable_to_img.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:19:07 by stan              #+#    #+#             */
/*   Updated: 2024/02/14 17:28:08 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_interactable_to_img(t_image *base_img, t_itbl *itbl, int x,
		int y)
{
	if (!itbl->animation)
		return ;
	if (itbl->flip)
		ft_mlx_put_sprite_reverse(base_img,
			itbl->animation->sprites_arr[itbl->sprite_idx], x, y);
	else
		ft_mlx_put_sprite(base_img,
			itbl->animation->sprites_arr[itbl->sprite_idx], x, y);
}
