#include <stdio.h>
#include "../include/ft_printf.h"

int		ft_printf(const char *str, ...);

int		main(void)
{
	printf("return:%d\n", printf("01. hello %d world %10d\n\n", 12345, -9876));
	printf("return:%d\n", ft_printf("01. hello %d world %10d\n\n", 12345, -9876));

	printf("02. hello %d world\n", -12345);
	ft_printf("02. hello %d world\n\n", -12345);

	printf("03. hello %10d world\n", 12345);
	ft_printf("03. hello %10d world\n\n", 12345);

	printf("04. hello %10d world\n", -12345);
	ft_printf("04. hello %10d world\n\n", -12345);

	printf("05. hello %010d world\n", 12345);
	ft_printf("05. hello %010d world\n\n", 12345);

	printf("06. hello %-10d world\n", 12345);
	ft_printf("06. hello %-10d world\n\n", 12345);

	printf("07. hello %-10d world\n", -12345);
	ft_printf("07. hello %-10d world\n\n", -12345);

	printf("08. hello %010d world\n", -12345);
	ft_printf("08. hello %010d world\n\n", -12345);

	printf("09. hello %4d world\n", 12345);
	ft_printf("09. hello %4d world\n\n", 12345);

	printf("10. hello %4d world\n", -12345);
	ft_printf("10. hello %4d world\n\n", -12345);

	printf("11. hello %10.5d world\n", 123);
	ft_printf("11. hello %10.5d world\n\n", 123);

	printf("12. hello %10.5d world\n", -123);
	ft_printf("12. hello %10.5d world\n\n", -123);

	printf("13. hello %10.1d world\n", 123);
	ft_printf("13. hello %10.1d world\n\n", 123);

	printf("14. hello %10.1d world\n", -123);
	ft_printf("14. hello %10.1d world\n\n", -123);

	printf("15. hello %2.5d world\n", 123);
	ft_printf("15. hello %2.5d world\n\n", 123);

	printf("16. hello %2.5d world\n", -123);
	ft_printf("16. hello %2.5d world\n\n", -123);

	printf("17. hello %2.2d world\n", 123);
	ft_printf("17. hello %2.2d world\n\n", 123);

	printf("18. hello %2.2d world\n", -123);
	ft_printf("18. hello %2.2d world\n\n", -123);

	printf("19. hello %.2d world\n", 123);
	ft_printf("19. hello %.2d world\n\n", 123);

	printf("20. hello %.2d world\n", -123);
	ft_printf("20. hello %.2d world\n\n", -123);

	printf("21. hello %.6d world\n", 123);
	ft_printf("21. hello %.6d world\n\n", 123);

	printf("22. hello %.6d world\n", -123);
	ft_printf("22. hello %.6d world\n\n", -123);

	printf("23. hello %010.5d world\n", 123);
	ft_printf("23. hello %010.5d world\n\n", 123);

	printf("24. hello %010.*d world\n", 5, 123);
	ft_printf("24. hello %010.*d world\n\n", 5, 123);

	printf("25. hello %10.*d world\n", 2, 123);
	ft_printf("25. hello %10.*d world\n\n", 2, 123);

	printf("26. hello %.*d world\n", 5, 123);
	ft_printf("26. hello %.*d world\n\n", 5, 123);

	printf("27. hello %.d world\n", 0);
	ft_printf("27. hello %.d world\n\n", 0);

	printf("28. hello %.0d world\n", 0);
	ft_printf("28. hello %.0d world\n\n", 0);

	printf("29. hello %10.d world\n", 0);
	ft_printf("29. hello %10.d world\n\n", 0);

	printf("30. hello %*d world\n", 10, 123);
	ft_printf("30. hello %*d world\n\n", 10, 123);

	printf("31. hello %0*d world\n", 10, 123);
	ft_printf("31. hello %0*d world\n\n", 10, 123);

	printf("32. hello %+7d world\n", 123);
	ft_printf("32. hello %+7d world\n\n", 123);

	printf("33. hello %+7d world\n", -123);
	ft_printf("33. hello %+7d world\n\n", -123);

	printf("34. hello %+-7d world\n", 123);
	ft_printf("34. hello %+-7d world\n\n", 123);

	printf("35. hello %+-7d world\n", -123);
	ft_printf("35. hello %+-7d world\n\n", -123);

	printf("36. hello %+2d world\n", 123);
	ft_printf("36. hello %+2d world\n\n", 123);

	printf("37. hello %+2d world\n", -123);
	ft_printf("37. hello %+2d world\n\n", -123);

	printf("38. hello %+.7d world\n", 123);
	ft_printf("38. hello %+.7d world\n\n", 123);

	printf("39. hello %+.7d world\n", -123);
	ft_printf("39. hello %+.7d world\n\n", -123);

	printf("40. hello %+.2d world\n", 123);
	ft_printf("40. hello %+.2d world\n\n", 123);

	printf("41. hello %+.2d world\n", -123);
	ft_printf("41. hello %+.2d world\n\n", -123);

	printf("42. hello %+10.2d world\n", 123);
	ft_printf("42. hello %+10.2d world\n\n", 123);

	printf("43. hello %+10.2d world\n", -123);
	ft_printf("43. hello %+10.2d world\n\n", -123);

	printf("44. hello %+10.7d world\n", 123);
	ft_printf("44. hello %+10.7d world\n\n", 123);

	printf("45. hello %+10.7d world\n", -123);
	ft_printf("45. hello %+10.7d world\n\n", -123);

	printf("46. hello %+010.7d world\n", 123);
	ft_printf("46. hello %+010.7d world\n\n", 123);

	printf("47. hello %+010.7d world\n", -123);
	ft_printf("47. hello %+010.7d world\n\n", -123);

	printf("48. hello %+010d world\n", 123);
	ft_printf("48. hello %+010d world\n\n", 123);

	printf("49. hello %+-10.7d world\n", 123);
	ft_printf("49. hello %+-10.7d world\n\n", 123);

	printf("50. hello % d world\n", 123);
	ft_printf("50. hello % d world\n\n", 123);

	printf("51. hello % 7d world\n", 123);
	ft_printf("51. hello % 7d world\n\n", 123);

	printf("52. hello % 7d world\n", -123);
	ft_printf("52. hello % 7d world\n\n", -123);

	printf("53. hello % -7d world\n", 123);
	ft_printf("53. hello % -7d world\n\n", 123);

	printf("54. hello % -7d world\n", -123);
	ft_printf("54. hello % -7d world\n\n", -123);

//	printf("55. hello % +7d world\n", 123);
//	ft_printf("55. hello % +7d world\n\n", 123);

//	printf("56. hello % +7d world\n", -123);
//	ft_printf("56. hello % +7d world\n\n", -123);

	printf("55. hello % .7d world\n", 123);
	ft_printf("55. hello % .7d world\n\n", 123);

	printf("56. hello % .7d world\n", -123);
	ft_printf("56. hello % .7d world\n\n", -123);

//	printf("57. hello % +05d world\n", 123);
	ft_printf("57. hello % +05d world\n\n", 123);

//	printf("58. hello % +-10.5d world\n", -123);
	ft_printf("58. hello % +-10.5d world\n\n", -123);

	printf("59. hello %+-10.5d world\n", -216);
	ft_printf("59. hello %+-10.5d world\n\n", -216);

	printf("60. hello %+-8.3d world\n", -8473);
	ft_printf("60. hello %+-8.3d world\n\n", -8473);

	printf("61. hello %0.d world\n", 73);
	ft_printf("61. hello %0.d world\n\n", 73);

	printf("62. hello %.0d world\n", 73);
	ft_printf("62. hello %.0d world\n\n", 73);

	printf("63. hello %.2d world\n", 0);
	ft_printf("63. hello %.2d world\n\n", 0);

	printf("64. hello %*d world\n", -4, -12);
	ft_printf("64. hello %*d world\n\n", -4, -12);

	printf("65. hello %.*d world\n", 3, -12);
	ft_printf("65. hello %.*d world\n\n", 3, -12);

	printf("66. hello %0*.*d world\n", 2, -2, 8);
	ft_printf("66. hello %0*.*d world\n\n", 2, -2, 8);

	printf("67. hello %0*.*d world\n", 2, -2, 0);
	ft_printf("67. hello %0*.*d world\n\n", 2, -2, 0);

	return (0);
}
