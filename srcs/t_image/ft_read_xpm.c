/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:52:03 by shatan            #+#    #+#             */
/*   Updated: 2024/06/12 15:30:58 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static inline t_image	*null_with_message(const char *message,
	const char *path)
{
	ft_printf("Error\n\tRead xpm: %s: %s\n", message, path);
	return (0);
}

t_image	*ft_read_xpm(t_assets *assets, char *relative_path)
{
	t_image	*img;

	if (!assets || !relative_path)
		return (null_with_message("Null pointer received", relative_path));
	img = malloc(sizeof(t_image));
	if (!img)
		return (null_with_message("failed to malloc", relative_path));
	img->img = mlx_xpm_file_to_image(assets->mlx, relative_path, &(img->width),
			&(img->height));
	if (!img->img)
	{
		free(img);
		return (null_with_message(strerror(errno), relative_path));
	}
	ft_list_add(&assets->all_img, img);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	img->mlx = assets->mlx;
	return (img);
}
