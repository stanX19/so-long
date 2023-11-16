SRCDIR	= srcs
# SPRITE	= sprite
# IMAGE	= image
# MAP		= map
# UTILS	= utils
# INTER	= interactable
# MLXUTILS	= mlx_utils
SRCS		= $(wildcard ./$(SRCDIR)/*/*.c)
# SRCS	=	$(addsuffix .c, \
# 		$(addprefix $(SRCDIR)/ft_, \
# 			) \
# 		$(addprefix $(SRCDIR)/$(IMAGE)/ft_, \
# 			add_img_to_arr\
# 			fill_image image_destory\
# 			mlx_put_image_to_win\
# 			new_image read_xpm)\
# 		$(addprefix $(SRCDIR)/$(INTER)/ft_, \
# 			get_bee_ani_sprites\
# 			init_interactable\
# 			put_interactable_to_img\
# 			init_sp_data)\
# 		$(addprefix $(SRCDIR)/$(MAP)/ft_, \
# 			generate_raw_map\
# 			map_init_cords\
# 			initialize_map_sprites\
# 			map_init\
# 			is_valid_map)\
# 		$(addprefix $(SRCDIR)/$(MLXUTILS)/ft_, \
# 			mlx_init\
# 			mlx_pixel_put\
# 			mlx_destory)\
# 		$(addprefix $(SRCDIR)/$(UTILS)/ft_, \
# 			memcpy\
# 			strdup\
# 			malloc_2d)\
# 		$(addprefix $(SRCDIR)/$(SPRITE)/ft_, \
# 			generate_sprites_array\
# 			init_animated_sprite\
# 			init_sprite mlx_put_sprite\
# 			sprite_destory)\
# 			)

HEADER_DIR	= headers
HEADER		= $(HEADER_DIR)/so_long.h
OBJDIR		= objs
OBJDIRS		= $(sort $(dir $(OBJS)))
OBJS		= $(subst $(SRCDIR),$(OBJDIR),$(subst .c,.o,$(SRCS)))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address
RM			= rm -rf
TESTDIR		= so_long_tester
TESTGIT		= https://github.com/augustobecker/so_long_tester.git

PRINTF_DIR	= ft_printf
PRINTF_LIB	= $(PRINTF_DIR)/libftprintf.a

MLX_LINUX	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_MACOS	= -Lmlx_macos -lmlx -framework OpenGL -framework AppKit
MLX			= $(MLX_LINUX)
NAME		= so_long

IFLAGS		= -I. -I$(HEADER_DIR) $(MLX) $(PRINTF_LIB)

UP			= \033[1A
FLUSH		= \033[2K

run: all
	./so_long
all: $(NAME)

$(NAME): main.c $(OBJS) $(PRINTF_LIB) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) main.c $(IFLAGS) -o $(NAME)
	@echo "$(CC) $(CFLAGS) objs/*.o main.c $(IFLAGS) -o $(NAME)"

$(OBJDIRS):
	mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER) | $(OBJDIRS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"

$(PRINTF_LIB):
	@make --directory=$(PRINTF_DIR) all
clean:
	@$(RM) $(OBJS)
fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(TESTDIR)
	@$(RM) ./a.out
	@make --directory=$(PRINTF_DIR) fclean
re:	fclean $(NAME)

test: $(TESTDIR)
	cd $(TESTDIR) && make && make fclean
$(TESTDIR):
	git clone $(TESTGIT)
.PHONY:			all clean fclean re .c.o
