/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:38:18 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 14:42:07 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	countnbr(int tmp)
{
	int	count;

	count = 0;
	if (tmp <= 0)
		++count;
	while (tmp)
	{
		tmp /= 10;
		++count;
	}
	return (count);
}

static char	*putnbr(char *a, int count, int n)
{
	while (n != 0)
	{
		a[count--] = (n % 10) + '0';
		n /= 10;
	}
	return (a);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*a;

	count = countnbr(n);
	a = malloc(sizeof(char) * (count + 1));
	if (!a)
		return (0);
	if (n == 0)
		a[0] = '0';
	a[count--] = '\0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			a[count--] = '8';
			n = -214748364;
		}
		n *= -1;
		a[0] = '-';
	}
	return (putnbr(a, count, n));
}
