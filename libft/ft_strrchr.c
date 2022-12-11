/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:53:45 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:21:24 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	while (count >= 0)
	{
		if (s[count] == c)
			return ((char *)s + count);
		count--;
	}
	return (0);
}
/*#include <stdio.h>
int main(void)
{
	printf("%s\n", ft_strrchr("bonjour",'b'));
	return (0);
}*/