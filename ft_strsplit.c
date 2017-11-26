/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 20:29:01 by vmuravio          #+#    #+#             */
/*   Updated: 2017/11/21 22:20:47 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}


char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s || !c)
		return (0);
	str = (char **)malloc(sizeof(char *) * (words(s, c) + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
		len = 0;
		while (s[i + len] && (s[i + len] != c))
			len++;
		str[j++] = ft_strsub(s, i, len);
		i = i + len;
		}
	}
	str[j] = 0;
	return (str);
}
