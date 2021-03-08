
#include "ft_printf.h"
#include "libft.h"
#include "limits.h"
#include <stdio.h>

int		ft_printf(const	char *str, ...);

int	main()
{
	int d;

	// d = ft_printf("\"this %d number\"", -267);
	d = printf("\"this %d number\"", -267);
	printf("\n");
	printf("%d\n", d);
	return 0;
}
