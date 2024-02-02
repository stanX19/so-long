/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:52:03 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 16:52:03 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static inline t_image	*null_with_message(char *message)
{
	ft_printf("ERROR: Read xpm: %s\n", message);
	return (0);
}

t_image	*ft_read_xpm(t_assets *assets, char *relative_path)
{
	t_image	*img;

	if (!assets || !relative_path)
		return (null_with_message("Warning: Read xpm: null pointer received"));
	img = malloc(sizeof(t_image));
	if (!img)
		return (null_with_message("failed to malloc"));
	img->img = mlx_xpm_file_to_image(assets->mlx, relative_path, &(img->width),
			&(img->height));
	if (!img->img)
	{
		free(img);
		return (null_with_message(strerror(errno)));
	}
	ft_list_add(&assets->all_img, img);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	img->mlx = assets->mlx;
	return (img);
}
