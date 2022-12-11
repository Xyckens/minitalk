/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:43:26 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:20:14 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				count;
	unsigned char		*dest2;
	const unsigned char	*src2;

	if (!dest && !src)
		return (NULL);
	count = 0;
	dest2 = dest;
	src2 = src;
	while (n > 0)
	{
		dest2[count] = src2[count];
		count++;
		n--;
	}
	return (dest2);
}
/*#include <stdio.h>
int main(void)
{
    char dest[15] = "era gtfh 543hf";
    char src[21] = "/|\x12\xff\x09\0\x42\042\0\42|\\";
    puts(dest);
    ft_memcpy(dest,src,8);
    puts(dest);
    return(0);
}*/
