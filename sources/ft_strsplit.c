/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:03:21 by vabraham          #+#    #+#             */
/*   Updated: 2020/07/14 18:50:17 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rainbow.h"

static char	**help0(char **a, int j)
{
	a[j] = NULL;
	return (a);
}

static char	**help(char **a, char const *s, char c, int k)
{
	int tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		k = 0;
		tmp = i--;
		while (s[++i] != c && s[i])
			k++;
		if (k > 0)
		{
			if (!(a[j++] = ft_memalloc(sizeof(char) * (k))))
				return (NULL);
			k = 0;
			while (s[tmp] != c && s[tmp])
				a[j - 1][k++] = s[tmp++];
			a[j - 1][k] = '\0';
		}
	}
	return (help0(a, j));
}

char		**ft_strsplit(char const *s, char c)
{
	char	**a;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] == c)
		i++;
	i--;
	while (s[++i])
		if (s[i] == c && s[i - 1] != c)
			k++;
	if (s[i - 1] != c)
		k++;
	a = ft_memalloc(sizeof(char *) * (k + 1));
	if (!a)
		return (NULL);
	return (help(a, s, c, 0));
}
