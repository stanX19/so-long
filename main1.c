#include "stdio.h"
#include "so_long.h"

t_vars *	ft_init_vars(void)
{
	t_vars *vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
	{
		ft_printf("ERROR: Init vars: Failed to malloc\n");
	}
	vars->mlx = ft_mlx_init();
	vars->assets = ft_init_assets(vars->mlx);
	vars->input = ft_init_input();
	return vars;
}

void	ft_init_game(t_vars* vars, char *path, char *title)
{
	vars->map = ft_map_init(path, vars->assets);
	vars->base_img = ft_new_image(vars->assets, vars->map->bkg_img->width, vars->map->bkg_img->height);
    vars->window = ft_window_init(vars->mlx, vars->map->bkg_img->width, vars->map->bkg_img->height, title);
}

void	ft_delete_game(t_vars* vars)
{
	ft_map_destory(vars->map);
	// deal with the base_img somehow
	ft_window_destory(vars->window);
}

void	ft_delete_vars(t_vars* vars)
{
	ft_input_destory(vars->input);
	ft_destory_assets(vars->assets);
	ft_mlx_destory(vars->mlx);
}

int ending_loop(t_vars* vars)
{
	int *kb = vars->input->keyboard;
	if (kb['w'] + kb['a'] + kb['s'] + kb['d'] + kb[vars->input->esc_code] == 0)
	{
		ft_printf("loop ended\n");
		ft_delete_game(vars);
		ft_delete_vars(vars);
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

int update(t_vars* vars)
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
	ft_mlx_put_image_to_win(vars->window, vars->base_img, 0, 0);
	mlx_string_put(vars->window->mlx, vars->window->mlx_win, 10, 20, 0xFFFFFFFF, step_count);
	free(step_count);

	
	//ft_printf("direction: %i | status: %i\n", vars->map->player1->direction, vars->map->player1->status);
	//ft_printf("%i %i %i %i %i\n", x['w'], x['a'], x['s'], x['d'], x[27]);
	//ft_printf("left: %i | right: %i\n", vars->input->mouse_left, vars->input->mouse_right);
	//ft_printf("(%i, %i) (%i, %i)\n", player->cord.x, player->cord.y, player->rel_cord.x, player->rel_cord.y);
	//ft_printf("speed = %i\n", vars->map->player1->stats.speed);
	if (kb[27])
		mlx_loop_hook(vars->window->mlx, ending_loop, vars);
	if (vars->map->exit->status & (DYING | DEAD))
	{
		step_count = ft_itoa(player->stats.steps);
		ft_printf("YOU WON!  |  Steps: %s\n", step_count);
		free(step_count);
		mlx_loop_hook(vars->window->mlx, ending_loop, vars);
	}
	if (player->status & DEAD)
	{
		vars->map->grid[player->cord.y][player->cord.x] |= player->self;
		ft_itbl_set_status(player, ATTACKING);
		// ft_delete_game(vars);
		// ft_init_game(vars, );
		// step_count = ft_itoa(player->stats.steps);
		ft_printf("YOU DIED\n");
		// free(step_count);
		// mlx_loop_hook(vars->window->mlx, ending_loop, vars);
	}
	return 0;
}




int main(int argc, char **argv)
{
	t_vars *		vars;
	char *			path;

	if (argc < 2)
		path = "./assets/map/map4.ber";
	else
		path = argv[1];
	vars = ft_init_vars();
	ft_init_game(vars, path, argv[0]);

	ft_printf("running...\n");
	mlx_loop_hook(vars->mlx, update, vars);
	ft_hook_listeners(vars);
	mlx_loop(vars->mlx);

    return (0);
}
