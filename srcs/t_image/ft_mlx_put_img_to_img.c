/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_put_img_to_img.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:54:11 by shatan            #+#    #+#             */
/*   Updated: 2024/06/16 23:49:06 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_img_pixel_color(t_image *img, int x, int y)
{
	char	*pixel_ptr;

	pixel_ptr = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)pixel_ptr);
}

void	ft_mlx_put_img_to_img(t_image *dst, t_image *src, int img_x, int img_y)
{
	unsigned int	color;
	t_vec2			curr;
	t_vec2			start;
	t_vec2			end;

	if (!dst || !src)
		return ;
	start = (t_vec2){(img_x <= 0) * -img_x, (img_y <= 0) * -img_y};
	end = (t_vec2){ft_min(src->width, dst->width - img_x),
		ft_min(src->height, dst->height - img_y)};
	curr.x = start.x;
	while (curr.x < end.x)
	{
		curr.y = start.y;
		while (curr.y < end.y)
		{
			color = get_img_pixel_color(src, curr.x, curr.y);
			ft_mlx_pixel_put(dst, img_x + curr.x, img_y + curr.y, color);
			++curr.y;
		}
		++curr.x;
	}
}
