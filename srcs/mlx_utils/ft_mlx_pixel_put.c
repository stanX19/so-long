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
	t_color	clrA;
	t_color	clrB;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));

	clrA.trgb = color;
	clrB.trgb = *(unsigned int *)dst;

	clrB.t = (char)0;
	clrB.r = (char)(((clrA.r * (255 - clrA.t)) + (clrB.r * clrA.t)) / 255);
	clrB.g = (char)(((clrA.g * (255 - clrA.t)) + (clrB.g * clrA.t)) / 255);
	clrB.b = (char)(((clrA.b * (255 - clrA.t)) + (clrB.b * clrA.t)) / 255);

	*(unsigned int *)dst = clrB.trgb;
}
