
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int		ft_printf(const	char *str, ...);



void	ft_multiple_five(t_set *set, int i)
{
	// int i = 0;
	int j;
	int	round;



	if (i < 1073)
	{
	// while (i < 1073)
	// {
		j = i/*++*/;
		round = 0;
		while (j >= 0)
		{
			if ((((set->bigint.five_arr[j] * 5) % 10) + round) < 10)
			{
				(set->bigint.five_arr)[j + 1] = ((set->bigint.five_arr[j] * 5) % 10) + round;
				round = 0;
			}
			else
			{
				(set->bigint.five_arr)[j + 1] = (((set->bigint.five_arr[j] * 5) % 10) + round) % 10;
				round = (((set->bigint.five_arr[j] * 5) % 10) + round) / 10;
			}
			round += (set->bigint.five_arr[j] * 5) / 10;
			set->bigint.five_arr[j--] = round;
		}

	}
		// j = 0;
		// printf ("\n");
		// while (j <= i)
		// 	printf("%d ", (set->bigint.five_arr)[j++]);

	// }


}

void	ft_init_decimal_arr(t_set *set)
{
	int	i = 0;
	int j = 0;
	int	round = 0;

	while (i < 1074)
	{
		j = i + 1;
		if (set->bigint.binary_arr[i] == 1)
		{
			while (j >= 0)
			{
				if ((set->bigint.result_arr[j] + set->bigint.five_arr[j] + round)< 10)
				{
					set->bigint.result_arr[j] = set->bigint.result_arr[j] + set->bigint.five_arr[j] + round;
					round = 0;
				}
				else
				{
					set->bigint.result_arr[j] = (set->bigint.result_arr[j] + set->bigint.five_arr[j] + round) % 10;
					round = 1;
				}
				j--;
			}
		}
		ft_multiple_five(set, i);
		i++;
	}
	return ;
}

void	ft_init_bigint_arr(t_set *set, t_double dnumb)
{
	ft_memset(set->bigint.binary_arr, 0, 1074);

	ft_memset(set->bigint.five_arr, 0, 1074);
	(set->bigint.five_arr)[0] = 5;
	ft_memset(set->bigint.result_arr, 0, 1074);
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

	dnumb.dnum = 0.626;
	ft_init_bigint_arr(&set, dnumb);
	i = 0;
	one = 1;
	one <<= 52;
	exp = dnumb.bitfield.exponent - (int)BIAS;
	temp = dnumb.bitfield.mantissa;
	if (exp >= 0)
	{
		temp <<= exp;
		while (i < 52)
		{
			(set.bigint.binary_arr)[i] = ((temp >> (51 - i)) & 1) ? 1 : 0;
			++i;
		}
	}
	else
	{
		temp |= one;
		exp *= (-1);
		while (i < 53)
			(set.bigint.binary_arr)[exp++ - 1] = ((temp >> (52 - i++)) & 1) ? 1 : 0;
	}

	i = 0;
	while (i < 1074)
	{
		printf("%d", (set.bigint.binary_arr)[i++]);
	}
	ft_init_decimal_arr(&set);
	printf("\n");
	i = 0;
	while (i < 1074)
	{
		printf("%d", (set.bigint.result_arr)[i++]);
	}
	return 0;
}
