
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	ft_printf(const	char *str, ...);

int	main()
{
	printf("%% d =% u'\n", 12);
	printf("%% d =% u'\n", -12);
	printf("%%+d =%+u'\n", 12);
	printf("%%+d =%+u'\n", -12);
	printf("\n");
	ft_printf("%% d =% d'\n", 12);
	ft_printf("%% d =% d'\n", -12);
	ft_printf("%%+d =%+d'\n", 12);
	ft_printf("%%+d =%+d'\n", -12);
	return 0;
}
