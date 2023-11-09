#include "stdio.h"
#include "so_long.h"

// int	main(void)
// {
// 	void* mlx;
// 	void* mlx_win;

// 	mlx = mlx_init();
// 	if (!mlx)
// 	{
// 		printf("failed to mlx_init\n");
// 		return 0;
// 	}
// 	else
// 		printf("initialized\n");
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);
// 	(void)mlx_win;
// }

// int looped(char* str)
// {
// 	printf("%s", str);
// 	return 0;
// }

// int	main(int argc, char**argv)
// {
// 	t_data	data;

// 	if (argc > 1)
// 		printf("%i", is_valid_map(argv[1]));
// 	data.mlx = mlx_init();
// 	data.mlx_win = mlx_new_window(data.mlx, 100, 50, argv[0]);
// 	data.img = mlx_new_image(data.mlx, 1000, 500);
	
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
// 									&data.line_length, &data.endian);
// 	ft_mlx_pixel_put(&data, 5, 5, 0x007FFF00);
// 	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
// 	mlx_loop_hook(data.mlx, looped, "hello\n");
// 	mlx_loop(data.mlx);
// 	printf("worked!");

typedef struct s_vars {
    t_window_data*	data;
	t_image*		base_img;
	t_ani_sprite*	animated;
} t_vars;
int update(t_vars* vars){
	static int idx = 0;

	if (idx >= vars->animated->length)
		idx = 0;

	//ft_fill_image(vars->base_img, 0x00FF00FF);
	ft_mlx_put_sprite(vars->base_img, vars->animated->sprites_arr[idx], 0, 0);
	ft_mlx_put_image_to_win(vars->data, vars->base_img, 0, 0);

	++idx;
	return 0;
}
int main(void)
{
    t_window_data	data;
	t_image*		base_img;
	t_image*		xpm_img;
	t_ani_sprite*	animated;

    // Initialize the MiniLibX context
    data = ft_mlx_init(500, 500, "Hello");
	base_img = ft_read_xpm(&data, "assets/sprites/overworld_tileset_grass.xpm");
	xpm_img = ft_read_xpm(&data, "assets/sprites/bee/S_Walk.xpm");
	// sprite = ft_init_sprite(xpm_img, 0, 0, (t_vec2){6, 1});
	// ft_mlx_put_sprite(base_img, sprite, 0, 0);
	t_sprite** sprites = ft_generate_sprites_array(xpm_img, (t_vec2){0, 0}, (t_vec2){6, 1}, (t_vec2){6, 1});
	animated = ft_init_animated_sprite(sprites, 6, 1);

	mlx_put_image_to_window(data.mlx, data.mlx_win, base_img->img, 0, 0);
    mlx_loop_hook(data.mlx, &update, &(t_vars){&data, base_img, animated});
	mlx_loop(data.mlx); // Enter the event loop

	(void)xpm_img;
    // Clean up and close the window when you're done
    //mlx_destroy_window(data.mlx, data.mlx_win);
    //mlx_destroy_image(data.mlx, img->img);

    return (0);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*img;
// 	char	*relative_path = "./assets/sprites/bee/D_Death.xpm";
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);

// 	(void)img;
// }