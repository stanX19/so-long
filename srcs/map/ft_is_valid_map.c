#include "so_long.h"

int	ft_is_valid_map(const char *path)
{
	int prev;
	int cur;
	char c;
	int fd;

	fd = open(path, O_RDONLY);
	prev = 0;
	while (read(fd, &c, 1) && c != '\n')
		prev++;
	while(read(fd, &c, 1))
	{
		if (c == '\n')
		{
			if (cur != prev)
				return 0;
			cur = 0;
		} else
			cur++;
	}
	return (cur == prev);
}