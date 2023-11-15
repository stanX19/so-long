#include "so_long.h"

void **	ft_malloc_2d(size_t height, size_t width, size_t pointer_size, size_t element_size)
{
	void** ret;

	ret = (void**)malloc(height * pointer_size);

	if (ret == NULL)
	{
		return NULL;
	}
	for (size_t i = 0; i < height; i++)
	{
		ret[i] = (void *)malloc(width * element_size);
	}

    return ret;
}