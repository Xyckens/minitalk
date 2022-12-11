/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:06:12 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:28:06 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi( char const *s, char (*f)(unsigned int, char))
{
	size_t	len_s;
	size_t	count;
	char	*sf;

	if (s == NULL || f == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	count = 0;
	sf = (char *) malloc((len_s + 1) * sizeof(char));
	if (!sf)
		return (NULL);
	while (s[count] != '\0')
	{
		sf[count] = f(count, s[count]);
		count++;
	}
	sf[count] = '\0';
	return (sf);
}
