/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:41:43 by vabraham          #+#    #+#             */
/*   Updated: 2020/07/14 18:49:50 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rainbow.h"

void	*ft_memset(void *dest, int n, size_t size)
{
	char *str;

	str = (char *)dest;
	while (size > 0)
	{
		str[size - 1] = (char)n;
		size--;
	}
	return (dest);
}
