/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:34:33 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:18:47 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str2;

	str2 = s;
	while (n > 0)
	{
		str2[n - 1] = '\0';
		n--;
	}
}
/*#include <stdio.h>
int main()
{
    char str[50]= "abcdefhtgdjkçlgrtelçjfsdre143567  uytyjhg";
    ft_bzero(str,5);
    printf("%s",str);
    return (0);
}*/
