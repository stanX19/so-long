#include "stdio.h"
#include "so_long.h"

// typedef struct s_vars2 {
//     t_mlx_data*		data;
// 	t_image*		base_img;
// 	t_image*		background;
// 	t_itbl*			itbl;
// 	t_input*		s2;
// } t_vars2;

// int update(t_vars2* vars)
// {
// 	static int x;
// 	static int y;

// 	ft_fill_image(vars->base_img, 0);
// 	ft_update_itbl_status(vars->itbl);
// 	ft_put_interactable_to_img(vars->base_img, vars->itbl, x, y);
// 	ft_mlx_put_image_to_win(vars->data, vars->base_img, 0, 0);
// }

int main(void)
{
    t_mlx_data *	data;
	t_image *		base_img;
	t_map *			map;
	t_assets *		assets;

    // Initialize the MiniLibX context
    data = ft_mlx_init(1100, 180, "Hello");
	assets = ft_init_assets(data);
	base_img = ft_new_image(assets, 2500, 1500);
	map = ft_map_init("./assets/map/map1.ber", assets);
	ft_mlx_put_img_to_img(base_img, map->bkg_img, 0, 0);

	ft_printf("running...\n");
	//ft_mlx_put_sprite(base_img, assets->player[LEFT][WALK]->sprites_arr[0], -10, -10);
	ft_mlx_put_image_to_win(data, base_img, 0, 0);
	for (int i = 0; i < map->grid_size.y; i++)
	{
		for (int j = 0; j < map->grid_size.x; j++)
		{
			printf("%3i  ", map->grid[i][j]);
		}
		printf("\n");
	}
	mlx_loop(data->mlx); // Enter the event loop

	ft_destory_assets(assets);
	ft_mlx_destory(data);
	ft_map_destory(map);

	(void)base_img;
	(void)map;
    return (0);
}
