/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:01:02 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 23:05:55 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	absolute_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_alga(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	if (n != 0)
		count--;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*string;

	count = ft_alga(n);
	string = (char *) malloc((count + 2) * sizeof(char));
	if (!string)
		return (NULL);
	string[count + 1] = '\0';
	if (n == 0)
		string[count] = '0';
	if (n < 0)
		string[0] = '-';
	while (n != 0)
	{
		string[count--] = absolute_value(n % 10) + '0';
		n /= 10;
	}
	return (string);
}
/*
#include <stdio.h>
int main(void)
{
    printf("%s \n",ft_itoa(-0));
    printf("%s \n",ft_itoa(9));
    printf("%s \n",ft_itoa(-9));
    printf("%s \n",ft_itoa(10));
    printf("%s \n",ft_itoa(-10));
    printf("%s \n",ft_itoa(8124));
    printf("%s \n",ft_itoa(-9874));
    printf("%s \n",ft_itoa(-543000));
    printf("%s \n",ft_itoa(-2147483648LL));
    printf("%s \n",ft_itoa(2147483647));

    return (0);
}*/
