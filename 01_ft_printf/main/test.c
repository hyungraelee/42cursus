/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:46:59 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/09 17:09:44 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	char	*str = "%.50f'";
	char	*str_num = "2.234";
	double	num = 2.234;

	printf("\n==========================================\n");
	printf("result of \"%s\" for ", str); printf("\"%s\"\n", str_num);
	printf(str, num);
	printf("\n000050000100005000020000500003");
	printf("\n==========================================\n\n");

	int i = 0;
	int n = 16;
	int temp = 0;
	double half = 2;
	int nu[17] = {0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0};
	double res = 0.0;
	while (n-- >= 0)
	{
		temp = 0;
		if (nu[n--] == 1)
		{
			temp += half;

		}
		if (temp >= 10)
			res += half;
		half *= 2;
	}
	printf("%.20f\n", res);
	return (0);
}
