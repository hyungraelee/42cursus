
#include "ft_printf.h"
#include "libft.h"
#include "limits.h"
#include <stdio.h>

int		ft_printf(const	char *str, ...);

int	main()
{
	// ft_printf("%f\n", __DBL_MAX__);
	// ft_printf("%.0g", -0.5);
	ft_printf("%e'", (double)INT_MAX + 1);
	// printf("\n%f", __DBL_MAX__);
	return 0;
}
