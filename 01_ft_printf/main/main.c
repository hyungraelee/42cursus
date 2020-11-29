
#include "ft_printf.h"
#include "libft.h"
#include "limits.h"
#include <stdio.h>

int		ft_printf(const	char *str, ...);

int	main()
{
	// ft_printf("%f\n", __DBL_MAX__);
	// printf("%d\n", ft_printf("%d %+2.4", 3));

	ft_printf("%d", (int)(-2147483678));
	// ft_printf("%.0e\n", -2.5);
	// ft_printf("%.0e\n", 2.5);
	// ft_printf("%.0e\n", 4.5);

	// printf("\n%f", __DBL_MAX__);
	return 0;
}


// Test 4034 (bonus_e_rnd_half_to_even_02) : FAILED.
//     First line of code: {return test("%.0e", -4.5);}
//       expected output : "-4e+00"
//       your output     : "-5e+00"
//       expected (nonprintable as hex) : "-4e+00"
//       actual   (nonprintable as hex) : "-5e+00"

// Test 4036 (bonus_e_rnd_half_to_even_04) : FAILED.
//     First line of code: {return test("%.0e", -2.5);}
//       expected output : "-2e+00"
//       your output     : "-3e+00"
//       expected (nonprintable as hex) : "-2e+00"
//       actual   (nonprintable as hex) : "-3e+00"

// Test 4041 (bonus_e_rnd_half_to_even_09) : FAILED.
//     First line of code: {return test("%.0e", 2.5);}
//       expected output : "2e+00"
//       your output     : "3e+00"
//       expected (nonprintable as hex) : "2e+00"
//       actual   (nonprintable as hex) : "3e+00"

// Test 4043 (bonus_e_rnd_half_to_even_11) : FAILED.
//     First line of code: {return test("%.0e", 4.5);}
//       expected output : "4e+00"
//       your output     : "5e+00"
//       expected (nonprintable as hex) : "4e+00"
//       actual   (nonprintable as hex) : "5e+00"
