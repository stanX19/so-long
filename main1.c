#include "stdio.h"
#include "so_long.h"

typedef struct s_vars2 {
    t_mlx_data*		data;
	t_image*		base_img;
	t_map*			map;
	t_assets*		assets;
	t_input*		s2;
} t_vars2;

int ending_loop(t_vars2* vars)
{
	int *kb = vars->s2->keyboard;
	if (kb['w'] + kb['a'] + kb['s'] + kb['d'] + kb[vars->s2->esc_code] == 0)
	{
		ft_printf("loop ended\n");
		ft_mlx_destory(vars->data);
		ft_map_destory(vars->map);
		ft_destory_assets(vars->assets);
		exit(0);
	}
	return 1;
}

void update2(t_itbl * itbl, t_direction direction, int*x, int*y)
{
	if (itbl->status != ATTACKING)
		itbl->status = MOVING;
	// if (itbl->direction != direction)
	// {
	// 	itbl->frame_tick = 0;
	// 	itbl->sprite_idx = 0;
	// }
	itbl->direction = direction;
	switch (direction)
	{
	case LEFT:
		*x -= itbl->stats.speed;
		break;
	case RIGHT:
		*x += itbl->stats.speed;
		break;
	case UP:
		*y -= itbl->stats.speed;
		break;
	case DOWN:
		*y += itbl->stats.speed;
		break;
	default:
		break;
	}
}
int update(t_vars2* vars)
{
	static int x;
	static int y;

	//ft_fill_image(vars->base_img, 0);
	ft_mlx_put_img_to_img(vars->base_img, vars->map->bkg_img, 0, 0);
	ft_update_itbl_status(vars->map->player1);
	ft_put_interactable_to_img(vars->base_img, vars->map->player1, x, y);
	ft_mlx_put_image_to_win(vars->data, vars->base_img, 0, 0);
	//ft_mlx_put_image_to_win(vars->data, vars->background, 0, 0);
	int *kb = vars->s2->keyboard;
	ft_printf("direction: %i | status: %i\n", vars->map->player1->direction, vars->map->player1->status);
	//ft_printf("%i %i %i %i %i\n", x['w'], x['a'], x['s'], x['d'], x[27]);
	//ft_printf("left: %i | right: %i\n", vars->s2->mouse_left, vars->s2->mouse_right);
	if (vars->s2->mouse_right)
		vars->map->player1->stats.speed = 10;
	if (!vars->s2->mouse_right)
		vars->map->player1->stats.speed = 1;
	if (vars->s2->mouse_left)
		vars->map->player1->status = ATTACKING;
	//ft_printf("speed = %i\n", vars->map->player1->stats.speed);
	if (kb['w'])
		update2(vars->map->player1, UP, &x, &y);
	else if (kb['a'])
		update2(vars->map->player1, LEFT, &x, &y);
	else if (kb['s'])
		update2(vars->map->player1, DOWN, &x, &y);
	else if (kb['d'])
		update2(vars->map->player1, RIGHT, &x, &y);
	else
		vars->map->player1->status = IDLING;
	if (kb[27])
		mlx_loop_hook(vars->data->mlx, ending_loop, vars);
	return 0;
}

int main(void)
{
    t_mlx_data *	data;
	t_image *		base_img;
	t_map *			map;
	t_assets *		assets;
	t_input 		input = ft_init_input();

    // Initialize the MiniLibX context
    data = ft_mlx_init(1100, 180, "Hello");
	assets = ft_init_assets(data);
	base_img = ft_new_image(assets, 2500, 1500);
	map = ft_map_init("./assets/map/map1.ber", assets);
	ft_mlx_put_img_to_img(base_img, map->bkg_img, 0, 0);

	ft_printf("running...\n");
	// ft_mlx_put_sprite(base_img, assets->player[LEFT][WALK]->sprites_arr[0], -10, -10);
	// ft_mlx_put_image_to_win(data, base_img, 0, 0);
	mlx_loop_hook(data->mlx, update, &(t_vars2){data, base_img, map, assets, &input});
	ft_hook_listeners(&(t_vars){data, map, &input});
	mlx_loop(data->mlx); // Enter the event loop

	ft_destory_assets(assets);
	ft_mlx_destory(data);
	ft_map_destory(map);

	(void)base_img;
	(void)map;
    return (0);
}
