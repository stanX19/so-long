#include "so_long.h"

int ft_wait_loop(t_vars* vars)
{
	ft_game_refresh(vars);
	mlx_string_put(vars->mlx, vars->window->mlx_win, 10, 20, 0xFFFFFFFF, "GAME ENDED, RELEASE ALL KEYS");
	int *kb = vars->input->keyboard;
	if (kb['w'] + kb['a'] + kb['s'] + kb['d'] +	kb['\e'] + kb['\t'] + 
		vars->input->mouse_left + vars->input->mouse_right == 0)
	{
		ft_new_game(vars);
		mlx_loop_hook(vars->mlx, ft_update_loop, vars);
	}
	return 0;
}

int ft_ending_loop(t_vars* vars)
{
	ft_game_refresh(vars);
	mlx_string_put(vars->mlx, vars->window->mlx_win, 10, 20, 0xFFFFFFFF, "GAME ENDED, RELEASE ALL KEYS");
	int *kb = vars->input->keyboard;
	if (kb['w'] + kb['a'] + kb['s'] + kb['d'] +	kb[vars->input->esc_code] + 
		vars->input->mouse_left + vars->input->mouse_right == 0)
	{
		ft_printf("loop ended\n");
		ft_delete_game(vars);
		ft_delete_vars(vars);
		exit(0);
	}
	return 1;
}

void choose_loop(t_vars* vars)
{
	if (vars->input->keyboard['\e'] || vars->input->destory)
	{
		mlx_loop_hook(vars->window->mlx, ft_ending_loop, vars);
	}
	else if (vars->map->exit->status & DEAD)
	{
		ft_print_steps(vars, "YOU WON!  |  Steps: %s\n");
		if (vars->idx + 1 >= vars->paths_len)
		{
			mlx_loop_hook(vars->mlx, ft_ending_loop, vars);
		}
		else
		{
			vars->idx++;
			mlx_loop_hook(vars->mlx, ft_wait_loop, vars);
		}
	}
	else if (vars->map->player->status & DEAD)
	{
		mlx_loop_hook(vars->mlx, ft_wait_loop, vars);
	}
}

int ft_update_loop(t_vars* vars)
{
	ft_update_player(vars);
	ft_map_update_enemy_v(vars->map);
	ft_map_update_itbl(vars->map);
	ft_game_refresh(vars);
	ft_show_steps(vars);
	choose_loop(vars);
	return 0;
}
