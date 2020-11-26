
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int		ft_printf(const	char *str, ...);

int	main()
{
	// ft_printf("%f\n", __DBL_MAX__);
	ft_printf("%g", 23.00041);
	// printf("\n%f", __DBL_MAX__);
	return 0;
}
