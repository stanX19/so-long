/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_destory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:57:23 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 16:57:25 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image_destory(t_image *image)
{
	if (image == 0 || image->img == 0)
	{
		ft_printf("Null image passed to ft_image_destory\n");
		return ;
	}
	mlx_destroy_image(image->mlx, image->img);
	free(image);
}
