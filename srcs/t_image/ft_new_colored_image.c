/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_colored_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:32:50 by stan              #+#    #+#             */
/*   Updated: 2024/06/13 18:32:51 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*ft_new_colored_image(t_assets *assets, int width, int height,
		unsigned int color)
{
	t_image	*img;

	img = ft_new_image(assets, width, height);
	ft_fill_image_whole(img, color);
	return (img);
}
