/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:03:47 by vabraham          #+#    #+#             */
/*   Updated: 2020/07/01 12:54:49 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rainbow.h"

int		ft_atoi(const char *str)
{
	int		i;
	long	ch;
	int		min;

	i = 0;
	min = 1;
	ch = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			min *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ch > ch * 10 + (str[i] - '0'))
		{
			if (min == 1)
				return (-1);
			else
				return (0);
		}
		ch = ch * 10 + (str[i++] - '0');
	}
	return ((int)ch * min);
}
