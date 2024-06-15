
#include "so_long.h"

void	ft_next_game(t_vars *vars)
{
	ft_print_steps(vars, "YOU WON!  |  Steps: %s\n");
	if (vars->idx + 1 >= vars->paths_len)
		ft_end_program(vars);
	vars->idx++;
	ft_new_game(vars);
}
