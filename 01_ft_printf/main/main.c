
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int		ft_printf(const	char *str, ...);

void	ft_multiple_five(t_set *set)
{
	int i = 0;
	int	round;

	while (i < 1074)
	{
		(set->bigint.five)[i + 1] = (set->bigint.five[i] * 5) % 10;
		round = (set->bigint.five[i] * 5) / 10;
	}


}

void	ft_init_bigint_arr(t_set *set, t_double dnumb)
{
	write(1, "working?\n", 9);
	ft_memset(set->bigint.num, 0, 1074);

	ft_memset(set->bigint.five, 0, 1074);
	(set->bigint.five)[0] = 5;
	ft_memset(set->bigint.result, 0, 1074);
	set->bigint.len = 0;
	return ;
}

int	main()
{
	t_set set;
	t_double dnumb;
	int	exp;
	int i;
	unsigned long	one;
	unsigned long	temp;

	dnumb.dnum = 0.625;
	ft_init_bigint_arr(&set, dnumb);
	i = 0;
	one = 1;
	one <<= 52;
	exp = dnumb.bitfield.exponent - (int)BIAS;
	temp = dnumb.bitfield.mantissa;
	if (exp >= 0)
	{
		while (i < 52)
		{
			(set.bigint.num)[i] = ((temp >> (51 - i)) & 1) ? 1 : 0;
			++i;
		}
	}
	else
	{
		temp |= one;
		exp *= (-1);
		while (i < 53)
			(set.bigint.num)[exp++ - 1] = ((temp >> (52 - i++)) & 1) ? 1 : 0;
	}

	i = 0;
	while (i < 1074)
	{
		printf("%d", (set.bigint.num)[i++]);
	}

	return 0;
}
