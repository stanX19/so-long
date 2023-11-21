#include "so_long.h"

void init_sp_data(t_sp_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS])
{
	int i;
	int j;

	i = 0;
	while (i < NUM_DIRECTIONS)
	{
		j = 0;
		while (j < NUM_ACTIONS)
		{
			sp_data[i][j++] = (t_sp_data){0, {0, 0}, {0, 0}, {0, 0}};
		}
		i++;
	}
}