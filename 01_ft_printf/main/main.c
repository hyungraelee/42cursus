
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
ft_printf("%e", 10.12);
// ft_printf("%5.0d", 0);
// ft_printf("%5.d", 0);
// ft_printf("%-5.0d", 0);
// ft_printf("%-5.d", 0);
	// ft_printf("%.0e\n", -2.5);
	// ft_printf("%.0e\n", 2.5);
	// ft_printf("%.0e\n", 4.5);

	// printf("\n%f", __DBL_MAX__);
	return 0;
}


// Test 4034 (bonus_e_rnd_half_to_even_02) : FAILED.
//     First line of code: {return ft_printf("%.0e", -4.5);
//       expected output : "-4e+00"
//       your output     : "-5e+00"
//       expected (nonprintable as hex) : "-4e+00"
//       actual   (nonprintable as hex) : "-5e+00"

// Test 4036 (bonus_e_rnd_half_to_even_04) : FAILED.
//     First line of code: {return ft_printf("%.0e", -2.5);
//       expected output : "-2e+00"
//       your output     : "-3e+00"
//       expected (nonprintable as hex) : "-2e+00"
//       actual   (nonprintable as hex) : "-3e+00"

// Test 4041 (bonus_e_rnd_half_to_even_09) : FAILED.
//     First line of code: {return ft_printf("%.0e", 2.5);
//       expected output : "2e+00"
//       your output     : "3e+00"
//       expected (nonprintable as hex) : "2e+00"
//       actual   (nonprintable as hex) : "3e+00"

// Test 4043 (bonus_e_rnd_half_to_even_11) : FAILED.
//     First line of code: {return ft_printf("%.0e", 4.5);
//       expected output : "4e+00"
//       your output     : "5e+00"
//       expected (nonprintable as hex) : "4e+00"
//       actual   (nonprintable as hex) : "5e+00"
