/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:26:33 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:22:16 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	count;
	char	*joined;

	count = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined = (char *) malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	while (s1[count] != '\0')
	{
		joined[count] = s1[count];
		count++;
	}
	count = 0;
	while (s2[count] != '\0')
	{
		joined[len_s1 + count] = s2[count];
		count++;
	}
	joined[len_s1 + count] = '\0';
	return (joined);
}
/*#include <stdio.h>
int main(void)
{
	if (len_s1 == 0 && len_s2 == 0)
		return (0);
		estava na linha 24
    char s1[] = "era franci";
    char s2[] = "sco manu\0glkjhk";

    printf("%s", ft_strjoin(s1,s2));
    return (0);
}*/
