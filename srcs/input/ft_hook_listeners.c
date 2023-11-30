#include "so_long.h"

void	ft_hook_listeners(t_vars * vars)
{
	mlx_do_key_autorepeatoff(vars->window->mlx);
	mlx_hook(vars->window->mlx_win, ON_KEYDOWN, KEY_PRESS_MASK, ft_on_key_press, vars);
	mlx_hook(vars->window->mlx_win, ON_KEYUP, KEY_RELEASE_MASK, ft_on_key_release, vars);
	mlx_hook(vars->window->mlx_win, ON_MOUSEDOWN, BUTTON_PRESS_MASK, ft_on_mouse_click, vars);
	mlx_hook(vars->window->mlx_win, ON_MOUSEUP, BUTTON_RELEASE_MASK, ft_on_mouse_release, vars);
	
}