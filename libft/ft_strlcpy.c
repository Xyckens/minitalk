/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:21:05 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:20:50 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	len_src;

	count = 0;
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	while (src[count] != '\0' && count < size - 1)
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (len_src);
}
