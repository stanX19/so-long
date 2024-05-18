#include <stdio.h>

typedef struct s
{
	char index[0];
	char x;
	char y;
	char z;
} t;

int	main(void)
{
	t	k;

	k.x = 'a';
	k.z = 'c';
	printf("%c\n", k.index[2]);
	printf("%li\n", sizeof(t));
	return (0);
}

int    main(int argc, char **argv)
{

}

