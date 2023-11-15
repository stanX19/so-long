#include "so_long.h"

void init_sp_data(t_sp_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS])
{
	for (int i = 0; i < NUM_DIRECTIONS; i++)
	{
		for (int j = 0; j < NUM_ACTIONS; j++)
		{
			sp_data[i][j] = (t_sp_data){0, {0, 0}};
		}
	}
}