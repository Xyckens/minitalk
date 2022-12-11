/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:50:28 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:21:42 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*string;
	unsigned int		i;
	unsigned int		a;

	i = start;
	a = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		string = malloc(1 * sizeof(char));
		if (string == NULL)
			return (NULL);
		string[0] = '\0';
		return (string);
	}
	string = malloc((len + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	while (i < ft_strlen(s) && len-- > 0)
		string[a++] = s[i++];
	string[a] = '\0';
	return (string);
}
/*#include <stdio.h>
int main()
{
    char *src = "01234";
	size_t size = 10;
    char* dest = ft_substr(src, 10, size);
    printf("%s\n", dest);
}*/
