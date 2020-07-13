/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:42:16 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/13 19:51:06 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int		ft_takewith(char *s)
{
	int i;

	i = 0;
	while(*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
		{
			while (*s >= '0' && *s <= '9')
				s++;
			i++;
		}
		s++;
	}
	return (i);
}

int		ft_howlong(int a)
{
	int i;

	i = (a > 0 ? 0 : 1);
	while (a)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int		make_increase(t_help *p, int **mas, int key)
{
	int ii;
	int jj;

	ii = 0;
	jj = 0;
	while (ii <= p->i)
	{
		while (jj <= p->n)
		{
			mas[ii][jj] *= 2;
			jj++;
		}
		jj = 0;
		ii++;
	}
	return (0);
}

int		make_unincrease(t_help *p, int **mas, int key)
{
	int ii;
	int jj;

	ii = 0;
	jj = 0;
	while (ii <= p->i)
	{
		while (jj <= p->n)
		{
			mas[ii][jj] /= 2;
			jj++;
		}
		jj = 0;
		ii++;
	}
	return (0);
}

int		ft_error()
{
	write(1, "\n\n      SORRY, MAN :c      \n\n", 30);
	return (0);
}