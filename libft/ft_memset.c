/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:24:50 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:20:22 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str2;

	str2 = s;
	while (n > 0)
	{
		str2[n - 1] = c;
		n--;
	}
	return (str2);
}
/*#include <stdio.h>
int main()
{
    char str[20]= "fef f gdgdsad fsdd";
    char c = 'L';
    ft_memset(str,c,10);
    printf("%s",str);
    return (0);
}*/
