#include "so_long.h"

static t_vec2	get_offset(t_map *map, t_image *bkg, t_itbl *subject)
{
	t_vec2 ret;

	ret = ft_get_displayed_cord(map->assets->tile_size, subject);
	ret.x = bkg->width / 2 - ret.x;
	ret.y = bkg->height / 2 - ret.y;
	ret.x = min(0, ret.x);
	ret.y = min(0, ret.y);
	ret.x = max(bkg->width - map->bkg_img->width, ret.x);
	ret.y = max(bkg->height - map->bkg_img->height, ret.y);
	return ret;
}

void	ft_game_refresh(t_vars *vars)
{
	t_vec2 offset;

	offset = get_offset(vars->map, vars->base_img, vars->map->player);
	ft_mlx_put_img_to_img(vars->base_img, vars->map->bkg_img, offset.x, offset.y);
	ft_map_put_itbl(vars->base_img, vars->map, offset);
	ft_mlx_put_image_to_win(vars->window, vars->base_img, 0, 0);
}