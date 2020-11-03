
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	ft_printf(const	char *str, ...);

int	main()
{
	int	num = 3;
	printf("main %p\n", &num);
	ft_printf("%p\n", &num);

	return 0;
}
