#include "so_long.h"

int	ft_has_input(t_input *input)
{
	size_t idx;

	idx = 0;
	while (idx < sizeof(input->keyboard))
	{
		if (input->keyboard[idx++])
			return 1;
	}
	if (input->mouse_left || input->mouse_right)
		return 1;
	return 0;
}

void	ft_manage_mouse(t_vars *vars, int center)
{
	if (!center)
	{
		mlx_mouse_show(vars->mlx, vars->window->mlx_win);
		return ;
	}
	mlx_mouse_move(vars->mlx, vars->window->mlx_win,
		vars->window->width / 2, vars->window->width / 2);
	mlx_mouse_hide(vars->mlx, vars->window->mlx_win);
}