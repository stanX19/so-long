/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:49:23 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 17:49:33 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// #include <assert.h>
// assert(x < img->width);
// assert(y < img->height);
void	ft_mlx_pixel_put(t_image *img, int x, int y, unsigned int color)
{
	char	*dst;
	t_color	clr_a;
	t_color	clr_b;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	clr_a.trgb = color;
	clr_b.trgb = *(unsigned int *)dst;
	clr_b.t = (char)0;
	clr_b.r = (char)(((clr_a.r * (255 - clr_a.t)) + (clr_b.r * clr_a.t)) / 255);
	clr_b.g = (char)(((clr_a.g * (255 - clr_a.t)) + (clr_b.g * clr_a.t)) / 255);
	clr_b.b = (char)(((clr_a.b * (255 - clr_a.t)) + (clr_b.b * clr_a.t)) / 255);
	*(unsigned int *)dst = clr_b.trgb;
}
