/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_delete_game.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:51:02 by stan              #+#    #+#             */
/*   Updated: 2024/06/12 13:28:31 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// ft_printf("%i %i\n", size.x, size.y);
// base image that all sprites will be printed on, then put on window
static t_image	*get_base_img(t_assets *assets, t_image *bkg_img)
{
	t_vec2	size;

	size.x = ft_min(1800, bkg_img->width);
	size.y = ft_min(900, bkg_img->height);
	return (ft_new_image(assets, size.x, size.y));
}

void	ft_init_game(t_vars *vars)
{
	vars->map = ft_map_init(vars->paths[vars->idx], vars->assets);
	if (!vars->map)
	{
		ft_delete_vars(vars);
		exit(1);
		return ;
	}
	vars->base_img = get_base_img(vars->assets, vars->map->bkg_img);
	vars->window = ft_window_init(vars->mlx, vars->base_img->width,
			vars->base_img->height, vars->title);
	ft_hook_listeners(vars);
}

void	ft_delete_game(t_vars *vars)
{
	if (!vars)
		return ;
	if (vars->map)
		ft_map_destory(vars->map);
	if (vars->base_img)
	{
		ft_list_remove(&vars->assets->all_img, vars->base_img);
		ft_image_destory(vars->base_img);
	}
	if (vars->window)
		ft_window_destory(vars->window);
}

void	ft_new_game(t_vars *vars)
{
	ft_delete_game(vars);
	ft_init_game(vars);
}
