#include "so_long.h"

static t_vec2 str_to_vec(char *buf)
{
	t_vec2 ret;

	ret = (t_vec2){0, 0};
	ret.x = ft_atoi(buf);
	while (!(*buf >= '0' && *buf <= '9') && *buf != 0)
		buf++;
	while (*buf >= '0' && *buf <= '9' && *buf != 0)
		buf++;
	while (!(*buf >= '0' && *buf <= '9') && *buf != 0)
		buf++;
	ret.y = ft_atoi(buf);
	return ret;
}

static t_vec2 path_to_vec2(const char *path)
{
	char buf[128];
	int fd;
	size_t size;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file: %s; error: %s\n", path, strerror(errno));
		return (t_vec2){0, 0};
	}
	size = read(fd, buf, sizeof(buf) - 1);
	buf[size] = '\0';
	close(fd);
	return str_to_vec(buf);
}

t_vec2 ft_system_get_screen_size(void)
{
	t_vec2 ret;

	system("xdpyinfo 2> /dev/null | grep dimensions | awk '{print $2}' > ./__resolution.txt");
	ret = path_to_vec2("./__resolution.txt");
	if (ret.x == 0 && ret.y == 0)
	{
		system("system_profiler SPDisplaysDataType 2> /dev/null | grep Resolution | awk '{print $2, $4}' > ./__resolution.txt");
		ret = path_to_vec2("./__resolution.txt");
	}
	if (ret.x == 0 && ret.y == 0)
	{
		ft_printf("Command to get screen size failed\n");
	}
	system("rm -rf ./__resolution.txt");
	return ret;
}