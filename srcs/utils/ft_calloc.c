#include "so_long.h"

void *	ft_calloc(size_t size)
{
	void *	ret;
	
	ret = malloc(size);
	if (!ret)
		return 0;
	ft_memset(ret, 0, size);
	return ret;
}