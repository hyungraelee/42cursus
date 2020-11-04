
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	ft_printf(const	char *str, ...);

int	main()
{
	printf("%% d =% d'\n", 0);
	printf("%% 5d =%+d'\n", 0);
	printf("%% 05d =% 05d'\n", 1);
	printf("%%+d =%+010d'\n", +123);
	printf("%%+-5d =%+-5d'\n", 1);
	printf("%%+-5d =%+-5d'\n", -1);
	printf("%% -5d =% -5d'\n", 1);
	printf("%% -5d =% -5d'\n", -1);

	return 0;
}
