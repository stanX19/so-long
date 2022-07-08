#include "stdio.h"
#include "so_long.h"

int	main(void)
{
	void* mlx;
	void* mlx_win;

	mlx = mlx_init();
	if (!mlx)
	{
		printf("failed to mlx_init\n");
		return 0;
	}
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	(void)mlx_win;
}

//int looped(char* str)
//{
//	printf("%s", str);
//	return 0;
//}

//int	main(int argc, char**argv)
//{
//	t_data	data;
//
//	if (argc > 1)
//		printf("%i", is_valid_map(argv[1]));
//	data.mlx = mlx_init();
//	data.mlx_win = mlx_new_window(data.mlx, 100, 50, argv[0]);
//	return 0;
//	data.img = mlx_new_image(data.mlx, 1000, 500);
//	
//	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
//									&data.line_length, &data.endian);
//	//ft_mlx_pixel_put(&data, 5, 5, 0x007FFF00);
//	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
//	mlx_loop_hook(data.mlx, looped, "hello\n");
//	mlx_loop(data.mlx);
//	//printf("worked!");
//}