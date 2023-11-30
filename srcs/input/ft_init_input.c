#include "so_long.h"

t_input *ft_init_input(void)
{
	t_input *ret;

	ret = ft_calloc(sizeof(t_input));
	ret->esc_code = 27;
	return ret;
}