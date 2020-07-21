/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:22:55 by vabraham          #+#    #+#             */
/*   Updated: 2020/07/14 18:49:47 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rainbow.h"

void	*ft_memalloc(size_t size)
{
	void *str;

	if (size + 1 <= 0)
		return (NULL);
	str = malloc((size));
	if (!str)
		return (NULL);
	ft_memset(str, 0, size);
	return (str);
}
