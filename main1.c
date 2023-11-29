#include "stdio.h"
#include "so_long.h"

typedef struct s_vars2 {
    t_mlx_data*		data;
	t_image*		base_img;
	t_map*			map;
	t_assets*		assets;
	t_input*		input;
} t_vars2;

int ending_loop(t_vars2* vars)
{
	int *kb = vars->input->keyboard;
	if (kb['w'] + kb['a'] + kb['s'] + kb['d'] + kb[vars->input->esc_code] == 0)
	{
		ft_printf("loop ended\n");
		ft_destory_assets(vars->assets);
		ft_mlx_destory(vars->data);
		ft_map_destory(vars->map);
		exit(0);
	}
	return 1;
}

void update2(t_itbl * itbl, t_input *input)
{
	
	if (input->mouse_right)
		itbl->stats.speed = 1000 * itbl->stats.base_speed;
	if (!input->mouse_right)
		itbl->stats.speed = itbl->stats.base_speed;
	itbl->velocity.x = itbl->stats.speed * (input->keyboard['d'] - input->keyboard['a']);
	itbl->velocity.y = itbl->stats.speed * (input->keyboard['s'] - input->keyboard['w']);
	if (itbl->velocity.x || itbl->velocity.y)
		itbl->status |= MOVING;
	else
		itbl->status &= ~MOVING;
	if (itbl->velocity.x > 0)
		itbl->direction = RIGHT;
	else if (itbl->velocity.x < 0)
		itbl->direction = LEFT;
	else if (itbl->velocity.y < 0)
		itbl->direction = UP;
	else if (itbl->velocity.y > 0)
		itbl->direction = DOWN;
	if (input->mouse_left)
	{
		if (!(itbl->status & ATTACKING))
		{
			itbl->frame_tick = 0;
			itbl->sprite_idx = 0;
		}
		itbl->status |= ATTACKING;
	}
	
}
int update(t_vars2* vars)
{
	char *step_count;
	t_itbl *player = vars->map->player1;
	int *kb = vars->input->keyboard;
	//ft_fill_image(vars->base_img, 0);
	update2(player, vars->input);
	for (size_t i = 0; i < vars->map->enemy_len; i++)
	{
		vars->map->enemy[i]->velocity.x += rand() % 3 - 1;
		vars->map->enemy[i]->velocity.y += rand() % 3 - 1;
		//update2(vars->map->enemy[i], vars->input);
		vars->map->enemy[i]->status |= MOVING;
		//ft_printf("(%i, %i)\n", vars->map->enemy[i]->stats.velocity.x, vars->map->enemy[i]->stats.velocity.y);
	}
	ft_mlx_put_img_to_img(vars->base_img, vars->map->bkg_img, 0, 0);
	ft_map_update_itbl(vars->map);
	ft_map_update_itbl_pos(vars->map);
	ft_map_put_itbl(vars->base_img, vars->map);
	//ft_put_interactable_to_img(vars->base_img, vars->map->player1, x, y);
	step_count = ft_itoa(player->stats.steps);
	ft_mlx_put_image_to_win(vars->data, vars->base_img, 0, 0);
	mlx_string_put(vars->data->mlx, vars->data->mlx_win, 10, 20, 0xFFFFFFFF, step_count);
	free(step_count);

	
	//ft_printf("direction: %i | status: %i\n", vars->map->player1->direction, vars->map->player1->status);
	//ft_printf("%i %i %i %i %i\n", x['w'], x['a'], x['s'], x['d'], x[27]);
	//ft_printf("left: %i | right: %i\n", vars->input->mouse_left, vars->input->mouse_right);
	//ft_printf("(%i, %i) (%i, %i)\n", player->cord.x, player->cord.y, player->rel_cord.x, player->rel_cord.y);
	//ft_printf("speed = %i\n", vars->map->player1->stats.speed);
	if (kb[27])
		mlx_loop_hook(vars->data->mlx, ending_loop, vars);
	if (vars->map->exit->status & (DYING | DEAD))
	{
		step_count = ft_itoa(player->stats.steps);
		ft_printf("YOU WON!  |  Steps: %s\n", step_count);
		free(step_count);
		mlx_loop_hook(vars->data->mlx, ending_loop, vars);
	}
	if (player->status & (DYING | DEAD))
	{
		step_count = ft_itoa(player->stats.steps);
		ft_printf("YOU DIED\n");
		free(step_count);
		mlx_loop_hook(vars->data->mlx, ending_loop, vars);
	}
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
	map = ft_map_init("./assets/map/map4.ber", assets);
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
