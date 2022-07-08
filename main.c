#include "stdio.h"
#include "so_long.h"

int	main(int argc, char**argv)
{
	t_data	data;

	if (argc > 1)
		printf("%i", is_valid_map(argv[1]));
	//data.mlx = mlx_init();
	//data.img = mlx_new_image(data.mlx, 1920, 1080);
	//data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, argv[0]);
	//data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
	//								&data.line_length, &data.endian);
	//ft_mlx_pixel_put(&data, 5, 5, 0x007FFF00);
	//mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	//mlx_loop(data.mlx);
	//printf("worked!");
}