/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_animated_sprite.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:29:14 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 17:29:39 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_ani_sprite	*ft_init_animated_sprite(t_assets *assets, t_sprite **sprites,
		int length, int frame_interval)
{
	t_ani_sprite	*animated;

	if (sprites == NULL)
		return (0);
	animated = malloc(sizeof(t_ani_sprite));
	if (animated == NULL)
		return (0);
	animated->sprites_arr = sprites;
	animated->length = length;
	animated->frame_interval = frame_interval;
	ft_list_add(&assets->all_ani_sprite, animated);
	return (animated);
}
