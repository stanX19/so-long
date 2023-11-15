#include "stdio.h"
#include "so_long.h"

typedef struct s_vars2 {
    t_mlx_data*		data;
	t_image*		base_img;
	t_image*		background;
	t_itbl*			itbl;
	t_input*		s2;
} t_vars2;

void update2(t_itbl * itbl, t_direction direction)
{
	if (itbl->direction != direction)
	{
		itbl->frame_tick = 0;
		itbl->sprite_idx = 0;
	}
	itbl->direction = direction;
}
int update(t_vars2* vars)
{
	ft_fill_image(vars->base_img, 0);
	ft_update_itbl_status(vars->itbl);
	ft_put_interactable_to_img(vars->base_img, vars->itbl, 0, 0);
	ft_mlx_put_image_to_win(vars->data, vars->base_img, 0, 0);
	int *x = vars->s2->keyboard;

	//ft_printf("%i %i %i %i %i\n", x['w'], x['a'], x['s'], x['d'], x[27]);
	if (x['w'])
		update2(vars->itbl, UP);
	else if (x['a'])
		update2(vars->itbl, LEFT);
	else if (x['s'])
		update2(vars->itbl, DOWN);
	else if (x['d'])
		update2(vars->itbl, RIGHT);
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
	background = ft_read_xpm(data, "assets/sprites/overworld_tileset_grass.xpm");
	itbl = ft_init_interactable(ft_get_bee_ani_sprites(data));
	itbl->status = IDLE;

    mlx_loop_hook(data->mlx, update, &(t_vars2){data, base_img, background, itbl, &input});
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_do_key_autorepeatoff(data->mlx);
	mlx_hook(data->mlx_win, ON_KEYDOWN, KEY_PRESS_MASK, ft_on_key_press, &(t_vars){data, 0, &input});
	mlx_hook(data->mlx_win, ON_KEYUP, KEY_RELEASE_MASK, ft_on_key_release, &(t_vars){data, 0, &input});
	ft_printf("running...\n");
	mlx_loop(data->mlx); // Enter the event loop
	ft_printf("loop ended\n");
	ft_mlx_destory(data);
	ft_itbl_destory(itbl);

    return (0);
}
