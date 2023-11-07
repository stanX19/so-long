#ifndef SO_LONG_HEADER_H
# define SO_LONG_HEADER_H
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_vector2 {
	int get[0];
	int x;
	int y;
} t_vector2;

typedef struct	s_window_data {
	void	*mlx;
	void	*mlx_win;
	size_t	width;
	size_t	height;
}				t_window_data;

typedef struct	s_image {
	void*	img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
	int		width;
	int		height;	
} t_image;

typedef struct	s_sprite {
	int		width;
	int		height;
	char*	addr;
	int		bits_per_pixel;
	int		line_length;
} t_sprite;

typedef struct	s_animated_sprite {
	void	**sprite_arr;
	size_t	length;
	int		frame_interval;
} t_animated_sprite;

typedef enum {
	LEFT,
	RIGHT,
	UP,
	DOWN
} t_direction;

typedef enum {
	DEAD,
	ALIVE,
	ATTACK,
} t_interactable_status;

typedef struct	s_interactable {
	t_vector2 loc;
	t_vector2 relative_loc;
	t_direction direction;
	t_interactable_status status;
	t_animated_sprite sprites[3][4];
} t_interactable;

typedef enum {
    PATH,
    WALL,
    WATER
} t_tile;

typedef struct s_map {
	t_tile**		grid;
	size_t			height;
	size_t			width;
	t_interactable	player1;
	t_interactable	exit;
	t_interactable*	slimes;
} t_map;

void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strdup(char *src);

t_image			ft_read_xpm(t_window_data* data, char* relative_path);
t_image			ft_new_image(t_window_data* data, int width, int height);
void			ft_fill_image(t_image* img, int color);

void			ft_mlx_put_sprite(t_image* image, t_sprite* sprite,int x, int y);
void			ft_mlx_pixel_put(t_image* img, int x, int y, int color);
t_window_data	ft_mlx_init(int window_width, int window_height, char *window_title);

int				ft_is_valid_map(const char *path);
char**			ft_generate_raw_map(const char* path, size_t *width, size_t *height);
t_map*			ft_initialize_map(const char* path);

t_sprite		ft_sprite_init(t_image *img, int x, int y, int x_size, int y_size);

#endif