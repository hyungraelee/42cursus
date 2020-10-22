
// #include "ft_printf.h"
// #include "libft.h"
#include <stdio.h>

int	ft_printf(const	char *str, ...);

int	main()
{
	printf("This is real  printf = %10.5f\n", 3.4512349);
	printf("This is real  printf = %10.5d\n", 3);
	ft_printf("This is my ft_printf = %d\n", 27);
	printf("\n");
	printf("This is real  printf = %d\n", 10000);
	ft_printf("This is my ft_printf = %d\n", 10000);
	printf("\n");
	printf("This is real  printf = %d\n", -1);
	ft_printf("This is my ft_printf = %d\n", -1);

	return 0;
}
