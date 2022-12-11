/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:44:19 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:20:31 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	words = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && i > 0 && s[i - 1] != c)
			words++;
		i++;
	}	
	return (words);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**ptrs;	

	ptrs = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!s || !ptrs)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			ptrs[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	ptrs[j] = 0;
	return (ptrs);
}
/*
#include <stdio.h>
int main(void)
{
	char *texto = "fds bbbgd grbb";
	char delimiter = 'b';
	char **array;
	int size;
	int i;
	i = 0;

	size = 2;
	array = ft_split(texto, delimiter);

	while(i < size)
	{
		printf("->%s\n", array[i++]);
	}
	printf("->%s", array[i]);

	return(0);
}*/
