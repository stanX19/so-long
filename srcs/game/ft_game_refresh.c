#include "so_long.h"

static t_vec2	get_offset(t_map *map, t_image *bkg, t_itbl *subject)
{
	static t_vec2 ofst;
	t_vec2 new_ofst;
	t_vec2 diff;

	new_ofst = ft_get_displayed_cord(map->assets->tile_size, subject);
	new_ofst.x = bkg->width / 2 - new_ofst.x;
	new_ofst.y = bkg->height / 2 - new_ofst.y;
	diff.x = new_ofst.x - ofst.x;
	diff.y = new_ofst.y - ofst.y;
	diff.x = sign(diff.x) * max(abs(diff.x) / 100, abs(diff.x) - bkg->width / 2 + 100);
	diff.y = sign(diff.y) * max(abs(diff.y) / 100, abs(diff.y) - bkg->height / 2 + 100);
	ofst.x += diff.x;
	ofst.y += diff.y;
	ofst.x = min(0, ofst.x);
	ofst.y = min(0, ofst.y);
	ofst.x = max(bkg->width - map->bkg_img->width, ofst.x);
	ofst.y = max(bkg->height - map->bkg_img->height, ofst.y);
	// ft_printf("ofst: (%i, %i), new_ofst: (%i, %i), diff: (%i, %i)\n",
	// 	ofst.x, ofst.y, new_ofst.x, new_ofst.y,
	// 	diff.x, diff.y
	// );
	return ofst;
}

void	ft_game_refresh(t_vars *vars)
{
	t_vec2 offset;

	offset = get_offset(vars->map, vars->base_img, vars->map->player);
	ft_mlx_put_img_to_img(vars->base_img, vars->map->bkg_img, offset.x, offset.y);
	ft_map_put_itbl(vars->base_img, vars->map, offset);
	ft_mlx_put_image_to_win(vars->window, vars->base_img, 0, 0);
}