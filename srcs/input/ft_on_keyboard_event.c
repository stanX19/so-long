#include "so_long.h"

static int match_key_to_input(int keycode)
{
	switch (keycode)
	{
	case 65307:
		return 27;
	default:
		if (keycode < 128)
			return keycode;
		else
			return 0;
	}
}

int	ft_on_key_press(int keycode, t_vars * vars)
{
	//ft_printf("press %i\n", keycode);
	vars->input->keyboard[match_key_to_input(keycode)] = 1;
	return 0;
}

int	ft_on_key_release(int keycode, t_vars * vars)
{
	if (keycode == 65307)
		mlx_loop_end(vars->data->mlx);
	//ft_printf("release %i\n", keycode);
	vars->input->keyboard[match_key_to_input(keycode)] = 0;
	return 0;
}