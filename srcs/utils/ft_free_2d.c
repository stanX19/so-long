#include "so_long.h"

void	ft_free_2d(void **ptr, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		if (ptr[idx])
			free(ptr[idx]);
		++idx;
	}
	free(ptr);
}