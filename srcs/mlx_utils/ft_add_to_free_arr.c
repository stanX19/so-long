#include "so_long.h"

int ft_add_to_free_arr(t_free_arr * free_arr, void * target)
{
	if (free_arr->idx < MAX_FREE_ARR_SIZE)
	{
		free_arr->arr[(free_arr->idx)++] = target;
		return 0;
	}
	else
	{
		ft_printf("ERROR: add to free arr:\
				number of element exceeded MAX_FREE_ARR_SIZE");
		return 1;
	}
}