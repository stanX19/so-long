#include "so_long.h"

static int count_lines(int fd)
{
	int ret;
	char c;

	ret = 1;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			ret++;
	}
	return ret;
}

char **generate_raw_map(const char* path, size_t *width, size_t *height)
{
	char	buffer[32000];
	char	**ret;
	int		idx;
	int		lc;
	int		fd;

	fd = open(path, O_RDONLY);
	ret = malloc(sizeof(char*) * count_lines(fd));
	idx = 0;
	lc = 0;
	while (read(fd, buffer + idx, 1))
	{
		if (buffer[idx++] == '\n')
		{
			buffer[idx] = 0;
			ret[lc++] = ft_strdup(buffer);
			idx = 0;
		}
	}
	buffer[++idx] = 0;
	ret[lc] = ft_strdup(buffer);
	return ret;
}