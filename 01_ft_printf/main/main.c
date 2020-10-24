
// #include "ft_printf.h"
// #include "libft.h"
#include <stdio.h>

int	ft_printf(const	char *str, ...);

int	main()
{
	printf("This is real  printf = %10.5d\n", 123);
	printf("This is real  printf = %010d\n", -12345);
	printf("This is real  printf = %05d\n", -1234567890);
	printf("This is real  printf = %05d\n", -123);
	printf("This is real  printf = %03d\n", -12345);
	printf("This is real  printf = %03d\n", -1234567890);
	printf("This is real  printf = %03d\n", -0);
	printf("This is real  printf = %.3d\n", -0);
	printf("\n");
	ft_printf("This is my ft_printf = %010d\n", -123);
	ft_printf("This is my ft_printf = %010d\n", -12345);
	ft_printf("This is my ft_printf = %05d\n", -1234567890);
	ft_printf("This is my ft_printf = %05d\n", -123);
	ft_printf("This is my ft_printf = %03d\n", -12345);
	ft_printf("This is my ft_printf = %03d\n", -1234567890);
	ft_printf("This is my ft_printf = %03d\n", -0);
	ft_printf("This is my ft_printf = %.3d\n", -0);
	printf("\n");

	return 0;
}
