SRCDIR	= srcs/
FUNC	= functions/
UTILS	= utils/
SHARED	= shared/
SRCS	=	$(addsuffix .c, \
		$(addprefix $(SRCDIR)ft_, \
			) \
		$(addprefix $(SRCDIR)$(FUNC)ft_, \
			)\
		$(addprefix $(SRCDIR)$(SHARED)ft_, \
			)\
		$(addprefix $(SRCDIR)$(UTILS)ft_, \
			))

OBJS	=	$(subst .c,.o,$(SRCS))

CC			= 	gcc
CFLAGS		=	-Wall -Wextra -Werror#-fsanitize=address
RM			=	rm -rf
TESTDIR = so_long_tester
TESTGIT = https://github.com/augustobecker/so_long_tester.git
NAME	= so_long

run: all
	$(CC) -I./srcs $(CFLAGS) main.c $(NAME) && ./a.out
bonus: all
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
%.o:%.c
	$(CC) -I. $(CFLAGS) $< -c -o $@
	@echo "\033[1A\033[2K\033[1A"
clean:
	@$(RM) $(OBJS)
	
fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TESTDIR)
	$(RM) ./a.out
re:	fclean $(NAME)

test: $(TESTDIR)
	cd $(TESTDIR) && make && make fclean
$(TESTDIR):
	git clone $(TESTGIT)
.PHONY:			all clean fclean re .c.o
