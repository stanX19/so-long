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
		ft_destory_assets(vars->assets);
		ft_mlx_destory(vars->data);
		ft_map_destory(vars->map);
		exit(0);
	}
	return 1;
}

void update2(t_itbl * itbl, t_direction direction)
{
	if (itbl->status != ATTACKING)
		itbl->status |= MOVING;
	itbl->direction = direction;
}
int update(t_vars2* vars)
{
	char *step_count;
	t_itbl *player = vars->map->player1;
	int *kb = vars->s2->keyboard;
	//ft_fill_image(vars->base_img, 0);
	ft_mlx_put_img_to_img(vars->base_img, vars->map->bkg_img, 0, 0);
	ft_map_update_itbl(vars->map);
	ft_map_update_itbl_pos(vars->map);
	ft_map_put_itbl(vars->base_img, vars->map);
	//ft_put_interactable_to_img(vars->base_img, vars->map->player1, x, y);
	step_count = ft_itoa(player->stats.steps);
	ft_mlx_put_image_to_win(vars->data, vars->base_img, 0, 0);
	mlx_string_put(vars->data->mlx, vars->data->mlx_win, 10, 10, 0xFFFFFFFF, step_count);
	free(step_count);

	
	//ft_printf("direction: %i | status: %i\n", vars->map->player1->direction, vars->map->player1->status);
	//ft_printf("%i %i %i %i %i\n", x['w'], x['a'], x['s'], x['d'], x[27]);
	//ft_printf("left: %i | right: %i\n", vars->s2->mouse_left, vars->s2->mouse_right);
	ft_printf("(%i, %i) (%i, %i)\n", player->cord.x, player->cord.y, player->rel_cord.x, player->rel_cord.y);
	if (vars->s2->mouse_right)
		vars->map->player1->stats.speed = 10 * vars->map->player1->stats.base_speed;
	if (!vars->s2->mouse_right)
		vars->map->player1->stats.speed = vars->map->player1->stats.base_speed;
	if (vars->s2->mouse_left)
	{
		if (!(vars->map->player1->status & ATTACKING))
		{
			vars->map->player1->frame_tick = 0;
			vars->map->player1->sprite_idx = 0;
		}
		vars->map->player1->status |= ATTACKING;
	}
	//ft_printf("speed = %i\n", vars->map->player1->stats.speed);
	if (kb['w'])
		update2(vars->map->player1, UP);
	else if (kb['a'])
		update2(vars->map->player1, LEFT);
	else if (kb['s'])
		update2(vars->map->player1, DOWN);
	else if (kb['d'])
		update2(vars->map->player1, RIGHT);
	else
		vars->map->player1->status &= ~MOVING;
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
    data = ft_mlx_init();
	assets = ft_init_assets(data);
	base_img = ft_new_image(assets, 2500, 1500);
	map = ft_map_init("./assets/map/map2.ber", assets);
	ft_mlx_win_init(data, map->bkg_img->width, map->bkg_img->height, "so long");

	map->player1->status = ATTACKING;
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
