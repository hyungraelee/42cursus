
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int		ft_printf(const	char *str, ...);


void	ft_bi_integer_arr_init_arr(t_set *set)
{
	ft_memset(set->bi_int_arr.int_binary, 0, 1024);
	ft_memset(set->bi_int_arr.int_two_mul, 0, 308);
	set->bi_int_arr.int_two_mul[0] = 1;
	ft_memset(set->bi_int_arr.int_result, 0, 309);
	return ;
}

int		ft_bi_integer_arr_multiple_two(t_set *set, int mul_len)
{
	int	round = 0;
	int i = 0;
	int temp;

	while (i < mul_len)
	{
		temp = (set->bi_int_arr.int_two_mul[i] * 2) + round;
		if (temp >= 10)
		{
			set->bi_int_arr.int_two_mul[i] = temp % 10;
			round = temp / 10;
		}
		else
		{
			set->bi_int_arr.int_two_mul[i] = temp;
			round = 0;
		}
		i++;
	}
	if (round == 1)
	{
		set->bi_int_arr.int_two_mul[i] = 1;
		mul_len++;
	}
	return (mul_len);
}

void	ft_bi_integer_reverse_arr(t_set *set,int mul_len)
{
	char temp[309];

	ft_memmove(temp, set->bi_int_arr.int_result, 309);
	ft_memset(set->bi_int_arr.int_result, 0, 309);
	while (mul_len)
	{
		set->bi_int_arr.int_result[309 - mul_len] = temp[mul_len - 1];
		mul_len--;
	}
	return ;
}

void	ft_bi_integer_arr_put_result(t_set *set)
{
	int		i = 1024;
	int		j = 0;
	int		round = 0;
	int		mul_len = 1;

	while (i-- > (1023 - set->exp))
	{
		if (set->bi_int_arr.int_binary[i] == 1)
		{
			j = 0;
			while (j < mul_len + 1)
			{
				if ((set->bi_int_arr.int_result[j] + set->bi_int_arr.int_two_mul[j] + round) < 10)
				{
					set->bi_int_arr.int_result[j] = set->bi_int_arr.int_result[j] + set->bi_int_arr.int_two_mul[j] + round;
					round = 0;
				}
				else
				{
					set->bi_int_arr.int_result[j] = (set->bi_int_arr.int_result[j] + set->bi_int_arr.int_two_mul[j] + round) % 10;
					round = 1;
				}
				j++;
			}
		}
		mul_len = ft_bi_integer_arr_multiple_two(set, mul_len);
	}
	printf("\n");
	i = 0;
	while (i < 309)
	{
		printf("%d", (set->bi_int_arr.int_result)[i++]);
	}
	ft_bi_integer_reverse_arr(set, mul_len);
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
		while (i < 52)
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
	ft_bi_integer_arr_put_result(set);
	return ;
}


int	main()
{
	// ft_printf("%f\n", 13.625);

	t_set set;
	t_double dbl;

	dbl.dnum = __DBL_MAX__;
	ft_bi_integer_arr(&set, dbl);

	printf("\n");
	int i = 0;
	while (i < 1024)
	{
		printf("%d", (set.bi_int_arr.int_binary)[i++]);
	}
	printf("\n");
	i = 0;
	while (i < 309)
	{
		printf("%d", (set.bi_int_arr.int_result)[i++]);
	}
	printf("\n%f", __DBL_MAX__);
	return 0;
}
