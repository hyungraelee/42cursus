
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int		ft_printf(const	char *str, ...);


void	ft_bi_integer_arr_init_arr(t_set *set)
{
	ft_memset(set->bi_int_arr.int_binary, 0, 1024);
	ft_memset(set->bi_int_arr.int_two_mul, 0, 1024);
	(set->bi_int_arr.int_two_mul)[0] = 2;
	ft_memset(set->bi_int_arr.int_result, 0, 309);
	return ;
}

void	ft_bi_integer_arr_multiple_two(t_set *set, int i)
{
	int	round;


	return ;
}

void	ft_bi_integer_arr_put_binary(t_set *set,t_double dbl)
{
	int	i;
	unsigned long	temp;

	i = 0;
	set->exp = dbl.bitfield.exponent - (int)BIAS;
	temp = dbl.bitfield.mantissa;
	if (set->exp >= 0)
	{
		set->bi_int_arr.int_binary[1024 - set->exp - 1] = 1;
		while (i < set->exp)
		{
			set->bi_int_arr.int_binary[1024 - set->exp + i] = ((temp >> (51 - i)) & 1) ? 1 : 0;
			i++;
		}
	}
	return ;
}

void	ft_bi_integer_arr(t_set *set,t_double dbl)
{
	ft_bi_integer_arr_init_arr(set);
	ft_bi_integer_arr_put_binary(set, dbl);
}


int	main()
{
	// ft_printf("%f\n", 13.625);

	t_set set;
	t_double dbl;

	dbl.dnum = 12312334.0;
	ft_bi_integer_arr(&set, dbl);

	int i = 0;
	while (i < 1024)
	{
		printf("%d", (set.bi_int_arr.int_binary)[i++]);
	}
	return 0;
}
