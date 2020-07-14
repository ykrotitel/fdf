/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:57:08 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/14 16:12:38 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int		vertical_conditions(t_help *p, int n)
{
	p->a = p->a + p->col;
	p->startx = n;
	p->starty += p->d;
	p->ii = 0;
	p->jj++;
	return (0);
}

int		horizontal_conditions(t_help *p, int m)
{
		p->a = p->a + p->col;
		p->starty = m;
		p->startx += p->d;
		p->ii = 0;
		p->jj++;
		return (0);
}

int		first_parameters(t_help *p, int n, int m)
{
	p->ii = 0;
	p->jj = 0;
	p->startx = n;
	p->starty = m;
	p->a = 0x800000;
	return (0);
}