#include "stdio.h"
#include "so_long.h"

typedef struct s_vars2 {
    t_mlx_data*		data;
	t_image*		base_img;
	t_image*		background;
	t_itbl*			itbl;
	t_input*		s2;
} t_vars2;

int ending_loop(t_vars2* vars)
{
	int *kb = vars->s2->keyboard;
	if (kb['w'] + kb['a'] + kb['s'] + kb['d'] + kb[vars->s2->esc_code] == 0)
	{
		ft_printf("loop ended\n");
		ft_mlx_destory(vars->data);
		ft_itbl_destory(vars->itbl);
		exit(0);
	}
	return 1;
}

void update2(t_itbl * itbl, t_direction direction, int*x, int*y)
{
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

	ft_fill_image(vars->base_img, 0);
	ft_update_itbl_status(vars->itbl);
	ft_put_interactable_to_img(vars->base_img, vars->itbl, x, y);
	ft_mlx_put_image_to_win(vars->data, vars->base_img, 0, 0);
	//ft_mlx_put_image_to_win(vars->data, vars->background, 0, 0);
	int *kb = vars->s2->keyboard;

	//ft_printf("%i %i %i %i %i\n", x['w'], x['a'], x['s'], x['d'], x[27]);
	ft_printf("left: %i | right: %i\n", vars->s2->mouse_left, vars->s2->mouse_right);
	if (kb['l'])
		vars->itbl->stats.speed += 1;
	if (kb['k'] && vars->itbl->stats.speed > 1)
		vars->itbl->stats.speed -= 1;
	//ft_printf("speed = %i\n", vars->itbl->stats.speed);
	if (kb['w'])
		update2(vars->itbl, UP, &x, &y);
	else if (kb['a'])
		update2(vars->itbl, LEFT, &x, &y);
	else if (kb['s'])
		update2(vars->itbl, DOWN, &x, &y);
	else if (kb['d'])
		update2(vars->itbl, RIGHT, &x, &y);
	if (kb[27])
		mlx_loop_hook(vars->data->mlx, ending_loop, vars);
	return 0;
}
int main(void)
{
    t_mlx_data *	data;
	t_image *		base_img;
	t_image *		background;
	t_itbl *		itbl;
	t_input			input = ft_init_input();

    // Initialize the MiniLibX context
    data = ft_mlx_init(500, 500, "Hello");
	base_img = ft_new_image(data, 500, 500);
	background = ft_read_xpm(data, "assets/sprites/player/U_Idle.xpm");
	itbl = ft_init_interactable(ft_init_coin_ani_sprites(data));
	itbl->direction = DOWN;
	itbl->status = IDLING;
	itbl->stats.speed = 1;

    mlx_loop_hook(data->mlx, update, &(t_vars2){data, base_img, background, itbl, &input});
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_do_key_autorepeatoff(data->mlx);
	ft_hook_listeners(&(t_vars){data, 0, &input});
	ft_printf("running...\n");
	mlx_loop(data->mlx); // Enter the event loop
	

    return (0);
}
