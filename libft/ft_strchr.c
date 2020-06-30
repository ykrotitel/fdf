/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:45:24 by vabraham          #+#    #+#             */
/*   Updated: 2020/06/30 17:35:07 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rainbow.h"

char	*ft_strchr(const char *str, int ch)
{
	int i;

	i = 0;
	while (str[i])
		if (str[i++] == (char)ch)
			return ((char *)(str + (--i)));
	if ((char)ch == '\0')
		return ((char *)(str + i));
	return (NULL);
}
