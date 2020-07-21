/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:42:16 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/21 18:19:40 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rainbow.h"

int		ft_takewith(char *s)
{
	char	**line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = ft_split(s);
	while (line[i])
	{
		while (line[i][j] != '\0')
			j++;
		i++;
		j = 0;
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

int		make_increase(t_help *p, int **mas)
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

int		make_unincrease(t_help *p, int **mas)
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

int		ft_error(int a)
{
	write(1, "\n\n                   SORRY, MAN :c                   \n\n", 56);
	write(1, "     BUT YOU CAN USE FDF LIKE THIS: ./fdf name_map    \n\n", 58);
	if (a == 0)
		write(1, "\n                    EMPTY FILE                    \n", 52);
	else if (a == 2)
		write(1, "\n                   INVALID MAP                   \n", 51);
	else if (a == 4)
		write(1, "\n                TOO MUCH ARGUMENTS              \n", 50);
	else if (a == -1)
		write(1, "\n                 NONEXISTENT FILE               \n", 50);
	return (0);
}
