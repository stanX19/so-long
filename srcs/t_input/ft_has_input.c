
#include "so_long.h"

int	ft_has_input(t_input *input)
{
	return (!ft_mem_is_zero(input, sizeof(t_input)));
}
