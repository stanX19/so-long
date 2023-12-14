#include "so_long.h"

t_vars *	ft_init_vars(int argc, char **argv)
{
	t_vars *vars;

	vars = ft_calloc(sizeof(t_vars));
	if (!vars)
	{
		ft_printf("ERROR: Init vars: Failed to malloc\n");
	}
	vars->mlx = ft_mlx_init();
	if (!vars->mlx)
	{
		free(vars);
		return 0;
	}
	vars->assets = ft_init_assets(vars->mlx);
	vars->input = ft_init_input();
	vars->paths = argv + 1;
	vars->paths_len = argc - 1;
	vars->title = argv[0];
	return vars;
}

void	ft_delete_vars(t_vars* vars)
{
	ft_input_destory(vars->input);
	ft_destory_assets(vars->assets);
	ft_mlx_destory(vars->mlx);
}
