#include "so_long.h"

int	ft_on_mouse_click(int button, int x, int y, t_vars * vars)
{
	//ft_printf("click button %i; (%i, %i)\n", button, x, y);
	if (button == 1)
		vars->input->mouse_left = 1;
	else if (button == 2)
		vars->input->mouse_right = 1;
	(void)x;
	(void)y;
	return 0;
}

int	ft_on_mouse_release(int button, int x, int y, t_vars * vars)
{
	//ft_printf("release button %i; (%i, %i)\n", button, x, y);
	if (button == 1)
		vars->input->mouse_left = 0;
	else if (button == 2)
		vars->input->mouse_right = 0;
	(void)x;
	(void)y;
	return 0;
}