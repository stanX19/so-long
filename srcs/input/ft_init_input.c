#include "so_long.h"

t_input ft_init_input(void)
{
	t_input ret;

	ft_memset(&ret.keyboard, 0, sizeof(ret.keyboard));
	ret.esc_code = 27;
	ret.mouse_left = 0;
	ret.mouse_right = 0;
	return ret;
}