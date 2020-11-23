
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int		ft_printf(const	char *str, ...);

int	main()
{
	// ft_printf("%f\n", __DBL_MAX__);
	ft_printf("%#.0e\n", 34354.81312451234);
	// printf("\n%f", __DBL_MAX__);
	return 0;
}
