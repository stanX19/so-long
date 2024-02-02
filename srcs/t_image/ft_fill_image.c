/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:58:01 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 16:59:02 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_image_whole(t_image *img, unsigned int color)
{
	t_vec2	start;
	t_vec2	end;

	start = (t_vec2){0, 0};
	end = (t_vec2){img->width, img->height};
	ft_fill_image(img, color, start, end);
}

void	ft_fill_image(t_image *img, unsigned int color,
		t_vec2 start, t_vec2 end)
{
	t_vec2	cord;

	cord = start;
	while (cord.y < end.y)
	{
		cord.x = start.x;
		while (cord.x < end.x)
		{
			ft_mlx_pixel_put(img, cord.x, cord.y, color);
			cord.x++;
		}
		cord.y++;
	}
	return ;
}
