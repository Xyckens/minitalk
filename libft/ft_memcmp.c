/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:30:32 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 22:42:01 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*str1_xd;
	unsigned char	*str2_xd;

	str1_xd = (unsigned char *) str1;
	str2_xd = (unsigned char *) str2;
	while (n > 0)
	{
		if (*str1_xd != *str2_xd)
			return (*str1_xd - *str2_xd);
		str1_xd++;
		str2_xd++;
		n--;
	}
	return (0);
}
/*#include <stdio.h>
int main (void)
{
printf("%d",ft_memcmp("t\200", "t\0", 2));
return (0);
}*/
