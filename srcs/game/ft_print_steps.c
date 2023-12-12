#include "so_long.h"

void ft_show_steps(t_vars *vars)
{
	char *step_count;

	step_count = ft_itoa(vars->map->player->stats.steps);
	mlx_string_put(vars->window->mlx, vars->window->mlx_win, 10, 20, 0xFFFFFFFF, step_count);
	free(step_count);
}

void ft_print_steps(t_vars *vars, char *fmt_str)
{
	char *step_count;

	step_count = ft_itoa(vars->map->player->stats.steps);
	ft_printf(fmt_str, step_count);
	free(step_count);
}