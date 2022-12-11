/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:57:53 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:21:01 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (0);
	while (s1[count] == s2[count] && count < n - 1 && s1[count] && s2[count])
		count++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
/*#include <stdio.h>
int	main()
{
		printf("s1 = %c s2 = %c \n", s1[count], s2[count]);
	printf("s1 = %c s2 = %c \n", s1[count], s2[count]);
	char	str1[] = "test\200";
	char	str2[] = "test\0";
	int	i;
	
	i = 0;
	printf("%s\n", str1);
	printf("%s\n", str2);
	i = ft_strncmp(str1, str2, 6);
	printf("o suposto s1 = %c s2 = %c \n", str1[6], str2[6]);
	printf("%d\n", i);
	if (i < 0)
		printf("Str1 is less than Str2");
	else if (i > 0)
		printf("Str2 is less than Str1");
	else
		printf("Str1 is equal to Str2");
	return (0);
}*/
