
#include "ft_printf.h"
#include "libft.h"
#include "limits.h"
#include <stdio.h>

int		ft_printf(const	char *str, ...);

int	main()
{
	// ft_printf("%f\n", __DBL_MAX__);
	// printf("%d\n", ft_printf("%d %+2.4", 3));

// ft_printf("%.5d", 2);
// ft_printf("%.6d", -3);
// ft_printf("%.3d", 0);
// ft_printf("%.4d", 5263);
// ft_printf("%.4d", -2372);
// ft_printf("%.3d", 13862);
// ft_printf("%.3d",-23646);
// ft_printf("%05d", 43);
// ft_printf("%07d", -54);
// ft_printf("%03d", 0);
// ft_printf("%03d", 634);
// ft_printf("%04d", -532);
// ft_printf("%04d", -4825);
// ft_printf("%8.5d", 34);
// ft_printf("%10.5d", -216);
// ft_printf("%8.5d", 0);
// ft_printf("%8.3d", 8375);
// ft_printf("%8.3d", -8473);
// ft_printf("%3.7d", 3267);
// ft_printf("%3.7d", -2375);
// ft_printf("%3.3d", 6983);
// ft_printf("%3.3d", -8462);
// ft_printf("%-8.5d", 34);
// ft_printf("%-10.5d", -216);
// ft_printf("%-8.5d", 0);
// ft_printf("%-8.3d", 8375);
// ft_printf("%-8.3d", -8473);
// ft_printf("%-3.7d", 3267);
// ft_printf("%-3.7d", -2375);
// ft_printf("%-3.3d", 6983);
// ft_printf("%-3.3d", -8462);
// ft_printf("%08.5d", 34);
// ft_printf("%010.5d", -216);
// ft_printf("%08.5d", 0);
// ft_printf("%08.3d", 8375);
// ft_printf("%08.3d", -8473);
// ft_printf("%03.7d", 3267);
// ft_printf("%03.7d", -2375);
// ft_printf("%03.3d", 6983);
// ft_printf("%03.3d", -8462);
// ft_printf("%0-8.5d", 34);
// ft_printf("%0-10.5d", -216);
// ft_printf("%0-8.5d", 0);
// ft_printf("%0-8.3d", 8375);
// ft_printf("%0-8.3d", -8473);
// ft_printf("%0-3.7d", 3267);
// ft_printf("%0-3.7d", -2375);
// ft_printf("%0-3.3d", 6983);
// ft_printf("%0-3.3d", -8462);
// ft_printf("%lx", (__LONG_MAX__ * -1) - 2);
ft_printf("%llu", -1);
printf("\n");
// printf("%lx", (__LONG_MAX__ * -1) - 2);
printf("%llu", -1);
	return 0;
}
