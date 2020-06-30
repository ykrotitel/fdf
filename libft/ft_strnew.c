/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:01:33 by vabraham          #+#    #+#             */
/*   Updated: 2020/06/30 17:35:28 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rainbow.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = ft_memalloc(size + 1);
	if (!str || size + 1 <= 0)
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}
