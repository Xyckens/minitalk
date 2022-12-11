/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:47:32 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:20:34 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == c)
			return ((char *)s + count);
		count++;
	}
	if (s[count] == c)
		return ((char *)s + count);
	return (0);
}
/*#include <stdio.h>
int main(void)
{
	printf("%s \n",ft_strchr("bonjour",'\0'));
	return(0);
}*/