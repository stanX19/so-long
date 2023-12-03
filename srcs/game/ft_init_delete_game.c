#include "so_long.h"

void	ft_init_game(t_vars* vars)
{
	vars->map = ft_map_init(vars->paths[vars->idx], vars->assets);
	vars->base_img = ft_new_image(vars->assets, vars->map->bkg_img->width, vars->map->bkg_img->height);
    vars->window = ft_window_init(vars->mlx, vars->base_img->width, vars->base_img->height, vars->title);
	ft_hook_listeners(vars);
}


void	ft_delete_game(t_vars* vars)
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

void	ft_new_game(t_vars* vars)
{
	ft_delete_game(vars);
	ft_init_game(vars);
}