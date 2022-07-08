#ifndef SO_LONG_HEADER_H
# define SO_LONG_HEADER_H
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_square {
	int x;
	int y;
	int x2;
	int y2;
	unsigned int color;
} square_t;

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);

int		is_valid_map(const char *path);
#endif