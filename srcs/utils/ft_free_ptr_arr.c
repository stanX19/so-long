#include "so_long.h"

void	ft_free_ptr_arr(void **arr, size_t len, void(*free_func)(void*))
{
	size_t i;

	i = 0;
	while (i < len)
	{
		free_func(arr[i++]);
	}
	free(arr);
}