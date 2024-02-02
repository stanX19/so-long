/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:28:32 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 17:28:46 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	*ft_init_sprite(t_image *img, int x, int y, t_vec2 grid_size)
{
	t_sprite	*new_sprite;

	if (!img)
		return (0);
	new_sprite = malloc(sizeof(t_sprite));
	if (new_sprite == NULL)
		return (0);
	new_sprite->width = img->width / grid_size.x;
	new_sprite->height = img->height / grid_size.y;
	x *= new_sprite->width;
	y *= new_sprite->height;
	new_sprite->addr = img->addr + (y * img->line_length + x
			* (img->bits_per_pixel / 8));
	new_sprite->line_length = img->line_length;
	new_sprite->bits_per_pixel = img->bits_per_pixel;
	return (new_sprite);
}
