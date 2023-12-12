#include "so_long.h"

int	ft_on_destory(t_vars * vars)
{
	vars->input->destory = 1;
	return 0;
}