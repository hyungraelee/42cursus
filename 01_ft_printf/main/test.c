/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:46:59 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/19 23:00:45 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	char	*str = "%.3e'";
	char	*str_num = "0.000000000054123";
	double	num = 0.000000000054123;

	printf("\n==========================================\n");
	printf("Result of \"%s\" for ", str); printf("\"%s\"\n", str_num);
	printf(str, num);
	printf("\n123456789012345678901234567890");
	printf("\n         1         2         3");
	printf("\n==========================================\n\n");

	return (0);
}
