/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:04:38 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:21:08 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	size_t	len_string;
	size_t	count;
	char	*array;

	len_string = ft_strlen(string);
	count = 0;
	array = (char *) malloc((len_string + 1) * sizeof(char));
	if (!array)
		return (NULL);
	while (string[count] != '\0')
	{
		array[count] = string[count];
		count++;
	}
	array[count] = '\0';
	return (array);
}
