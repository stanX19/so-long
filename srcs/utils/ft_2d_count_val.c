#include "so_long.h"

int	ft_2d_count_val(char ** map, int width, int height, char target)
{
	int count;

	count = 0;
	for (int j = 0; j < height; ++j)
	{
		for (int i = 0; i < height; ++i)
		{
			if (map[j][i] == target)
				++count;
		}
	}
	return count;
}