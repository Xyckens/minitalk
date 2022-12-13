/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:57:05 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/13 13:38:58 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*ft_alt_strjoin(unsigned char *s1, unsigned char c)
{
	int				len_s1;
	int				counter;
	unsigned char	*str;

	len_s1 = ft_strlen((char *) s1);
	str = malloc((len_s1 + 2) * sizeof(char));
	counter = 0;
	while (s1[counter] != '\0')
	{
		str[counter] = s1[counter];
		counter++;
	}
	str[counter] = c;
	str[counter + 1] = '\0';
	if (s1[0] != 0)
		free(s1);
	return (str);
}